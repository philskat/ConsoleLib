#include "error.hpp"

con::Console Error::m_Console;
con::ConsoleColor Error::m_ErrroConsoleColor(con::Color(con::RED), con::Color(con::NONE), true, false, false);
con::ConsoleColor Error::m_ErrorPrefixConsoleColor(con::Color(con::BLACK), con::Color(con::RED), true, false, false);

con::ConsoleColor Error::m_WarningConsoleColor(con::Color(255, 165, 0), con::Color(con::NONE), true, false, false);
con::ConsoleColor Error::m_WarningPrefixConsoleColor(con::Color(con::BLACK), con::Color(255, 165, 0), true, false, false);

Error::Error(const std::string &message, ErrorType type)
{
    m_Message = message;
    m_Type = type;
}

void Error::sendErrorMessage() const
{
    switch (m_Type)
    {
    case ERROR:
        m_Console.print("ERROR:", m_ErrorPrefixConsoleColor);
        m_Console.printLn(" " + m_Message, m_ErrroConsoleColor);
        break;
    
    case WARNING:
        m_Console.print("WARNING:", m_WarningPrefixConsoleColor);
        m_Console.printLn(" " + m_Message, m_WarningConsoleColor);
        break;
    }
}

ErrorType Error::getErrorType() const
{
    return m_Type;
}