#pragma once

#include <gba_base.h>
#include <gba_video.h>

#include <array>
#include <cstring>
#include <limits>
#include <stdexcept>

namespace gba {

class Color {
   public:
    constexpr Color(u16 color) : m_v(color) {}
    constexpr Color(u8 r, u8 g, u8 b) : m_v(RGB8(r, g, b)) {}

    operator u16() const { return m_v; }

    const u16 m_v;

   public:
    static const Color RED, GREEN, BLUE, WHITE;
};

inline constexpr Color Color::RED = RGB8(0xFF, 0x00, 0x00);
inline constexpr Color Color::GREEN = RGB8(0x00, 0xFF, 0x00);
inline constexpr Color Color::BLUE = RGB8(0x00, 0x00, 0xFF);
inline constexpr Color Color::WHITE = RGB8(0xFF, 0xFF, 0xFF);

template <u8 N>
class Palette {
   public:
    explicit Palette(Color const (&colors)[N]) {
        static_assert(N <= 256, "A palette may not exceed 256 entries");
        std::memcpy(&m_colors, colors, N);
    }

    constexpr void apply() {
        auto dst = BG_PALETTE;
        for (const auto& color : m_colors) {
            *dst++ = color;
        }
    }

    std::array<u16, N> m_colors;
};
}  // namespace gba
