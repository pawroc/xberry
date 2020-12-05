#include <sensors/tempSensor.hpp>
#include <iostream>

int main()
{
    // this should be while loop which handles
    // all sensors, not just one as here
    try
    {
        sensors::TempSensor tempSensor(1);
        tempSensor.subscribe();
    }
    catch(...)
    {
        std::cerr << "Unknown exception caught\n";
    }
}
