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
    ConsoleColor m_CColor; //!< Stores default ConsoleColor used by Console
public:
    /**
     * @brief Construct a new Console object
     * 
     * @param cColor ConsoleColor used for the object
     */
    Console(ConsoleColor cColor);
    /**
     * @brief Construct a new Console object
     * 
     * @param foreground Color object used for the text
     * @param background Color object used for the background
     */
    Console(Color foreground, Color background);
    /**
     * @brief Construct a new Console object
     * 
     * @param foreground ColorCode used for the text
     * @param background ColorCode used for the background
     */
    Console(ColorCode foreground, ColorCode background);
    /**
     * @brief Construct a new Console object
     * 
     */
    Console();

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
    void print(const char* message) const;
    /**
     * @brief Print message to console setting foreground or background color
     * 
     * @param message Message to print to console
     * @param col Color used for text or background
     * @param isForeground Should the color be used for foreground
     */
    void print(const char* message, Color col, bool isForeground=true) const;
    /**
     * @brief Print message to console setting foreground and background color
     * 
     * @param message Message to print to console
     * @param foreground Color used for text
     * @param background Color used for background
     */
    void print(const char* message, Color foreground, Color background) const;
    /**
     * @brief Print message to console using ConsoleColor
     * 
     * @param message Message to print to console
     * @param cColor ConsoleColor used to format message
     */
    void print(const char* message, ConsoleColor cColor) const;
    // ===========================================================

    // ====================== Print string =======================
    /**
     * \overload void print(const std::string& message) 
     * \see void print(const char* message)
     */
    void print(const std::string& message) const;
    /**
     * \overload void print(const std::string& message, Color col, bool isForeground=true)
     * \see void print(const char* message, Color col, bool isForeground=true)
     */
    void print(const std::string& message, Color col, bool isForeground=true) const;
    /**
     * \overload void print(const std::string& message, Color foreground, Color background)
     * \see void print(const char* message, Color foreground, Color background)
     */
    void print(const std::string& message, Color foreground, Color background) const;
    /**
     * \overload void print(const std::string& message, ConsoleColor cColor)
     * \see void print(const char* message, Color foreground, Color background)
     */
    void print(const std::string& message, ConsoleColor cColor) const;
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
    void printLn(const char* message) const;
    /**
     * @brief Print message with linebreak to console setting foreground or background color
     * 
     * @param message Message to print to console
     * @param col Color used for text or background
     * @param isForeground Should the color be used for foreground
     */
    void printLn(const char* message, Color col, bool isForeground=true) const;
    /**
     * @brief Print message with linebreak to console setting foreground and background color
     * 
     * @param message Message to print to console
     * @param foreground Color used for text
     * @param background Color used for background
     */
    void printLn(const char* message, Color foreground, Color background) const;
    /**
     * @brief Print message with linebreak to console using ConsoleColor
     * 
     * @param message Message to print to console
     * @param cColor ConsoleColor used to format message
     */
    void printLn(const char* message, ConsoleColor cColor) const;
    // ===========================================================

    // ====================== PrintLn string =====================
    /**
     * \overload void printLn(const std::string& message)
     * \see void printLn(const char* message)
     */
    void printLn(const std::string& message) const;
    /**
     * \overload void printLn(const std::string& message, Color col, bool isForeground=true)
     * \see void printLn(const char* message, Color col, bool isForeground=true)
     */
    void printLn(const std::string& message, Color col, bool isForeground=true) const;
    /**
     * \overload void printLn(const std::string& message, Color foreground, Color background)
     * \see void printLn(const char* message, Color foreground, Color background)
     */
    void printLn(const std::string& message, Color foreground, Color background) const;
    /**
     * \overload void printLn(const std::string& message, ConsoleColor cColor)
     * \see void printLn(const char* message, ConsoleColor cColor)
     */
    void printLn(const std::string& message, ConsoleColor cColor) const;
    // ===========================================================
    ///@}
private:
#ifdef CMAKE_WINDOWS
    void init();
#endif
};

}

#endif