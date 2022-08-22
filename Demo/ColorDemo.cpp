#include "..\src\ansi-styles.hpp"
#include <iostream>
using namespace std;
using namespace ansi_styles;

void printHeader()
{
    Style style;
    for (int i = BRIGHT_WHITE; i >= BLACK; --i)
    {
        style.set_background_color(Color(i));
        cout << ' ';
    }
    style.reset();
    cout << "This is a Demo of TxtColor and BGColor by: Avi Aaron";
    for (int i = BLACK; i <= BRIGHT_WHITE; ++i)
    {
        style.set_background_color(Color(i));
        cout << ' ';
    }
}

void myFunc()
{
    cout << "\t//now in myFunc(), notice the color is still blue" << endl;
    cout << "\tStyle style2;// creating another Style object" << endl;
    Style style2;
    cout << "\tstyle2.set_color(YELLOW);" << endl;
    style2.set_color(YELLOW);
    cout << "\tstyle2.reset();" << endl;
    style2.reset();
    cout << "\t//notice the color is blue, not the system default" << endl;
    cout << "\t//resetting changes the style to before the creation of style2, not the begining of the program" << endl;
    cout << "\tstyle2.set_color(GREEN);" << endl;
    style2.set_color(GREEN);
    cout << "\t//returning from myFunc(), the destructor of style2 is called" << endl;
    cout << "\t//the destructor resets the style" << endl;
}

void printColorNames()
{
    Style style;
    cout << "The available colors are:" << endl;
    style.set_color(BLACK);
    cout << "BLACK ";
    style.set_color(BRIGHT_BLACK);
    cout << "BRIGHT_BLACK ";
    style.set_color(RED);
    cout << "RED     ";
    style.set_color(BRIGHT_RED);
    cout << "BRIGHT_RED" << endl;
    style.set_color(GREEN);
    cout << "GREEN ";
    style.set_color(BRIGHT_GREEN);
    cout << "BRIGHT_GREEN ";
    style.set_color(YELLOW);
    cout << "YELLOW  ";
    style.set_color(BRIGHT_YELLOW);
    cout << "BRIGHT_YELLOW" << endl;
    style.set_color(BLUE);
    cout << "BLUE  ";
    style.set_color(BRIGHT_BLUE);
    cout << "BRIGHT_BLUE  ";
    style.set_color(MAGENTA);
    cout << "MAGENTA ";
    style.set_color(BRIGHT_MAGENTA);
    cout << "BRIGHT_MAGENTA" << endl;
    style.set_color(CYAN);
    cout << "CYAN  ";
    style.set_color(BRIGHT_CYAN);
    cout << "BRIGHT_CYAN  ";
    style.set_color(WHITE);
    cout << "WHITE   ";
    style.set_color(BRIGHT_WHITE);
    cout << "BRIGHT_WHITE" << endl;
    style.set_color(DEFAULT);
    cout << "          DEFAULT = sytem default" << endl << endl;
}

void printAllCombinations()
{
    Style style;
    cout << "Here are all the combinations:" << endl << endl;
    for (int i = BLACK; i <= BRIGHT_WHITE; ++i)
    {
        style.set_background_color(Color(i));
        for (int j = BLACK; j <= BRIGHT_WHITE; ++j)
        {
            style.set_color(Color(j));
            cout << " txt ";
        }
        style.reset_background_color();
        cout << endl;
    }
}

void printMoreColors()
{
    cout << "Here are more colors" << endl;
    Style style;
    for (int i = 0; i < 8; ++i)
    {
        style.set_background_color(i);
        cout << "         ";
    }
    style.reset();
    cout << endl;
    for (int i = 8; i < 16; ++i)
    {
        style.set_background_color(i);
        cout << "         ";
    }
    style.reset();
    cout << endl;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            for (int k = 0; k < 6; ++k)
            {
                style.set_background_color(16 + 36 * j + 6 * i + k);
                cout << "  ";
            }
        }
        style.reset();
        cout << endl;
    }
    for (int i = 232; i < 256; ++i)
    {
        style.set_background_color(i);
        cout << "   ";
    }
}

int main()
{
    Style style;
    printHeader();
    cout << endl << "Style style;" << endl;
    cout << "style.set_color(RED); // recives enum Color color" << endl;
    style.set_color(RED);
    cout << "style.reset_color();" << endl;
    style.reset_color();
    cout << "style.set_color(BLUE);" << endl;
    style.set_color(BLUE);
    cout << "calling myFunc()" << endl;
    myFunc();
    cout << "//back to blue" << endl << endl;
    style.reset_color();
    printColorNames();
    cout << "style.set_background_color(<color>) is exactly the same but for background color" << endl;
    printAllCombinations();
    printMoreColors();
}