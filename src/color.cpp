#include "../include/color.hpp"

namespace con {

Color::Color(int r, int g, int b)
{
    m_R = r;
    m_G = g;
    m_B = b;
}

Color::Color(ColorCode color)
{
    getRGBFromColorCode(color, m_R, m_G, m_B);
}

std::string Color::getColorCodeString() const
{
    std::string result = "";
    if (m_R != -1) {
        result = std::to_string(m_R) + ";" + std::to_string(m_G) + ";" + std::to_string(m_B);
    }
    return result;
}

int Color::getRed() const
{
    return m_R;
}

int Color::getGreen() const
{
    return m_G;
}

int Color::getBlue() const
{
    return m_B;
}

void Color::getRGBFromColorCode(ColorCode col, int& r, int& g, int& b)
{
    switch (col)
    {
    case BLACK:
        r = 0; g = 0; b = 0;
        break;
    case WHITE:
        r = 255; g = 255; b = 255;
        break;
    case RED:
        r = 255; g = 0; b = 0;
        break;
    case GREEN:
        r = 0; g = 255; b = 0;
        break;
    case BLUE:
        r = 0; g = 0; b = 255;
        break;
    case YELLOW:
        r = 255; g = 255; b = 0;
        break;
    case MAGENTA:
        r = 255; g = 0; b = 255;
        break;
    case CYAN:
        r = 0; g = 255; b = 255;
        break;
    case NONE:
        r = -1; g = -1; b = -1;
    }
}

bool Color::operator==(const Color& other) const
{
    return m_R == other.m_R && m_G == other.m_G && m_B == other.m_B;
}

bool Color::operator!=(const Color& other) const
{
    return !(*this == other);
}

ConsoleColor::ConsoleColor(Color foreground, Color background)
    : m_Foreground(foreground), m_Background(background)
{
    m_IsBold = false;
    m_IsUnderline = false;
    m_IsItalic = false;
}

ConsoleColor::ConsoleColor(bool isBold, bool isUnderline, bool isItalic)
    : m_Foreground(NONE), m_Background(NONE)
{
    m_IsBold = isBold;
    m_IsUnderline = isUnderline;
    m_IsItalic = isItalic;
}

ConsoleColor::ConsoleColor(Color foreground, Color background, bool isBold, bool isUnderline, bool isItalic)
    : m_Foreground(foreground), m_Background(background)
{
    m_IsBold = isBold;
    m_IsUnderline = isUnderline;
    m_IsItalic = isItalic;
}

ConsoleColor::ConsoleColor()
    : m_Foreground(NONE), m_Background(NONE)
{
    m_IsBold = false;
    m_IsUnderline = false;
    m_IsItalic = false;
}

std::string ConsoleColor::colorString(const std::string& msg) const
{
    std::string result;

    if (m_Foreground.getRed() != -1) 
    {
        result = "\033[38;2;" + m_Foreground.getColorCodeString();
    } 
    else
    {
        result = "\033[";
    }

    if (m_Background.getRed() != -1) 
    {
        result += ";48;2;" + m_Background.getColorCodeString();
    }

    if (m_IsBold) 
    {
        result += ";1";
    }
    if (m_IsUnderline)
    {
        result += ";4";
    }
    if (m_IsItalic)
    {
        result += ";3";
    }
    
    result += "m";

    result += msg;

    result += "\033[0m";

    return result;
}

void ConsoleColor::setForegroundColor(const Color& color)
{
    m_Foreground = color;
}

Color ConsoleColor::getForegroundColor() const
{
    return m_Foreground;
}

void ConsoleColor::setBackgroundColor(const Color& color)
{
    m_Background = color;
}

Color ConsoleColor::getBackgroundColor() const
{
    return m_Background;
}

void ConsoleColor::setBold(bool isBold)
{
    m_IsBold = isBold;
}

bool ConsoleColor::isBold() const
{
    return m_IsBold;
}

void ConsoleColor::setUnderline(bool isUnderline)
{
    m_IsUnderline = isUnderline;
}

bool ConsoleColor::isUnderline() const
{
    return m_IsUnderline;
}

void ConsoleColor::setItalic(bool isItalic)
{
    m_IsItalic = isItalic;
}

bool ConsoleColor::isItalic() const
{
    return m_IsItalic;
}

}