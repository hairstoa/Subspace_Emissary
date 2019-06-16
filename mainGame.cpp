/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston 
 * Date:         June 1, 2019
 *
 * mainGame.cpp
 * Calls functions from the Game class to run the program.
 * ****************************************************************************/
#include "classRelic.hpp"
#include "classSpace.hpp"
#include "classDarkMatter.hpp"
#include "classBlackHole.hpp"
#include "classAsteroidField.hpp"
#include "classPlanet.hpp"
#include "classExplorer.hpp"
#include "classGame.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
int main()
{
    std::string commanderName;
    Game::startMenu(commanderName); 
    Game subspaceEmissary(commanderName);
    subspaceEmissary.createSpaces();
    subspaceEmissary.runGame();
    return 0;
}
