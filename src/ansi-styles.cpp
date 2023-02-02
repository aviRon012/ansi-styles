#include "ansi-styles.hpp"
using std::string;
using std::to_string;
using std::get_if;
using std::uint8_t;
using std::stoi;
namespace ansi_styles
{
RGB::RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

RGB::RGB(HexColorStr hex_color_str) {
    int color = stoi(hex_color_str, 0, 16);
    r = (color >> 16) & 0xff;
    g = (color >> 8) & 0xff;
    b = color & 0xff;
}

static ColorData current_color = DEFAULT;
static ColorData current_background = DEFAULT;

static string get_color_sequence()
{
    if (auto color = get_if<Color>(&current_color)) {
        if (*color > WHITE) return string("\033[") + to_string(90 + *color - 8) + 'm';
        if (*color > DEFAULT) return string("\033[") + to_string(30 + *color) + 'm';
        return "\033[39m";
    }
    if (auto color_code = get_if<ColorCode>(&current_color)) {
        return string("\033[38;5;") + to_string(*color_code) + 'm';
    }
    if (auto rgb = get_if<RGB>(&current_color)) {
        return string("\033[38;2;") + to_string(rgb->r) + ';' + to_string(rgb->g) + ';' + to_string(rgb->b) + 'm';
    }
    return "";
}

static string get_background_sequence()
{
    if (auto color = get_if<Color>(&current_background)) {
        if (*color > WHITE) return string("\033[") + to_string(100 + *color - 8) + 'm';
        if (*color > DEFAULT) return string("\033[") + to_string(40 + *color) + 'm';
        return "\033[49m";
    }
    if (auto color_code = get_if<ColorCode>(&current_background)) {
        return string("\033[48;5;") + to_string(*color_code) + 'm';
    }
    if (auto rgb = get_if<RGB>(&current_background)) {
        return string("\033[48;2;") + to_string(rgb->r) + ';' + to_string(rgb->g) + ';' + to_string(rgb->b) + 'm';
    }
    return "";
}

ResetPoint::ResetPoint() : parant_color(current_color), parant_background(current_background)
{
}

ResetPoint::~ResetPoint()
{
    std::cout << (*this)();
}

string color(ColorData data)
{
    current_color = data;
    return get_color_sequence();
}

string color(std::uint8_t r, std::uint8_t g, std::uint8_t b)
{
    return color(RGB(r, g, b));
}

string color(HexColorStr hex_color_str)
{
    return color(RGB(hex_color_str));
}

string background(ColorData data)
{
    current_background = data;
    return get_background_sequence();
}

string background(std::uint8_t r, std::uint8_t g, std::uint8_t b)
{
    return background(RGB(r, g, b));
}

string background(HexColorStr hex_color_str)
{
    return background(RGB(hex_color_str));
}
string ResetPoint::color() const
{
    current_color = parant_color;
    return get_color_sequence();
}

string ResetPoint::background() const
{
    current_background = parant_background;
    return get_background_sequence();
}

string ResetPoint::operator()() const
{
    return this->color() + this->background();
}
} // namespace ansi_styles
