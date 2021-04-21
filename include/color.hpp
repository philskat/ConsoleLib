#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

namespace con {

    /**
     * @brief Predefined ColorCodes
     * 
     */
    enum ColorCode
    {
        BLACK, //!< Color Back (0, 0, 0)
        WHITE, //!< Color White (255, 255, 255)
        RED, //!< Color Red (255, 0, 0)
        GREEN, //!< Color Green (0, 255, 0)
        BLUE, //!< Color Blue (0, 0, 255)
        YELLOW, //!< Color Yellow (255, 255, 0)
        MAGENTA, //!< Color Magenta (255, 0, 255)
        CYAN, //!< Color Cyan (0, 255, 255)
        NONE //!< Use the default color
    };

    /**
     * @brief Object that stores the RGB data of a color
     * 
     */
    class Color
    {
    private:
        int m_R/**< Red value of color */, m_G/**< Green value of color */, m_B/**< Blue value of color */;

    public:
        /**
         * @brief Construct a new Color object
         * 
         * @param r Red value of the color (0-255)
         * @param g Green value of the color (0-255)
         * @param b Blue value of the color (0-255)
         */
        Color(int r, int g, int b);
        /**
         * @brief Construct a new Color object
         * 
         * @param color ColorCode used for color
         * \see ColorCode for possible values
         */
        Color(ColorCode color);

        /**
         * @brief Return the Color in the format r;g;b used for Formating strings in ConsoleColor
         * 
         * @return std::string r;g;b values used to format String
         */
        std::string getColorCodeString() const;

        /**
         * @brief Get the Red value
         * 
         * @return char Value of Red component of the color
         */
        int getRed() const;
        /**
         * @brief Get the Green value
         * 
         * @return char Value of Green component of the color
         */
        int getGreen() const;
        /**
         * @brief Get the Blue value
         * 
         * @return char Value of Blue component of the color
         */
        int getBlue() const;

        bool operator==(const Color& other) const;
        bool operator!=(const Color& other) const;
        bool operator>(const Color& other) const = delete;
        bool operator<(const Color& other) const = delete;
        bool operator>=(const Color& other) const = delete;
        bool operator<=(const Color& other) const = delete;

    private:
        /**
         * @brief Convert ColorCode to RGB
         * 
         * @param col ColorCode to be converted
         * @param r Red value
         * @param g Green value
         * @param b Blue value
         */
        void getRGBFromColorCode(ColorCode col, int& r, int& g, int& b);
    };

    /**
     * @brief Class to convert text into given color
     * 
     */
    class ConsoleColor
    {
    private:
        Color m_Foreground /**< Text color */, m_Background /**< Background color */;
        bool m_IsBold /**< Bold text */, m_IsUnderline /**< Underline text */, m_IsItalic /**< Italic text */;

    public:
        /**
         * @brief Construct a new Console Color object
         * 
         * @param foreground Color for text
         * @param background Color for background
         */
        ConsoleColor(Color foreground, Color background);
        /**
         * @brief Construct a new Console Color object
         * 
         * @param isBold Is bold text
         * @param isUnderline Is underline text
         * @param isItalic Is italic text
         */
        ConsoleColor(bool isBold, bool isUnderline, bool isItalic);
        /**
         * @brief Construct a new Console Color object
         * 
         * @param foreground Color for text
         * @param background Color for background
         * @param isBold Is bold text
         * @param isUnderline Is underline text
         * @param isItalic Is italic text
         */
        ConsoleColor(Color foreground, Color background, bool isBold, bool isUnderline, bool isItalic);
        /**
         * @brief Construct a new Console Color object
         * 
         * Using Default console colors
         */
        ConsoleColor();

        /**
         * @brief Add necessary characters to format text
         * 
         * @param msg Message to be formatted
         * @return std::string Formatted text
         */
        std::string colorString(const std::string& msg) const;

        /**
         * @brief Set the Foreground color
         * 
         * @param color Color for text
         */
        void setForegroundColor(const Color& color);
        /**
         * @brief Get foreground Color
         * 
         * @return Color Foreground color 
         */
        Color getForegroundColor() const;

        /**
         * @brief Set the Background color
         * 
         * @param color Color for background
         */
        void setBackgroundColor(const Color& color);
        /**
         * @brief Get background Color
         * 
         * @return Color Background color
         */
        Color getBackgroundColor() const;

        /**
         * @brief Set the Bold flag
         * 
         * @param isBold Is bold text
         */
        void setBold(bool isBold);
        /**
         * @brief Should text be bold
         * 
         * @return true Text is bold
         * @return false Text is not bold
         */
        bool isBold() const;

        /**
         * @brief Set the Underline flag
         * 
         * @param isUnderline Is underline text
         */
        void setUnderline(bool isUnderline);
        /**
         * @brief Should text be underline
         * 
         * @return true Text is underline
         * @return false Text is not underline
         */
        bool isUnderline() const;

        /**
         * @brief Set the Italic flag
         * 
         * @param isItalic Is italic text
         */
        void setItalic(bool isItalic);
        /**
         * @brief Should text be italic
         * 
         * @return true text is italic
         * @return false text is not italic
         */
        bool isItalic() const;
    };

}

#endif