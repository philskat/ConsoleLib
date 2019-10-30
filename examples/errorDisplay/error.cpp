#include "error.hpp"

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
        con::Console::print("ERROR:", m_ErrorPrefixConsoleColor);
        con::Console::printLn(" " + m_Message, m_ErrroConsoleColor);
        break;
    
    case WARNING:
        con::Console::print("WARNING:", m_WarningPrefixConsoleColor);
        con::Console::printLn(" " + m_Message, m_WarningConsoleColor);
        break;
    }
}

ErrorType Error::getErrorType() const
{
    return m_Type;
}