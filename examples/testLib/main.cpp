#include <console.hpp>
#include <iostream>

using namespace con;

int main() {

    // Init library
    Console::init();

    // Normal Text
    Console::printLn("Test text");

    // Foreground color
    Console::printLn("Test text", Color(RED));

    // Background color
    Console::printLn("Test text", Color(RED), false);

    // Foreground + Background color 
    Console::printLn("Test text", Color(YELLOW), Color(BLUE));

    // Bold
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  false, false));

    // Underline
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, true,  false));
    
    // Italic
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, false, true));
    
    // Bold + Underline
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  true,  false));
    
    // Bold + Italic
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  false, true));
    
    // Bold + Underline + Italic
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  true,  true));
    
    // Underline + Italic
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, true,  true));
    
    // No format, just foreground and background color
    Console::printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, false, false));

    return 0;
}