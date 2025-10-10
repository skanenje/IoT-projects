#include "Blink.h"

Blink::Blink(WriteFn writeFunc, uint32_t onMs, uint32_t offMs)
: _write(writeFunc), _onMs(onMs), _offMs(offMs), _lastToggle(0), _isOn(false)
{
    if (_write) _write(_isOn);
}

void Blink::update(uint32_t nowMillis) {
    uint32_t interval = _isOn ? _onMs : _offMs;
    if ((nowMillis - _lastToggle) >= interval) {
        _isOn = !_isOn;
        _lastToggle = nowMillis;
        if (_write) _write(_isOn);
    }
}

bool Blink::state() const { return _isOn; }
