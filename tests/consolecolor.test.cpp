#include <gtest/gtest.h>
#include "color.hpp"

void checkConsoleColorData(
  const con::ConsoleColor& conCol, 
  const con::Color& forCol, 
  const con::Color& backCol, 
  bool isBold, bool isUnderline, bool isItalic, 
  const std::string& message, const std::string& ccString
)
{
  EXPECT_EQ(conCol.getForegroundColor(), forCol);
  EXPECT_EQ(conCol.getBackgroundColor(), backCol);
  EXPECT_EQ(conCol.isBold(), isBold);
  EXPECT_EQ(conCol.isUnderline(), isUnderline);
  EXPECT_EQ(conCol.isItalic(), isItalic);

  EXPECT_EQ(conCol.colorString(message), ccString);
}

TEST(ConsoleColor, CheckColorConstructor)
{
  con::Color forCol(con::RED);
  con::Color backCol(con::GREEN);

  con::ConsoleColor conCol(forCol, backCol);

  std::string ccString = "\033[38;2;255;0;0;48;2;0;255;0mTest\033[0m";
  checkConsoleColorData(conCol, forCol, backCol, false, false, false, "Test", ccString);
}

TEST(ConsoleColor, CheckFormatConstructor)
{
  con::Color noneCol(con::NONE);
  con::ConsoleColor conCol(true, false, true);

  std::string ccString = "\033[;1;3mTest\033[0m";
  checkConsoleColorData(conCol, noneCol, noneCol, true, false, true, "Test", ccString);
}

TEST(ConsoleColor, CheckFullConstructor)
{
  con::Color forCol(con::NONE);
  con::Color backCol(con::YELLOW);
  con::ConsoleColor conCol(forCol, backCol, false, true, true);

  std::string ccString = "\033[;48;2;255;255;0;4;3mTest\033[0m";
  checkConsoleColorData(conCol, forCol, backCol, false, true, true, "Test", ccString);
}

TEST(ConsoleColor, CheckDefaultConstructor)
{
  con::Color noneCol(con::NONE);
  con::ConsoleColor conCol;

  std::string ccString = "\033[mTest\033[0m";
  checkConsoleColorData(conCol, noneCol, noneCol, false, false, false, "Test", ccString);
}