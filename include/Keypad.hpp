#pragma once

#include <gba_base.h>
#include <gba_input.h>

namespace gba {
class Keypad final {
    using Keys = u16;
    using Key = u16;

   public:
    explicit Keypad() noexcept { rescan(); };

    bool pressed_or_held(Keys keys) const noexcept {
        return (keys & (m_pressed | m_held)) == keys;
    }

    void rescan() noexcept {
        scanKeys();
        m_pressed = keysDown();
        m_held = keysHeld();
    }

   private:
    Keys m_pressed;
    Keys m_held;
};
}  // namespace gba
