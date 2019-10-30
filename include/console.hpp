#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "color.hpp"

/**
 * @brief Namespace of ConsoleLib
 * 
 * This is the namespace used form the ConsoleLib
 * 
 */
namespace con {

/**
 * @brief Main class used for printing colored text to the console.
 * 
 */
class Console
{
private:
    static ConsoleColor m_CColor; //!< Stores default ConsoleColor used by Console
public:
    Console() = delete;

    /**
     * @name Print without linebreak
     * 
     */
    ///@{
    // ====================== Print char =========================
    /**
     * @brief Print message to console using set ConsoleColor
     * 
     * @param message Message to print to console
     */
    static void print(const char* message);
    /**
     * @brief Print message to console setting foreground or background color
     * 
     * @param message Message to print to console
     * @param col Color used for text or background
     * @param isForeground Should the color be used for foreground
     */
    static void print(const char* message, Color col, bool isForeground=true);
    /**
     * @brief Print message to console setting foreground and background color
     * 
     * @param message Message to print to console
     * @param foreground Color used for text
     * @param background Color used for background
     */
    static void print(const char* message, Color foreground, Color background);
    /**
     * @brief Print message to console using ConsoleColor
     * 
     * @param message Message to print to console
     * @param cColor ConsoleColor used to format message
     */
    static void print(const char* message, ConsoleColor cColor);
    // ===========================================================

    // ====================== Print string =======================
    /**
     * \overload void print(const std::string& message) 
     * \see void print(const char* message)
     */
    static void print(const std::string& message);
    /**
     * \overload void print(const std::string& message, Color col, bool isForeground=true)
     * \see void print(const char* message, Color col, bool isForeground=true)
     */
    static void print(const std::string& message, Color col, bool isForeground=true);
    /**
     * \overload void print(const std::string& message, Color foreground, Color background)
     * \see void print(const char* message, Color foreground, Color background)
     */
    static void print(const std::string& message, Color foreground, Color background);
    /**
     * \overload void print(const std::string& message, ConsoleColor cColor)
     * \see void print(const char* message, Color foreground, Color background)
     */
    static void print(const std::string& message, ConsoleColor cColor);
    // ===========================================================
    ///@}

    /**
     * @name Print with linebreak
     * 
     */
    ///@{
    // ====================== PrintLn char =======================
    /**
     * @brief Print message with linebreak to console using set ConsoleColor
     * 
     * @param message Message to print to console
     */
    static void printLn(const char* message);
    /**
     * @brief Print message with linebreak to console setting foreground or background color
     * 
     * @param message Message to print to console
     * @param col Color used for text or background
     * @param isForeground Should the color be used for foreground
     */
    static void printLn(const char* message, Color col, bool isForeground=true);
    /**
     * @brief Print message with linebreak to console setting foreground and background color
     * 
     * @param message Message to print to console
     * @param foreground Color used for text
     * @param background Color used for background
     */
    static void printLn(const char* message, Color foreground, Color background);
    /**
     * @brief Print message with linebreak to console using ConsoleColor
     * 
     * @param message Message to print to console
     * @param cColor ConsoleColor used to format message
     */
    static void printLn(const char* message, ConsoleColor cColor);
    // ===========================================================

    // ====================== PrintLn string =====================
    /**
     * \overload void printLn(const std::string& message)
     * \see void printLn(const char* message)
     */
    static void printLn(const std::string& message);
    /**
     * \overload void printLn(const std::string& message, Color col, bool isForeground=true)
     * \see void printLn(const char* message, Color col, bool isForeground=true)
     */
    static void printLn(const std::string& message, Color col, bool isForeground=true);
    /**
     * \overload void printLn(const std::string& message, Color foreground, Color background)
     * \see void printLn(const char* message, Color foreground, Color background)
     */
    static void printLn(const std::string& message, Color foreground, Color background);
    /**
     * \overload void printLn(const std::string& message, ConsoleColor cColor)
     * \see void printLn(const char* message, ConsoleColor cColor)
     */
    static void printLn(const std::string& message, ConsoleColor cColor);
    // ===========================================================
    ///@}

    static void setConsoleColor(const ConsoleColor &cColor);
    static ConsoleColor getConsoleColor();

    static void init();
};

}

#endif