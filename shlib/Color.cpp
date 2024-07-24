#include "Color.h"

#include <swift/bridging>
#include <shlib-Swift.h>

bool Color::fromString(Color& color, char const* str)
{
    if (auto c = SwiftShlib::colorFromString(str)) {
        color = c.get();
        return true;
    }
    return false;
}
