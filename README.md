# Ansi Styles

## What

Ansi styles is a c++ utility for ansi escape sequences,
ansi escape sequences are used to control appearance of text in terminal emulators that support it, it can control the clolor of the text and the background color.

## How to use it

1. include `ansi-styles.hpp`,
2. use the namespace `ansi_styles`,
3. create an object of type `Style`,
4. set the property you want with one of the builtin methods.

here is an example:
```cpp
#include "ansi-styles.hpp"
#include <iostream>
using mamespace ansi_styles;

int main()
{
    Style style;
    style.set_color(RED);
    std::cout << "This text is red" << std::endl;
}
```

## Features

### Auto resetting

- the constructor of the object memorizes the style at that moment,
- when the object goes out of scope the destructor resets the style to the time of the creation.

here is an example:
```c++
int main()
{
    Style style1;
    style1.set_color(RED);
    std::cout << "This text is red" << std::endl;
    {
        Style style2;
        style2.set_color(BLUE);
        std::cout << "This text is blue" << std::endl;
    }
    std::cout << "Back to red again" << std::endl;
}
```

### Chaining

- methods retun a reference to the object so methods can be chaind.

like this:
```c++
style.set_color(RED).set_backgroun_color(BLUE);
```

## Available methods

- there are 3 variants of `set_color()`
  - `set_color(Color color)` that receives `enum Color`,
  - `set_color(unsigned char bit8_code`) that receives a number between 0 - 255,
  - `set_color(unsigned chat r, unsigned char g, unsigned char b)` that receives an RGB values.
- a method `reset_color()` resets the color to time of creation of the object.
- there are 3 variants of `set_background_color()` same as the above but for the background,
- a method `reset_backgroun_color()`,
- a method `reset()` that resets both.

## The type `enum Color`

Theses are the builtin colors:
- `DEFAULT` the system default,
- `BLACK`,
- `RED`,
- `GREEN`,
- `YELLOW`,
- `BLUE`,
- `MAGENTA`,
- `CYAN`,
- `WHITE`,
- `BRIGHT_BLACK`,
- `BRIGHT_RED`,
- `BRIGHT_GREEN`,
- `BRIGHT_YELLOW`,
- `BRIGHT_BLUE`,
- `BRIGHT_MAGENTA`,
- `BRIGHT_CYAN`,
- `BRIGHT_WHITE`.