#include "ansi-styles.hpp"
#include <iostream>
using std::cout;

namespace ansi_styles
{
ColorData Style::current_color = {SYSTEM, DEFAULT};
ColorData Style::current_background_color = {SYSTEM, DEFAULT};

Style::Style() : parant_color(current_color), parant_background_color(current_background_color)
{
}

Style::~Style()
{
    reset();
}

const Style &Style::set_color(Color color) const
{
    current_color = {SYSTEM, color};
    int code = 39;
    if (color > WHITE)
    {
        code = 90 + color - 8;
    }
    else if (color > DEFAULT)
    {
        code = 30 + color;
    }
    cout << "\033[" << code << 'm';
    cout.flush();
    return *this;
}

const Style &Style::set_color(unsigned char bit8_code) const
{
    current_color.type = BIT8;
    current_color.data.code = bit8_code;
    cout << "\033[38;5;" << int(bit8_code) << 'm';
    cout.flush();
    return *this;
}

const Style &Style::set_color(unsigned char r, unsigned char g, unsigned char b) const
{
    current_color.type = RGB;
    current_color.data.rgb = {r, g, b};
    cout << "\033[38;2;" << int(r) << ';' << int(g) << ';' << int(b) << 'm';
    cout.flush();
    return *this;
}

const Style &Style::set_background_color(Color color) const
{
    current_color = {SYSTEM, color};
    int code = 49;
    if (color > WHITE)
    {
        code = 100 + color - 8;
    }
    else if (color > DEFAULT)
    {
        code = 40 + color;
    }
    cout << "\033[" << code << 'm';
    cout.flush();
    return *this;
}

const Style &Style::set_background_color(unsigned char bit8_code) const
{
    current_background_color.type = BIT8;
    current_background_color.data.code = bit8_code;
    cout << "\033[48;5;" << int(bit8_code) << 'm';
    cout.flush();
    return *this;
}

const Style &Style::set_background_color(unsigned char r, unsigned char g, unsigned char b) const
{
    current_background_color.type = RGB;
    current_background_color.data.rgb = {r, g, b};
    cout << "\033[48;2;" << int(r) << ';' << int(g) << ';' << int(b) << 'm';
    cout.flush();
    return *this;
}

Style &Style::reset_color()
{
    if (parant_color.type == SYSTEM)
    {
        set_color(parant_color.data.color);
    }
    else if (parant_color.type == BIT8)
    {
        set_color(parant_color.data.code);
    }
    else
    {
        set_color(parant_color.data.rgb.r, parant_color.data.rgb.g, parant_color.data.rgb.b);
    }
    return *this;
}

Style &Style::reset_background_color()
{
    if (parant_background_color.type == SYSTEM)
    {
        set_background_color(parant_background_color.data.color);
    }
    else if (parant_background_color.type == BIT8)
    {
        set_background_color(parant_background_color.data.code);
    }
    else
    {
        set_background_color(parant_background_color.data.rgb.r, parant_background_color.data.rgb.g,
                             parant_background_color.data.rgb.b);
    }
    return *this;
}

Style &Style::reset()
{
    return reset_color().reset_background_color();
}
} // namespace ansi_styles