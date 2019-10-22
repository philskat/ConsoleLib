#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "color.hpp"

class Console
{
private:
    ConsoleColor m_CColor;
public:
    Console(ConsoleColor cColor);
    Console(Color foreground, Color background);
    Console(ColorCode foreground, ColorCode background);
    Console();

    // ====================== Print char =========================
    void print(const char* message);
    void print(const char* message, Color col, bool isForeground=true);
    void print(const char* message, Color foreground, Color background);
    void print(const char* message, ConsoleColor cColor);
    // ===========================================================

    // ====================== Print string =======================
    void print(const std::string& message);
    void print(const std::string& message, Color col, bool isForeground=true);
    void print(const std::string& message, Color foreground, Color background);
    void print(const std::string& message, ConsoleColor cColor);
    // ===========================================================

    // ====================== PrintLn char =======================
    void printLn(const char* message);
    void printLn(const char* message, Color col, bool isForeground=true);
    void printLn(const char* message, Color foreground, Color background);
    void printLn(const char* message, ConsoleColor cColor);
    // ===========================================================

    // ====================== PrintLn string =====================
    void printLn(const std::string& message);
    void printLn(const std::string& message, Color col, bool isForeground=true);
    void printLn(const std::string& message, Color foreground, Color background);
    void printLn(const std::string& message, ConsoleColor cColor);
    // ===========================================================
private:
#ifdef CMAKE_WINDOWS
    void init();
#endif
};

#endif