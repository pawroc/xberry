#pragma once

#include <cstdint>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h>
#include <utils/exceptions.hpp>
#include <messages/messages.hpp>
#include <iostream>
#include <array>

namespace sensors
{
class Sensor
{
public:
    Sensor(std::uint8_t sensorId);
    virtual ~Sensor() = default;

    virtual void sendResult() = 0;
    virtual void subscribe() = 0;
    virtual void unsubscribe() = 0;

protected:
    std::uint16_t port{8080};
    std::string controlUnitIp{"127.0.0.1"};
    sockaddr_in controlUnitAddr;
    int sockfd;
    std::uint8_t id;
};

Sensor::Sensor(std::uint8_t sensorId) : id{sensorId}
{
    controlUnitAddr.sin_family = AF_INET;
    controlUnitAddr.sin_port = htons(port);
    if (inet_pton(controlUnitAddr.sin_family, controlUnitIp.c_str(), &controlUnitAddr.sin_addr) <= 0)
    {
        throw utils::SocketFailure("IP conversion failed");
    }
    if ((sockfd = socket(controlUnitAddr.sin_family, SOCK_STREAM, 0)) < 0) 
    { 
        throw utils::SocketFailure("Socket descriptor creation failure");
    }
}

class TempSensor : public Sensor
{
public:
    explicit TempSensor(std::uint8_t sensorId) : Sensor(sensorId) {}
    ~TempSensor() { close(sockfd); }

    void sendResult() override;
    void subscribe() override;
    void unsubscribe() override;

private:

};

void TempSensor::subscribe()
{
    if (connect(sockfd, reinterpret_cast<sockaddr*>(&controlUnitAddr), sizeof(controlUnitAddr)) < 0) 
    { 
        throw utils::SocketFailure("Socket connection failure");
    }
//    std::string msg{"Subscribe sensor " + std::to_string(id)};
    
    messages::Subscribe msg{1};
    auto m = msg.encode();
    send(sockfd, m.c_str(), m.size(), 0);

    constexpr std::uint16_t bSize{1024};
    std::array<std::uint8_t, bSize> recBuf;

    read(sockfd, recBuf.data(), bSize);
    std::cout << "Sensor received: " << recBuf.data() << '\n';
}

void TempSensor::unsubscribe()
{
}

void TempSensor::sendResult()
{
}
} // namespace sensors
