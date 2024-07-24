#pragma once

class Color
{
public:
    Color() = default;
    explicit Color(unsigned long rep) : m_rep(rep) { }

    static bool fromString(Color&, char const*);

private: 
    unsigned long m_rep { 0 };
};
