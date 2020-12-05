#pragma once
#include <cstdint>
#include <string>

namespace sensors::messages
{
constexpr std::uint8_t invalidMsgId{0xFF};

std::uint8_t getMsgId(const char* payload)
{
    if (payload)
    {
        return *reinterpret_cast<const std::uint8_t*>(payload);
    }
    std::cerr << "Payload is nullptr\n";
    return invalidMsgId;
}

struct Msg
{
    virtual ~Msg() = default;

    virtual std::string encode() = 0;

    std::uint8_t msgId{0};
};

struct Subscribe : public Msg
{
    std::string encode() override
    {
        return {std::to_string(msgId) + std::to_string(sensorId)};
    }

    std::uint8_t sensorId{0};
};
} // namespace sensors::messages
