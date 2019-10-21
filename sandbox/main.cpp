#include "console.hpp"

int main() {
    Console con;

    con.print("ERROR:", ConsoleColor(Color(BLACK), Color(RED), true, true, false));
    con.printLn(" Das ist die Fehlermeldung", ConsoleColor(Color(RED), Color(NONE), true, false, false));

    return 0;
}