#include <console.hpp>
#include <iostream>

using namespace con;

int main() {
    Console con;

    // Normal Text
    con.printLn("Test text");

    // Foreground color
    con.printLn("Test text", Color(RED));

    // Background color
    con.printLn("Test text", Color(RED), false);

    // Foreground + Background color 
    con.printLn("Test text", Color(YELLOW), Color(BLUE));

    // Bold
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  false, false));

    // Underline
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, true,  false));
    
    // Italic
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, false, true));
    
    // Bold + Underline
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  true,  false));
    
    // Bold + Italic
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  false, true));
    
    // Bold + Underline + Italic
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  true,  true));
    
    // Underline + Italic
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, true,  true));
    
    // No format, just foreground and background color
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, false, false));

    return 0;
}