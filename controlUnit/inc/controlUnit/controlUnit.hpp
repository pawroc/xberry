#pragma once

#include <cstdint>
#include <boost/circular_buffer.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <utils/exceptions.hpp>
#include <messages/messages.hpp>

namespace cu
{
template<std::size_t bufSize>
class ControlUnit
{
public:
    ControlUnit();
    ~ControlUnit() { close(sockfd); }

    void run();
    void receive();
    void sendNotification();
    void handleSubscribe();
    void handleUnsubscribe();

private:
    boost::circular_buffer<int> buf;
    int sockfd;
    int sock;
    struct sockaddr_in address;
};

template<std::size_t bufSize>
ControlUnit<bufSize>::ControlUnit()
    : buf{bufSize}
{
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(8080); 
}

template<std::size_t bufSize>
void ControlUnit<bufSize>::run()
{
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        throw utils::SocketFailure("Cannot create cosket description");
    }

    socklen_t addrlen = static_cast<socklen_t>(sizeof(address));
    if (bind(sockfd, reinterpret_cast<sockaddr*>(&address), addrlen)<0) 
    { 
        throw utils::SocketFailure("Cannot bind socket");
    } 
    if (listen(sockfd, 3) < 0) 
    { 
        throw utils::SocketFailure("Listen failed");
    }
    if ((sock = accept(sockfd, reinterpret_cast<sockaddr*>(&address), &addrlen))<0) 
    { 
        throw utils::SocketFailure("Accept failure"); 
    } 
}


template<std::size_t bufSize>
void ControlUnit<bufSize>::receive()
{
    constexpr std::uint16_t bSize{1024};

    std::array<std::uint8_t, bSize> recBuf;
    read(sock, recBuf.data(), bSize);
    
    auto msgId = messages::getMsgId(recBuf.data());
    std::cout << "CU received msgId: " << msgId << '\n';

    switch(msgId)
    {
        // list of messages which could be handled
        case messages::Subscribe::msgId:
            // run handling of subscribe message
            std::cout << "Received Subscribe msg\n";
            break;
    }

    std::string resp{"CU response"};
    send(sock, resp.c_str(), resp.size(), 0);
    std::cout << "CU has sent response\n";

    // here we should add buffering of received messages
}
} // namespace cu
