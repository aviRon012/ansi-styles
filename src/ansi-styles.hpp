#ifndef ANSI_STYLES_HPP
#define ANSI_STYLES_HPP

#include <iostream>
#include <string>
#include <variant>
#include <cstdint>
namespace ansi_styles
{

enum Color
{
    DEFAULT = -1,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    BRIGHT_BLACK,
    BRIGHT_RED,
    BRIGHT_GREEN,
    BRIGHT_YELLOW,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_CYAN,
    BRIGHT_WHITE
};

using HexColorStr = char[7];
struct RGB {
    std::uint8_t r, g, b;
    RGB(std::uint8_t r, std::uint8_t g, std::uint8_t b);
    RGB(HexColorStr);
};
using ColorCode = std::uint8_t;
using ColorData = std::variant<Color, ColorCode, RGB>;

class ResetPoint
{
    const ColorData parant_color;
    const ColorData parant_background;

  public:
    ResetPoint();
    ~ResetPoint();

    std::string color() const;
    std::string background() const;
    std::string operator()() const;
};

std::string color(ColorData data);
std::string color(std::uint8_t r, std::uint8_t g, std::uint8_t b);
std::string color(HexColorStr hex_color_str);
std::string background(ColorData data);
std::string background(std::uint8_t r, std::uint8_t g, std::uint8_t b);
std::string background(HexColorStr hex_color_str);

} // namespace ansi_styles

#endif // ANSI_STYLES_HPP