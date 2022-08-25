#ifndef ANSI_STYLES_HPP
#define ANSI_STYLES_HPP

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

class Style
{
    static ColorData current_color;
    static ColorData current_background_color;

    const ColorData parant_color;
    const ColorData parant_background_color;

  public:
    Style();
    ~Style();
    const Style &set_color(Color color) const;
    const Style &set_color(unsigned char bit8_code) const;
    const Style &set_color(unsigned char r, unsigned char g, unsigned char b) const;
    const Style &set_background_color(Color color) const;
    const Style &set_background_color(unsigned char bit8_code) const;
    const Style &set_background_color(unsigned char r, unsigned char g, unsigned char b) const;
    Style &reset_color();
    Style &reset_background_color();
    Style &reset();
};
} // namespace ansi_styles

#endif // ANSI_STYLES_HPP