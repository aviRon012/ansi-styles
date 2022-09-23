#include "ansi-styles.hpp"
using std::string;
using std::to_string;

namespace ansi_styles
{
static ColorData current_color = {ColorData::SYSTEM, DEFAULT};
static ColorData current_background = {ColorData::SYSTEM, DEFAULT};

string get_color_sequence()
{
    switch (current_color.type)
    {
    case ColorData::SYSTEM:
        if (current_color.data.color > WHITE)
            return string("\033[") + to_string(90 + current_color.data.color - 8) + 'm';
        if (current_color.data.color > DEFAULT)
            return string("\033[") + to_string(30 + current_color.data.color) + 'm';
        return "\033[39m";
    case ColorData::BIT8:
        return string("\033[38;5;") + to_string(current_color.data.code) + 'm';
    case ColorData::RGB:
        return string("\033[38;2;") + to_string(current_color.data.rgb.r) + ';' + to_string(current_color.data.rgb.g) +
               ';' + to_string(current_color.data.rgb.b) + 'm';
    default:
        return "";
    }
}

string get_background_sequence()
{
    switch (current_background.type)
    {
    case ColorData::SYSTEM:
        if (current_background.data.color > WHITE)
            return string("\033[") + to_string(100 + current_background.data.color - 8) + 'm';
        if (current_background.data.color > DEFAULT)
            return string("\033[") + to_string(40 + current_background.data.color) + 'm';
        return "\033[49m";
    case ColorData::BIT8:
        return string("\033[48;5;") + to_string(current_background.data.code) + 'm';
    case ColorData::RGB:
        return string("\033[48;2;") + to_string(current_background.data.rgb.r) + ';' +
               to_string(current_background.data.rgb.g) + ';' + to_string(current_background.data.rgb.b) + 'm';
    default:
        return "";
    }
}

Style::Style() : parant_color(current_color), parant_background(current_background)
{
}

Style::~Style()
{
    std::cout << (*this)();
}

string color(Color color)
{
    current_color = {ColorData::SYSTEM, color};
    return get_color_sequence();
}

string color(unsigned char bit8_code)
{
    current_color.type = ColorData::BIT8;
    current_color.data.code = bit8_code;
    return get_color_sequence();
}

string color(unsigned char r, unsigned char g, unsigned char b)
{
    current_color.type = ColorData::RGB;
    current_color.data.rgb = {r, g, b};
    return get_color_sequence();
}

string background(Color color)
{
    current_background = {ColorData::SYSTEM, color};
    return get_background_sequence();
}

string background(unsigned char bit8_code)
{
    current_background.type = ColorData::BIT8;
    current_background.data.code = bit8_code;
    return get_background_sequence();
}

string background(unsigned char r, unsigned char g, unsigned char b)
{
    current_background.type = ColorData::RGB;
    current_background.data.rgb = {r, g, b};
    return get_background_sequence();
}

string Style::color() const
{
    current_color = parant_color;
    return get_color_sequence();
}

string Style::background() const
{
    current_background = parant_background;
    return get_background_sequence();
}

string Style::operator()() const
{
    return this->color() + this->background();
}
} // namespace ansi_styles
