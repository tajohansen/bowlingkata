
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Game.h"

TEST_CASE("Does the Game exist", "[score]")
{
    // Arrange
    Game *g = new Game;
    bool exist = true;

    // Act
    if (g == NULL) {
        exist = false;
    }
    // Assert
    REQUIRE(g != NULL);
}

    TEST_CASE("Gutter game return 0", "[score]")
    {
        // Arrange
        Game g;
        int pins = 0;


        // Act
        g.roll(pins);
        for (int frame = 0; frame < 20; frame++)
        {
            g.roll(pins);
        }

        // Assert
        REQUIRE(0 == g.scoreGame());
    }

TEST_CASE("Single Pin Game Return 20", "[score]")
{
    // Arrange
    Game g;
    int pins = 1;

    // Act

    for (int frame = 0; frame < 20; frame++)
    {
        g.roll(pins);
    }

    // Assert
    REQUIRE(20 == g.scoreGame());
}

TEST_CASE("One Spare Game returns correct value", "[score]")
{
    // Arrange
    Game g;
    int pins = 0;

    // Act
    g.roll(5);
    g.roll(5);
    g.roll(3);
    for (int frame = 0; frame < 17; frame++)
    {
        g.roll(pins);
    }

    // Assert
    REQUIRE(16 == g.scoreGame());
}

TEST_CASE("All Strikes", "[score]")
{
    // Arrange
    Game g;
    int pins = 10;

    // Act

    for (int frame = 0; frame < 12; frame++)
    {
        g.roll(pins);
    }

    // Assert
    REQUIRE(300 == g.scoreGame());
}


