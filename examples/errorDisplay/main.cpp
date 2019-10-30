#include "error.hpp"

void throwError()
{
    throw Error("This is a Error!");
}

void throwWarning()
{
    throw Error("This is a Warning!", WARNING);
}

int main()
{
	con::Console::init();
    try 
    {
        throwError();
    } 
    catch (Error e)
    {
        e.sendErrorMessage();
    }

    try
    {
        throwWarning();
    }
    catch (Error e)
    {
        e.sendErrorMessage();
    }


    return 0;
}