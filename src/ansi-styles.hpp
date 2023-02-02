#ifndef ANSI_STYLES_HPP
#define ANSI_STYLES_HPP

#include <iostream>
#include <string>

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

struct ColorData
{
    enum
    {
        SYSTEM,
        BIT8,
        RGB
    } type;
    union {
        Color color;
        unsigned char code;
        struct
        {
            unsigned char r, g, b;
        } rgb;
    } data;
};

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

std::string color(Color color);
std::string color(unsigned char bit8_code);
std::string color(unsigned char r, unsigned char g, unsigned char b);
std::string background(Color color);
std::string background(unsigned char bit8_code);
std::string background(unsigned char r, unsigned char g, unsigned char b);

} // namespace ansi_styles

#endif // ANSI_STYLES_HPP