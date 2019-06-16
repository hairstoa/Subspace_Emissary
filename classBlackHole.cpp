/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston 
 * Date:         June 1, 2019
 *
 * classBlackHole.cpp
 * Implementation file. 
 * Black Hole is derived from the Space Class. It has a unique function to 
 * teleport the player's spaceship to a different random location. 
 * ****************************************************************************/
#include "classBlackHole.hpp"
#include "classSpace.hpp"
#include <iostream> 
#include <cstdlib>
//constructor
BlackHole::BlackHole()
{
    baseFuelCost = 20;
    spaceType = "Black Hole";
   //set appearance
    appearance = new char*[5];
    for (int i = 0; i < 5; i++)
    {
        appearance[i] = new char[10];
    } 
    char appearanceCopy[5][10] = {{' ',' ',' ',' ',' ','.',' ',' ',' ',' '},
                             {' ',' ',' ',',','"','"',',',' ',' ',' '},
                             {' ',' ',',','*',' ',' ','*',',',' ',' '},   
                             {' ',' ',' ',' ','"','"',' ',' ',' ',' '},
                             {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};   
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            appearance[i][j] = appearanceCopy[i][j];
        }   
    }        
       
}
void BlackHole::setTeleportTo(Space* t)
{
    teleportTo = t;
}
/*******************************************************************************
 * Name:        searchSpace 	
 * Called by: 	game
 * Calls: 	none    
 * Passed: 	nothing   
 * Returns: 	void 	
 *
 * The Black Hole teleports the ship to the other black hole location. The user 
 * may gain a relic through the process.
 * ****************************************************************************/
void BlackHole::searchSpace(Explorer* spaceCraft)
{
    //subtract fuel costs for traveling in this space
    spaceCraft->setFuel(spaceCraft->getFuel() - baseFuelCost);
   
    std::cout << "We teleported through a wormhole." << std::endl;  
 
    spaceCraft->setLocation(teleportTo);
    if (hasRelic == true)
    {
        std::cout << "Amazing, there is a relic in here!" << std::endl;
        std::cout << "We collected " << relic->getRelicName() << "!" << std::endl;
        spaceCraft->addRelic(relic);
        spaceCraft->setScore(spaceCraft->getScore() + relic->getPoints());
        relic = NULL;
        hasRelic = false;    
    }
}
BlackHole::~BlackHole()
{
    for (int i = 0; i < 5; i++)
    {
        delete [] appearance[i];
    } 
    delete [] appearance;

}

