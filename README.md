# Disclaimer

This project is a recruitment task for company Xberry.

## Architecture

### Control unit
There is one Control unit which has list of registered and supported sensors.
The control unit exhibits API which conists of:

* _subscribe_ - The message should contain sensor ID which was previously
registered to the control unit. When they match then subscription is accomplished
and every message sent by sensor will be pushed into buffer and sent out then
to client (UI)
* _unsibscribe_ - The message disables handling of messages comming from given sensor.
When ID does not match, then warnig message abot potential risk is printed (sent to
client).

### Sensors
Each sensor should exhibit specified API - it should be enough to inherit from _Sensor_
pure virtual class and implement all needed interfaces.

### Scalability
In order to register new sensor into system _Control Unit_ will only require addition of
new _sensor id_ to its list of supported (known sensors). If it is completely new sensor
it would be necessery to add additional procedure for specifi sensor handling.

The list of known sensors should be kept in some database, e.g. xml file.

### Reliability
Sensors are run as separate processes, so when sensor crashes, whole system will operate
normally.

### Sensors
They are seperate applications run in separate processes. They do specific measurements
and send them to __control unit__ when properly subscribed.

### UI
Simulates client (not required component).

## Build

### Executable

```bash
(mkdir -p build; cd build; cmake ..; cmake --build .)
```

### UTs

```bash
(mkdir -p build; cd build; cmake -DBUILD_TESTING=ON ..; cmake --build .)
```

## Run system
1. Compile project as described in _Build_ section.
2. Run server (_Control Unit_): `./build/controlUnit/xberry_ControlUnit_exe`
3. Run sensor: `./build/sensors/xberry_tempSensor_exe`
