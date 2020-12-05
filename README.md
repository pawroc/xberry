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
