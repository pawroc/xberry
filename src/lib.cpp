#include <lib.hpp>

namespace lib
{
void SyncQueue::push(int element)
{
    std::lock_guard<std::mutex> lg(mtx);
    queue.push_back(element);
}

const int& SyncQueue::front() const
{
    return queue.front();
}

const int& SyncQueue::back() const
{
    return queue.back();
}
} // namespace lib
