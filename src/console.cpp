#include "../include/console.hpp"
#include <iostream>

#ifdef CMAKE_WINDOWS
	#include <Windows.h>
#endif

namespace con {

ConsoleColor Console::m_CColor;

// ====================== Print char =========================
void Console::print(const char* message)
{
    print(std::string(message));
}

void Console::print(const char* message, Color col, bool isForeground)
{
    print(std::string(message), col, isForeground);
}

void Console::print(const char* message, Color foreground, Color background)
{
    print(std::string(message), foreground, background);
}

void Console::print(const char* message, ConsoleColor cColor)
{
    print(std::string(message), cColor);
}
// ===========================================================

// ====================== Print string =======================
void Console::print(const std::string& message)
{
    std::cout << m_CColor.colorString(message);
}

void Console::print(const std::string& message, Color col, bool isForeground)
{
    ConsoleColor cc;
    if (isForeground) {
        cc = ConsoleColor(col, m_CColor.getBackgroundColor());
    } else {
        cc = ConsoleColor(m_CColor.getForegroundColor(), col);
    }

    std::cout << cc.colorString(message);
}

void Console::print(const std::string& message, Color foreground, Color background)
{
    ConsoleColor cc(foreground, background);
    std::cout << cc.colorString(message);
}

void Console::print(const std::string& message, ConsoleColor cColor)
{
    std::cout << cColor.colorString(message);
}
// ===========================================================

// ====================== PrintLn char =======================
void Console::printLn(const char* message)
{
    printLn(std::string(message));
}

void Console::printLn(const char* message, Color col, bool isForeground)
{
    printLn(std::string(message), col, isForeground);
}

void Console::printLn(const char* message, Color foreground, Color background)
{
    printLn(std::string(message), foreground, background);
}

void Console::printLn(const char* message, ConsoleColor cColor)
{
    printLn(std::string(message), cColor);
}
// ===========================================================

// ====================== PrintLn string =====================
void Console::printLn(const std::string& message)
{
    std::cout << m_CColor.colorString(message) << std::endl;
}

void Console::printLn(const std::string& message, Color col, bool isForeground)
{
    ConsoleColor cc;
    if (isForeground) {
        cc = ConsoleColor(col, m_CColor.getBackgroundColor());
    } else {
        cc = ConsoleColor(m_CColor.getForegroundColor(), col);
    }

    std::cout << cc.colorString(message) << std::endl;
}

void Console::printLn(const std::string& message, Color foreground, Color background)
{
    ConsoleColor cc(foreground, background);

    std::cout << cc.colorString(message) << std::endl;
}

void Console::printLn(const std::string& message, ConsoleColor cColor)
{
    std::cout << cColor.colorString(message) << std::endl;
}
// ===========================================================

void Console::setConsoleColor(const ConsoleColor &cColor)
{
    m_CColor = cColor;
}

ConsoleColor Console::getConsoleColor()
{
    return m_CColor;
}

void Console::init()
{
    #ifdef CMAKE_WINDOWS
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) 
	{
		std::cout << "ERROR: Could not get Std Handle!" << std::endl;
		return;
	}

	DWORD dwMode = 0;
	GetConsoleMode(hConsole, &dwMode);

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hConsole, dwMode);
    #endif
}

}
