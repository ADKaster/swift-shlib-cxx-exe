#include "Color.h"
#include <stdio.h>

int main()
{
    Color c;
    if (Color::fromString(c, "red"))
      puts("color is red");
    return 0;
}
