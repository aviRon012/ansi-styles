#include "../src/ansi-styles.hpp"
#include <iostream>
using namespace std;
using namespace ansi_styles;

void printHeader()
{
    Style style;
    for (int i = BRIGHT_WHITE; i >= BLACK; --i)
    {
        cout << background(Color(i)) << ' ';
    }
    cout << style.background();
    cout << "This is a Demo of TxtColor and BGColor by: Avi Aaron";
    for (int i = BLACK; i <= BRIGHT_WHITE; ++i)
    {
        cout << background(Color(i)) << ' ';
    }
}

void myFunc()
{
    cout << "\t//now in myFunc(), notice the color is still blue" << endl;
    cout << "\tStyle style2;// creating another Style object" << endl;
    Style style2;
    cout << "\tstyle2.set_color(YELLOW);" << endl;
    cout << color(YELLOW) << "\tstyle2.reset();" << style2.color() << endl;
    cout << "\t//notice the color is blue, not the system default" << endl;
    cout << "\t//resetting changes the style to before the creation of style2, not the begining of the program" << endl;
    cout << "\tstyle2.set_color(GREEN);" << endl;
    cout << color(GREEN) << "\t//returning from myFunc(), the destructor of style2 is called" << endl;
    cout << "\t//the destructor resets the style" << endl;
}

void printColorNames()
{
    Style style;
    cout << "The available colors are:" << endl
         << color(BLACK) << "BLACK " << color(BRIGHT_BLACK) << "BRIGHT_BLACK " << color(RED)
         << "RED     " << color(BRIGHT_RED) << "BRIGHT_RED" << endl
         << color(GREEN) << "GREEN " << color(BRIGHT_GREEN) << "BRIGHT_GREEN " << color(YELLOW)
         << "YELLOW  " << color(BRIGHT_YELLOW) << "BRIGHT_YELLOW" << endl
         << color(BLUE) << "BLUE  " << color(BRIGHT_BLUE) << "BRIGHT_BLUE  " << color(MAGENTA)
         << "MAGENTA " << color(BRIGHT_MAGENTA) << "BRIGHT_MAGENTA" << endl
         << color(CYAN) << "CYAN  " << color(BRIGHT_CYAN) << "BRIGHT_CYAN  " << color(WHITE)
         << "WHITE   " << color(BRIGHT_WHITE) << "BRIGHT_WHITE" << endl
         << color(DEFAULT) << "          DEFAULT = sytem default" << endl
         << endl;
}

void printAllCombinations()
{
    Style style;
    cout << "Here are all the combinations:" << endl << endl;
    for (int i = BLACK; i <= BRIGHT_WHITE; ++i)
    {
        cout << background(Color(i));
        for (int j = BLACK; j <= BRIGHT_WHITE; ++j)
            cout << color(Color(j)) << " txt ";
        cout << style.background() << endl;
    }
}

void printMoreColors()
{
    cout << "Here are more colors" << endl;
    Style style;
    for (int i = 0; i < 8; ++i)
        cout << background(i) << "         ";
    cout << style.background() << endl;
    for (int i = 8; i < 16; ++i)
        cout << background(i) << "         ";
    cout << style.background() << endl;
    for (int i = 0; i < 36; i += 6)
    {
        for (int j = 16; j < 232; j += 36)
            for (int k = 0; k < 6; ++k)
                cout << background(j + i + k) << "  ";
        cout << style.background() << endl;
    }
    for (int i = 232; i < 256; ++i)
        cout << background(i) << "   ";
    cout << style.background() << endl;
}

int main()
{
    Style style;
    printHeader();
    cout << endl << "Style style;" << endl;
    cout << "style.set_color(RED); // recives enum Color color" << endl;
    cout << color(RED) << "style.reset_color();" << endl;
    cout << style.color() << "style.set_color(BLUE);" << endl;
    cout << color(BLUE) << "calling myFunc()" << endl;
    myFunc();
    cout << "//back to blue" << endl << endl;
    cout << style.color();
    printColorNames();
    cout << "style.set_background_color(<color>) is exactly the same but for background color" << endl;
    printAllCombinations();
    printMoreColors();
}
