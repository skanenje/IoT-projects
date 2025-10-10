#pragma once
#include <functional>
#include <cstdint>

class Blink {
public:
    using WriteFn = std::function<void(bool)>;

    Blink(WriteFn writeFunc, uint32_t onMs = 500, uint32_t offMs = 500);
    void update(uint32_t nowMillis);
    bool state() const;

private:
    WriteFn _write;
    uint32_t _onMs;
    uint32_t _offMs;
    uint32_t _lastToggle;
    bool _isOn;
};
