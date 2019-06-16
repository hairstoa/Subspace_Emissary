/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 3, 2019
 *
 * classGame.cpp
 * Implementation file.
 * The Game will have menu functions, control the flow of the game, and handle 
 * the visual printing of the spaces and spaceCraft. 
 * ****************************************************************************/
#include "classGame.hpp"
#include "classRelic.hpp"
#include "classExplorer.hpp"
#include "classSpace.hpp"
#include "classPlanet.hpp"
#include "classBlackHole.hpp"
#include "classAsteroidField.hpp"
#include "classDarkMatter.hpp"
#include "testInput.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using std::endl;
using std::cout;
// constructor
Game::Game(std::string comName)
{
    std::srand(std::time(0));
    spaceColumns = 4;  
    spaceRows = 4; 
    spVisualRows = 24;  //( the number of rows * 5) + 4(for borders)
    spVisualCols = 44;  //( the number of columns * 10) + 4 (for borders) 
    numberOfRelics = 6; //must be less than number of spaces 

    shuttle = new Explorer(comName);
}
void Game::startMenu(std::string& coName)
{
    cout << endl;
    cout << "/@@  @ @  @\\   /@@  @@\\   @   /@\\  @@@" << endl;
    cout << "@    @ @  @/   @    @ @  / \\  @ @  @  " << endl;
    cout << "\\@@  @ @  @@\\  \\@@  @@/  @=@  @    @@ " << endl;
    cout << "  @  @ @  @ @    @  @    @ @  @ @  @" << endl;
    cout << "@@/  \\@/  @@/  @@/  @    @ @  \\@/  @@@" << endl;
    cout << endl;
    cout << "@@@  \\ /  @@@  /@@  /@@   @   @@\\  @ @" << endl;
    cout << "@    @V@   @   @    @    / \\  @ @  \\ /" << endl;
    cout << "@@   @ @   @   \\@@  \\@@  @=@  @@/   @ " << endl;
    cout << "@    @ @   @     @    @  @ @  @\\    @ " << endl;
    cout << "@@@  @ @  @@@  @@/  @@/  @ @  @ \\   @ " << endl;
    cout << endl;    
    cout << "Welcome to Subspace Emissary." << endl;
    cout << "An outerspace journey to explore, collect, and learn." << endl;
    cout << endl; 
    cout << "I'm Findlay, your Pilot." << endl;
    cout << "What is your name, Commander?" << endl;
    
    std::getline(std::cin, coName); 
    cout << endl;
    cout << "Nice to finally meet you, " << coName << "!" << endl;
    cout << "I am already familiar with our -" << endl;
    cout << " * MISSION OBJECTIVES * " << endl;
    cout << "   - Collect 2 Relics " << endl;
    cout << "   - Build an Experimental Habitat" << endl;
    cout << "   - Forge an Alliance with Aliens" << endl;
    cout << endl;
    cout << "Fuel is limited. Our mission is over if we run out." << endl;
    cout << endl;
    cout << "   Once we warp into the subspace, our radar will reveal" << endl;
    cout << "the nearest surrounding areas. It is up to you to lead our" <<endl;
    cout << "team through the unknown. Relics are scattered through the"<< endl;
    cout << "vastness of space. As Carl said, \"Imagination will often" << endl;
    cout << "carry us to worlds that never were. But without it we go " << endl;   
    cout << "nowhere.\"" << endl;
 
} 
void Game::createSpaces()
{
    // create the visual element
    // make the borders, fill the rest with empty spaces
    spaceVisual = new char*[spVisualRows];
    for (int i = 0; i < spVisualRows; i++)
    {
        spaceVisual[i] = new char[spVisualCols];
        for (int j = 0; j < spVisualCols; j++)
        {
            if (( i == 0) || (i == 1) || (i == 22) || (i == 23)) 
            {
                spaceVisual[i][j] = '-';
            }
            else if ((j == 0) || (j == 1) || (j == 42) || (j == 43))
            {
                spaceVisual[i][j] = '|';  
            } 
            else 
            { 
                spaceVisual[i][j] = ' ';
            }
        } 
    }
    // fill the corners
    // top right
    spaceVisual[0][0] = ' ';
    spaceVisual[0][1] = '/';
    spaceVisual[1][0] = '/';
    spaceVisual[1][1] = '/';
    // bottom right
    spaceVisual[spVisualRows-1][0] = ' ';
    spaceVisual[spVisualRows-2][0] = '\\';
    spaceVisual[spVisualRows-2][1] = '\\';
    spaceVisual[spVisualRows-1][1] = '\\';      
    // bottom left
    spaceVisual[spVisualRows-1][spVisualCols-1] = ' ';
    spaceVisual[spVisualRows-1][spVisualCols-2] = '/';
    spaceVisual[spVisualRows-2][spVisualCols-2] = '/';
    spaceVisual[spVisualRows-2][spVisualCols-1] = '/';   
    // top left
    spaceVisual[0][spVisualCols-1] = ' ';
    spaceVisual[0][spVisualCols-2] = '\\';
    spaceVisual[1][spVisualCols-2] = '\\';
    spaceVisual[1][spVisualCols-1] = '\\';
    // directions
    spaceVisual[0][22] = 'N';
    spaceVisual[12][43] = 'E';
    spaceVisual[23][22] = 'S';
    spaceVisual[12][0] = 'W';    

    // create the space objects
    subspace = new Space**[spaceRows];
     
    for (int i = 0; i < spaceRows; i++)
    {
        subspace[i] = new Space*[spaceColumns];
        for (int j = 0; j < spaceColumns; j++)
        {
            subspace[i][j] = NULL; 
        }  
    } 
    // how many of each space derived class there are
    // these numbers must add up to the rows * columns 
    int numPlanets = 4;
    int numBlackHoles = 2;
    //saveBH variables hold row and column of first blackholes object
    int saveBHR1 = -1;
    int saveBHC1 = -1; 
    int numAsteroids = 3;
    int numDarkMatter = 7;
    int randNum;
    int numExplorer = 1; 
    // a loop to randomly instantiate the derived classes
    // so the spaces are different each play through   
     for (int p = 0; p < spaceRows; p++)
    {
        for (int q = 0; q < spaceColumns; q++)
        {    
            while(subspace[p][q] == NULL)
            {
                randNum = std::rand() % 4 + 1;
                if (randNum == 1)
                {
                    if (numPlanets > 0)
                    {
                        subspace[p][q] = new Planet();
                        numPlanets -= 1;
                    } 
                }   
                else if (randNum == 2)
                {
                    if (numBlackHoles > 0)
                    {   
                        if (numBlackHoles == 2)
                        {
                           saveBHR1 = p;
                           saveBHC1 = q;  
                        }                
                        subspace[p][q] = new BlackHole();
                        numBlackHoles -= 1;   
                        if (numBlackHoles == 0)
                        {
                           BlackHole* bh2 = static_cast<BlackHole*>(subspace[p][q]); 
                           BlackHole* bh1 = static_cast<BlackHole*>(subspace[saveBHR1][saveBHC1]);  
                           bh2->setTeleportTo(subspace[saveBHR1][saveBHC1]);
                           bh1->setTeleportTo(subspace[p][q]);   
                        }   
                    }   
                }
                else if (randNum == 3)
                {
                    if (numAsteroids > 0)
                    {
                        subspace[p][q] = new AsteroidField();
                        numAsteroids -= 1;
                    }  
                }
                else // randNum == 4  
                {
                    if (numDarkMatter > 0)
                    {
                        subspace[p][q] = new DarkMatter();
                        numDarkMatter -= 1;
                        //place the explorer in Dark Matter 
                        if (numExplorer > 0)
                        {
                            shuttle->setLocation(subspace[p][q]); 
                            numExplorer -= 1; 
                        } 
                    }  
                }
            } 
             
        } 
    }
    // connect the spaces through N,E,S,W direction pointers
    linkSpaces();
    // add relics randomly to spaces
    disperseRelics();
}
void Game::linkSpaces()
{
    int randSpaRo;
    int randSpaCo; 
    for (int ro = 0; ro < spaceRows; ro++)
    {
        for (int co = 0; co < spaceColumns; co++)
        {
            if (ro < 3)
            {
                subspace[ro][co]->setSouth(subspace[ro+1][co]);
            }
            if (ro > 0)
            {
                subspace[ro][co]->setNorth(subspace[ro-1][co]);
            }
            if (co < 3)
            {
                subspace[ro][co]->setEast(subspace[ro][co+1]); 
            }
            if (co > 0)
            {
                subspace[ro][co]->setWest(subspace[ro][co-1]);
            }
        }
    }
}
void Game::disperseRelics()
{
    bool isRelicSet;
    int randRow;
    int randCol;
    
    relics = new Relic*[numberOfRelics];
    for (int r = 0; r < numberOfRelics; r++)
    {
        relics[r] = new Relic(); 
    }
    for (int i = 0; i < numberOfRelics; i++)
    {
        isRelicSet = false;
        // while the relic has not been placed, generate a random space
        // if that space does not have a relic and is not an asteroid field
        // place the relic there. Else, repeat until the relic is placed. 
        while (!isRelicSet)
        {
            randRow = std::rand() % (spaceRows-1);
            randCol = std::rand() % (spaceColumns-1);
     
            if (subspace[randRow][randCol]->getHasRelic() == false)
            {
                if (subspace[randRow][randCol]->getSpaceType() != "Asteroid Field")
                {
                  subspace[randRow][randCol]->setRelic(relics[i]);
                  subspace[randRow][randCol]->setHasRelic(true);
                  isRelicSet = true;
                }   
            }   
        }  
    }
    /* relic cheat sheet locations
    for (int i = 0; i < spaceRows; i++)
    {
        for (int j = 0; j < spaceColumns; j++)
        {
            if (subspace[i][j]->getHasRelic() == true)
            {
                cout << subspace[i][j]->getRelic()->getRelicName() << "   "; 
            }
            else
            {
                cout << "NORELICHERE   ";
            }  

        }
        cout << endl;
    }
    */
} 
void Game::printSpaces()
{
    int offsetR = 2;
    int offsetC;
    // for each space, get its appearance, and copy it to the char
    // spaceVisual board. There is an offset for moving across the board
    // and for the borders.
    for (int spRow = 0; spRow < spaceRows; spRow++)
    {
        offsetC = 2; 
        for (int spCol = 0; spCol < spaceColumns; spCol++)
        {
          if(subspace[spRow][spCol]->getIsVisible() == true)
          { 
            // each space appearance is copied through more nested loops
            // the appearance of the space has 5 rows and 10 char columns
            for (int chRow = 0; chRow < 5; chRow++)
            {
                for (int chCol = 0; chCol < 10; chCol++)
                {
                    spaceVisual[chRow+offsetR][chCol+offsetC] = subspace[spRow][spCol]->getAppearance()[chRow][chCol];
                } 
            }
            // override one of the characters to be the ship 'X'
            // 2 and 5 + the offset puts it roughly in the middle of the space  
            if (subspace[spRow][spCol] == shuttle->getLocation())
            {
                spaceVisual[2+offsetR][5+offsetC] = 'X';
            } 
          } 
            offsetC += 10;   
        }
        offsetR += 5;
    } 
    // print the board of characters
    for (int row = 0; row < spVisualRows; row++)
    {
        for (int col = 0; col < spVisualCols; col++)
        {  
            cout << spaceVisual[row][col];
        }
        cout << endl; 
    } 

}
void Game::runGame()
{
    bool keepPlaying = true;
    bool isDirectionValid;
    int choice;
    //note
    cout << "Our shuttle, the Explorer, looks like an 'X' on the radar." << endl;
    cout << endl;

    while (keepPlaying)
    {  
        isDirectionValid = false; 
        //interact with current space 
        shuttle->getLocation()->searchSpace(shuttle);
        cout << endl; 
         
        shuttle->useRadar(); 
        printSpaces();
        cout << endl;  
        //print fuel, relics, points, habitat
        cout << "==============================" << endl;
        cout << "Fuel: " << shuttle->getFuel() << "   ";
        cout << "Score: " << shuttle->getScore() << "   ";
        cout << endl; 
        cout << "Exp Habitat: ";
        if (shuttle->getHabitats() > 0)
        {    cout << "Yes   ";   }
        else
        {    cout << "No    ";   }
        cout << "Alliance: ";
        if (shuttle->getAlliances() > 0)
        {    cout << "Yes   ";   }
        else
        {    cout << "No    ";   }    
        cout << endl;
        cout << "Inventory: ";
        shuttle->printRelics(); 
        cout << "==============================" << endl;
        cout << endl;

        if ( shuttle->getFuel() <= 0)
        { 
             cout << "The mission is over. We will be warped back to Earth "
                  << "with disappointing news of failure." << endl; 
             cout << endl;
             cout << "Final Score: " << shuttle->getScore() << endl; 
             keepPlaying = false; 
        }      
        else if ((shuttle->getRelicCount() >= 2) 
              && (shuttle->getHabitats() > 0) && (shuttle->getAlliances() > 0))
        {   
            cout << " * o * Celebrate! * o * " << endl; 
            cout << "We did it! The mission is successful." << endl;
            cout << "Our findings can be studided further after we take the "
                 << "next wormhole back to Earth." << endl;
            cout << "Final Score: " << shuttle->getScore() << endl;
            keepPlaying = false;
        }
        else
        {
          while (!isDirectionValid)
          { 
            cout << "Choose the direction of travel" << endl;
            cout << "   1) North" << endl;
            cout << "   2) East" << endl;
            cout << "   3) South" << endl;
            cout << "   4) West"  << endl;

            choice = testInput(1, 4);
           
            // make sure the direction of travel is not null, then relocate the shuttle
            // if it is NULL, reprint the menu
            if (choice == 1)
            {
                if (shuttle->getLocation()->getNorth() != NULL) 
                {
                    shuttle->setLocation(shuttle->getLocation()->getNorth());
                    isDirectionValid = true;  
                } 
                else
                {   cout << "Invalid direction, please pick again." << endl;}
            }
            else if (choice == 2)
            {
                if (shuttle->getLocation()->getEast() != NULL) 
                {
                    shuttle->setLocation(shuttle->getLocation()->getEast());
                    isDirectionValid = true;  
                } 
                else
                {   cout << "Invalid direction, please pick again." << endl;}
            }      
            else if (choice == 3)
            {
                if (shuttle->getLocation()->getSouth() != NULL) 
                {
                    shuttle->setLocation(shuttle->getLocation()->getSouth());
                    isDirectionValid = true;  
                } 
                else
                {   cout << "Invalid direction, please pick again." << endl;}
            }
            else //choice == 4
            {
                if (shuttle->getLocation()->getWest() != NULL) 
                {
                    shuttle->setLocation(shuttle->getLocation()->getWest());
                    isDirectionValid = true;  
                } 
                else
                {   cout << "Invalid direction, please pick again." << endl;}
            }  
          }  
        }
             
    }
 
     
     
}
Game:: ~Game()
{
    //delete Relics
    for (int r = 0; r < numberOfRelics; r++)
    {
        delete relics[r]; 
    }   
    delete [] relics;
 
    delete shuttle;

    // delete visual char board
    for (int i = 0; i < spVisualRows; i++)
    {
        delete [] spaceVisual[i]; 
    }  
    delete [] spaceVisual;

    // delete space object array
    for (int row = 0; row < spaceRows; row++)
    {
        for (int col = 0; col < spaceColumns; col++)
        {
            delete subspace[row][col];  
        }
    } 

    for (int i = 0; i < spaceRows; i++)
    {
        delete [] subspace[i]; 
    }  
    delete [] subspace;
    
}

