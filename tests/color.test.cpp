#include <gtest/gtest.h>
#include "color.hpp"

void expectColor(const con::Color& col, int r, int g, int b)
{
  EXPECT_EQ(col.getRed(), r);
  EXPECT_EQ(col.getGreen(), g);
  EXPECT_EQ(col.getBlue(), b);

  std::string ccString = std::to_string(r) + ";" + 
                         std::to_string(g) + ";" + 
                         std::to_string(b);
  EXPECT_EQ(col.getColorCodeString(), ccString);
}

TEST(ColorTest, CheckRGBConstructor)
{
  con::Color col(100, 50, 20);

  expectColor(col, 100, 50, 20);
}

TEST(ColorTest, CheckBlackColorCodeConstructor)
{
  con::Color col(con::ColorCode::BLACK);

  expectColor(col, 0, 0, 0);
}

TEST(ColorTest, CheckWhiteColorCodeConstructor)
{
  con::Color col(con::ColorCode::WHITE);

  expectColor(col, 255, 255, 255);
}

TEST(ColorTest, CheckRedColorCodeConstructor)
{
  con::Color col(con::ColorCode::RED);

  expectColor(col, 255, 0, 0);
}

TEST(ColorTest, CheckGreenColorCodeConstructor)
{
  con::Color col(con::ColorCode::GREEN);

  expectColor(col, 0, 255, 0);
}

TEST(ColorTest, CheckBlueColorCodeConstructor)
{
  con::Color col(con::ColorCode::BLUE);

  expectColor(col, 0, 0, 255);
}

TEST(ColorTest, CheckYellowColorCodeConstructor)
{
  con::Color col(con::ColorCode::YELLOW);

  expectColor(col, 255, 255, 0);
}

TEST(ColorTest, CheckMagentaColorCodeConstructor)
{
  con::Color col(con::ColorCode::MAGENTA);

  expectColor(col, 255, 0, 255);
}

TEST(ColorTest, CheckCyanColorCodeConstructor)
{
  con::Color col(con::ColorCode::CYAN);

  expectColor(col, 0, 255, 255);
}

TEST(ColorTest, CheckNoneColorCodeConstructor)
{
  con::Color col(con::ColorCode::NONE);

  EXPECT_EQ(col.getRed(), -1);
  EXPECT_EQ(col.getGreen(), -1);
  EXPECT_EQ(col.getBlue(), -1);
  EXPECT_EQ(col.getColorCodeString(), "");
}