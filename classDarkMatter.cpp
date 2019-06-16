/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 1, 2019
 *
 * classDarkMatter.cpp
 * Implementation file.
 * This is a class derived from Space. The Dark Matter represents an area of 
 * space that doesn't have much in it that is larger than particles. There is 
 * a small chance of finding a relic here. 
 * ****************************************************************************/
#include "classDarkMatter.hpp"
#include "classSpace.hpp"
#include "classRelic.hpp"
#include "classExplorer.hpp"
#include <iostream> 
#include <cstdlib>
//constructor
DarkMatter::DarkMatter()
{
    baseFuelCost = 10;
    spaceType = "Dark Matter";
    // set appearance
   // create 2D array of char for the visual appearance of this space
    appearance = new char*[5];
    for(int i = 0; i < 5; i++)
    {
        appearance[i] = new char[10]; 
    }  

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int randChar = rand() % 12 + 1;
            if (randChar == 1)
            {
                appearance[i][j] = '.';
            }  
            else if (randChar == 2)
            {
                appearance[i][j] = '*';  
            }
            else if (randChar == 3)
            {
                appearance[i][j] = ','; 
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
 * Calls: 	none    
 * Passed: 	nothing   
 * Returns: 	void 	
 *
 * This function is overridden˙by the derived Space classes.
 * In dark matter a line is printed to the console and a small chance to find 
 * a relic.   
 * ****************************************************************************/
void DarkMatter::searchSpace(Explorer* spaceCraft)
{
    //subtract fuel costs for traveling in this space
    spaceCraft->setFuel(spaceCraft->getFuel() - baseFuelCost);
 
   // if there is a relic in the space, give the ship a chance to find it, 
   // else, there will be nothing they find.  
   if (hasRelic)
   {
       int randNum = (std::rand() % 10) +1;
       if (randNum > 5)
       {
            std::cout << "The team has reported no substanstial findings from"
                      << " this area." << std::endl;  

       }  
       // the team foud a relic
       else
       {
           std::cout << "How interesting, we found a relic amongst"
                     << " the Dark Matter!" << std::endl;
           std::cout << relic->getRelicName() 
                     << " was added to the capsule." << std::endl;  
           spaceCraft->addRelic(relic);
           spaceCraft->setScore(spaceCraft->getScore() + relic->getPoints());
 
           relic = NULL;
           hasRelic = false;
       } 
   }
   else
   { 
       std::cout << "The team has reported no substanstial findings from "
                 << "this area." << std::endl;  
   }
}
//destructor
DarkMatter::~DarkMatter()
{
   for(int i = 0; i < 5; i++)
   {
      delete [] appearance[i]; 
   } 
   delete [] appearance;
}

