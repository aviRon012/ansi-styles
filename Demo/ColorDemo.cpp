#include "../src/ansi-styles.hpp"
#include <iostream>
using namespace std;
using namespace ansi_styles;

void printHeader()
{
    ResetPoint reset2;
    for (int i = BRIGHT_WHITE; i >= BLACK; --i)
    {
        cout << background(Color(i)) << ' ';
    }
    cout << reset2.background();
    cout << "This is a Demo of TxtColor and BGColor by: Avi Aaron";
    for (int i = BLACK; i <= BRIGHT_WHITE; ++i)
    {
        cout << background(Color(i)) << ' ';
    }
}

void myFunc()
{
    cout << "\t//now in myFunc(), notice the color is still blue" << endl;
    cout << "\tResetPoint reset3;// creating another ResetPoint object" << endl;
    ResetPoint reset3;
    cout << "\tcout << color(YELLOW);" << endl;
    cout << color(YELLOW) << "\treset3.color();" << reset3.color() << endl;
    cout << "\t//notice the color is blue, rather than the system default" << endl;
    cout << "\t//resetting, resets the style to the time of the createion of the ResetPoint, rather than the begining "
            "of the program"
         << endl;
    cout << "\tcout << color(GREEN);" << endl;
    cout << color(GREEN) << "\t//returning from myFunc(), the destructor of style2 is called" << endl;
    cout << "\t//the destructor resets the style" << endl;
}

void printColorNames()
{
    ResetPoint reset4;
    cout << "The available colors are:" << endl
         << color(BLACK) << "BLACK " << color(BRIGHT_BLACK) << "BRIGHT_BLACK " << color(RED) << "RED     "
         << color(BRIGHT_RED) << "BRIGHT_RED" << endl
         << color(GREEN) << "GREEN " << color(BRIGHT_GREEN) << "BRIGHT_GREEN " << color(YELLOW) << "YELLOW  "
         << color(BRIGHT_YELLOW) << "BRIGHT_YELLOW" << endl
         << color(BLUE) << "BLUE  " << color(BRIGHT_BLUE) << "BRIGHT_BLUE  " << color(MAGENTA) << "MAGENTA "
         << color(BRIGHT_MAGENTA) << "BRIGHT_MAGENTA" << endl
         << color(CYAN) << "CYAN  " << color(BRIGHT_CYAN) << "BRIGHT_CYAN  " << color(WHITE) << "WHITE   "
         << color(BRIGHT_WHITE) << "BRIGHT_WHITE" << endl
         << color(DEFAULT) << "          DEFAULT = sytem default" << endl
         << endl;
}

void printAllCombinations()
{
    ResetPoint reset5;
    cout << "background(<color>) is exactly the same but for background color" << endl;
    cout << "Here are all the combinations:" << endl << endl;
    for (int i = BLACK; i <= BRIGHT_WHITE; ++i)
    {
        cout << background(Color(i));
        for (int j = BLACK; j <= BRIGHT_WHITE; ++j)
            cout << color(Color(j)) << " txt ";
        cout << reset5.background() << endl;
    }
}

void printMoreColors()
{
    cout << "Here are more colors" << endl;
    ResetPoint reset6;
    for (int i = 0; i < 8; ++i)
        cout << background(ColorCode(i)) << "         ";
    cout << reset6.background() << endl;
    for (int i = 8; i < 16; ++i)
        cout << background(ColorCode(i)) << "         ";
    cout << reset6.background() << endl;
    for (int i = 0; i < 36; i += 6)
    {
        for (int j = 16; j < 232; j += 36)
            for (int k = 0; k < 6; ++k)
                cout << background(ColorCode(j + i + k)) << "  ";
        cout << reset6.background() << endl;
    }
    for (int i = 232; i < 256; ++i)
        cout << background(ColorCode(i)) << "   ";
    cout << reset6.background() << endl;
}

void printRGBColors()
{
    cout << "here are even more colors" << endl;
    ResetPoint reset7;
    for (int b1 = 0; b1 < 256; b1 += 17*4) {
        for (int g = 0; g < 256; g += 17) {
            for(int b2 = 0; b2 < 17*4; b2 += 17)
                for (int r = 0; r < 256; r += 17) {
                    cout << background(r, g, b1 + b2) << ' ';
                }
            cout << reset7.background() << endl;
        }
    }
}

int main()
{
    ResetPoint reset1;
    printHeader();
    cout << endl << "ResetPoint reset1;" << endl;
    cout << "cout << color(RED); // recives enum Color color" << endl;
    cout << color(RED) << "cout << reset1.color();" << endl;
    cout << reset1.color() << "cout << color(BLUE);" << endl;
    cout << color(BLUE) << "calling myFunc()" << endl;
    myFunc();
    cout << "//back to blue" << endl << endl;
    cout << reset1.color();
    printColorNames();
    printAllCombinations();
    printMoreColors();
    printRGBColors();
    HexColorStr hex_color = "FfAa55";
    cout << color(hex_color) << hex_color << endl;
}
