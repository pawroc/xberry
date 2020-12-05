#pragma once

#include <exception>

namespace utils
{
struct SocketFailure : public std::exception
{
    explicit SocketFailure(const char* msg) : _msg{msg} {}

    const char* what() const noexcept override
    {
        return _msg;
    }

    const char* _msg;
};
} // namespace utils
