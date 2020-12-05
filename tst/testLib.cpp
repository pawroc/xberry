#include <array>
#include <gtest/gtest.h>
#include <gmock/gmock.h> // for Return and more
#include <lib.hpp>

namespace
{
using namespace ::testing;

class TestSyncQueue : public Test
{
protected:
    lib::SyncQueue sut;
};

TEST_F(TestSyncQueue, push__should_block_resource_and_add_new_element)
{
    int newElement = 10;

    sut.push(newElement);

    EXPECT_EQ(sut.front(), newElement);
}

TEST_F(TestSyncQueue, front__should_return_view_of_the_oldest_element)
{
    std::array<int, 2> newElements{10, 20};

    sut.push(newElements[0]);
    sut.push(newElements[1]);

    EXPECT_EQ(sut.front(), newElements[0]);
}

TEST_F(TestSyncQueue, back__should_return_view_of_the_yangest_element)
{
    std::array<int, 2> newElements{10, 20};

    sut.push(newElements[0]);
    sut.push(newElements[1]);

    EXPECT_EQ(sut.back(), newElements[1]);
}

TEST_F(TestSyncQueue, pop_front__should_block_resource_and_pop_the_oldest_element)
{
}

TEST_F(TestSyncQueue, pop_back__should_block_resource_and_pop_the_yangest_element)
{
}

TEST_F(TestSyncQueue, clear__should_block_resource_and_remove_all_elements)
{
}
} // anonymous namespace
