#include <controlUnit/controlUnit.hpp>
#include <utils/exceptions.hpp>
#include <iostream>

int main()
{
    cu::ControlUnit<10> controlUnit;

    try
    {
        controlUnit.run();

        // this should be in while loop in order
        // to operate continuously
        controlUnit.receive();
    }
    catch(const utils::SocketFailure& e)
    {
        std::cerr << "SocketFailure: " << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown exception\n";
    }
    return 0;
}
