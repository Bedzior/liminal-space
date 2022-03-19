#include "Intellisense.h"

#include "Keypad.hpp"
#include "Palette.hpp"

#include <gba_base.h>
#include <gba_video.h>

void fill(u16 c) {
    for (unsigned row = 0; row < SCREEN_HEIGHT; ++row) {
        for (unsigned col = 0; col < SCREEN_WIDTH; ++col) {
            MODE3_FB[row][col] = c;
        }
    }
}
namespace colors {}  // namespace colors

int main() {
    using namespace gba;
    SetMode(BG2_ON | MODE_3);

    while (1) {
        Keypad k;

        if (k.pressed_or_held(KEY_A | KEY_B)) {
            fill(Color::RED);
        } else if (k.pressed_or_held(KEY_A)) {
            fill(Color::GREEN);
        } else if (k.pressed_or_held(KEY_B)) {
            fill(Color::BLUE);
        } else {
            fill(Color::WHITE);
        }
    }
    return 0;
}
