#pragma once

#include <cstdint>
#include <string>
#include <iostream>

namespace messages
{
constexpr std::uint8_t invalidMsgId{0xFF};

std::uint8_t getMsgId(unsigned char* payload)
{
    if (payload)
    {
        return *reinterpret_cast<std::uint8_t*>(payload);
    }
    std::cerr << "Payload is nullptr\n";
    return invalidMsgId;
}

struct Msg
{
    virtual ~Msg() = default;

    virtual std::string encode() noexcept = 0;
};

struct Subscribe : public Msg
{
    explicit Subscribe(std::uint8_t sensorId) : _sensorId{sensorId} {}

    std::string encode() noexcept override
    {
        return {std::to_string(msgId) + std::to_string(_sensorId)};
    }

    std::uint8_t _sensorId;

    static constexpr std::uint8_t msgId{1};
};
} // namespace sensors::messages
