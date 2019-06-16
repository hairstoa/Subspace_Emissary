/*******************************************************************************
 * Program name: Final Project
 * Author:       Adriane Hairston
 * Date:         June 2, 2019
 *
 * classAsteroidField.cpp
 * Implementation file.
 * Derived from the Space class. The Asteroid Belt may have a relic, or it may
 * cause you to loose a relic if an asteroid hits your ship. It takes more fuel
 * to cross an asteroid field because of the movement around each rock. 
 * ****************************************************************************/
#include "classAsteroidField.hpp"
#include "classSpace.hpp"
#include "classExplorer.hpp"
#include <cstdlib>
#include <iostream>
//constructor
AsteroidField::AsteroidField()
{
    baseFuelCost = 50;
    spaceType = "Asteroid Field"; 
    
    // set appearance
    appearance = new char*[5];
    for (int i = 0; i < 5; i++)
    { 
        appearance[i] = new char[10];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int randChar = rand() % 10 + 1;
            if (randChar == 1)
            {
                appearance[i][j] = '.';
            }  
            else if (randChar == 2)
            {
                appearance[i][j] = 'O';  
            }
            else if (randChar == 3)
            {
                appearance[i][j] = 'o'; 
            }
            else
            {
                appearance[i][j] = ' ';
            } 
        }
    }    
    
}
/*******************************************************************************
 * Name: 	searchSpace
 * Called by: 	Game
 * Calls: 	dodgeAsteroids    
 * Passed: 	Explorer pointer
 * Returns: 	void 	
 *
 * Searching through the asteroid field could cause an unwanted impact with an
 * asteroid that results in losing a relic.
 * ****************************************************************************/
void AsteroidField::searchSpace(Explorer* spaceCraft)
{
    //subtract fuel costs for traveling in this space
    spaceCraft->setFuel(spaceCraft->getFuel() - baseFuelCost);

    std::cout << "We must travel through this area with caution."
         << " Asteroids could be moving at high speeds." << std::endl;
   
    dodgeAsteroids(spaceCraft);
}
/*******************************************************************************
 * Name: 	dodgeAsteroids 
 * Called by: 	searchSpace
 * Calls: 	Explorer::removeRelic
 * Passed: 	nothing   
 * Returns: 	void 	
 *
 * This function creates a fifty percent chance for the shuttle to dodge
 * asteroids. If the shuttle is hit and has a relic, it will loose a relic. 
 * ****************************************************************************/
void AsteroidField::dodgeAsteroids(Explorer* shuttle)
{
    int dodge = rand() % 10 + 1;
    if (dodge > 5)
    {
        std::cout << "Oh no! Our ship has been hit!" << std::endl;
        std::cout << "Check the capsule!" << std::endl;     
        std::cout << "..." << std::endl;
        
       if ( shuttle->removeRelic())
       {
           std::cout << "A relic was lost." << std::endl;
       } 
     
    }
}
//destructor
AsteroidField::~AsteroidField()
{
    for (int i = 0; i < 5; i++)
    {
        delete [] appearance[i];
    }
    delete [] appearance;
}
