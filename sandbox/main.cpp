#include "console.hpp"

int main() {
    Console con;

    con.printLn("Test text");
    con.printLn("Test text", Color(RED));
    con.printLn("Test text", Color(RED), false);
    con.printLn("Test text", Color(YELLOW), Color(BLUE));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  false, false));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, true,  false));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, false, true));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  true,  false));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  false, true));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), true,  true,  true));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, true,  true));
    con.printLn("Test text", ConsoleColor(Color(YELLOW), Color(BLUE), false, false, false));

    return 0;
}