# led-blink

PlatformIO example project that blinks the onboard LED.

Environments:
- dfrobot_beetle_esp32c3 (existing)
- uno (Arduino Uno)
- esp32dev (ESP32 Dev)
- native (for running unit tests locally)

Build:

    pio run -e dfrobot_beetle_esp32c3

Upload:

    pio run -e dfrobot_beetle_esp32c3 -t upload

Run unit tests:

    pio test -e native
