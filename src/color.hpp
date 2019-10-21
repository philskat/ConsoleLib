#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

/*#define BLACK   0
#define WHITE   1
#define RED     2
#define GREEN   3
#define BLUE    4
#define YELLOW  5  
#define MAGENTA 6
#define CYAN    7*/

enum ColorCode
{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,  
    MAGENTA,
    CYAN,
    NONE
};

class Color
{
private:
    int m_R, m_G, m_B;

public:
    Color(int r, int g, int b);
    Color(ColorCode color);

    std::string getColorCodeString() const;

    int getRed() const;
    int getGreen() const;
    int getBlue() const;
private:
    void getRGBFromColorCode(ColorCode col, int& r, int& g, int& b);
};

class ConsoleColor
{
private:
    Color m_Foreground, m_Background;
    bool m_IsBold, m_IsUnderline, m_IsItalic;

public:
    ConsoleColor(Color foreground, Color background);
    ConsoleColor(bool isBold, bool isUnderline, bool isItalic);
    ConsoleColor(Color foreground, Color background, bool isBold, bool isUnderline, bool isItalic);
    ConsoleColor();

    std::string colorString(const std::string& msg);
    Color getForegroundColor() const;
    Color getBackgroundColor() const;

    void setBold(bool isBold);
    bool isBold() const;

    void setUnderline(bool isUnderline);
    bool isUnderline() const;

    void setItalic(bool isItalic);
    bool isItalic() const;
};

#endif