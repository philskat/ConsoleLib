#ifndef ERROR_HPP
#define ERROR_HPP

#include <console.hpp>

enum ErrorType
{
    ERROR,
    WARNING
};

class Error
{
private:
    static con::Console m_Console;
    static con::ConsoleColor m_ErrroConsoleColor, m_ErrorPrefixConsoleColor;
    static con::ConsoleColor m_WarningConsoleColor, m_WarningPrefixConsoleColor;
    std::string m_Message;
    ErrorType m_Type;
public:
    Error(const std::string &message, ErrorType type=ERROR);

    void sendErrorMessage() const;
    ErrorType getErrorType() const;
};

#endif