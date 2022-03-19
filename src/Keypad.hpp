#pragma once

#include <gba_base.h>
#include <gba_input.h>

namespace gba {
class Keypad final {
    using Keys = u16;
    using Key = u16;

   public:
    explicit Keypad() {
        scanKeys();
        m_pressed = keysDown();
        m_held = keysHeld();
    };
    bool pressed_or_held(Keys keys) const {
        return (keys & (m_pressed | m_held)) == keys;
    }

   private:
    Keys m_pressed;
    Keys m_held;
};
}  // namespace gba
