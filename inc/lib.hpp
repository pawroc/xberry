#pragma once

#include <mutex>
#include <vector>

namespace lib
{
class SyncQueue
{
public:
    void push(int);
    const int& front() const;
    const int& back() const;

private:
    std::mutex mtx;
    std::vector<int> queue;
};
} // namespace lib
