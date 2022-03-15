#include "Intellisense.h"

#include "Palette.hpp"

#include <gba_base.h>
#include <gba_input.h>
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

    int t = 0;
    u16 keys_pressed, keys_held;
    while (1) {
        scanKeys();
        keys_pressed = keysDown();
        keys_held = keysHeld();

        if (((keys_pressed | keys_held) & (KEY_A | KEY_B)) == (KEY_A | KEY_B)) {
            fill(Color::RED);
        } else if ((keys_pressed | keys_held) & KEY_A) {
            fill(Color::GREEN);
        } else if ((keys_pressed | keys_held) & KEY_B) {
            fill(Color::BLUE);
        } else {
            fill(Color::WHITE);
        }
        ++t;
    }
    return 0;
}
