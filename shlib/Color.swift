
import shlib

public func colorFromString(_ str: String) -> shlib.Color?
{
    if (str == "red") {
        return Color(1234)
    }
    return nil
}
