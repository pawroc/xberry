#include <module/module.hpp>
#include <gmock/gmock.h>
#include <iostream>

class MySecondModuleMock
{
public:
    MOCK_METHOD(int, foo, (int));
    MOCK_METHOD(void, boo, (), (const));
};
