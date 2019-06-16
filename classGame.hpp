/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 3, 2019
 *
 * classGame.hpp
 * Declaration file.
 * The Game will have menu functions, control the flow of the game, and handle 
 * the visual printing of the spaces and spaceCraft. 
 * ****************************************************************************/
#ifndef CLASSGAME_HPP
#define CLASSGAME_HPP
#include "classExplorer.hpp"
#include "classRelic.hpp"
#include "classSpace.hpp"
#include <string>
class Game
{
    private:
        int spaceColumns;
        int spaceRows;
        int spVisualRows;
        int spVisualCols;
        int numberOfRelics; 
        Explorer* shuttle;
        Relic** relics;
        char** spaceVisual;
        Space*** subspace;      
  
    public:
        Game(std::string comName);
        static void startMenu(std::string& coName);
        void createSpaces();
        void linkSpaces();
        void disperseRelics(); 
        void printSpaces();
        void runGame();  
        ~Game();
        
};
#endif
