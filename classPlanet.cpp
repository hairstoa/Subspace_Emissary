/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 2, 2019
 *
 * classPlanet.cpp
 * Implementation file. 
 * Derived from the Space base class. Class planet is a section of space where 
 * a planet can host aliens or can be colonized by our people. A planet can 
 * have a relic on it or offer fuel benefits.  
 * ****************************************************************************/
#include "classPlanet.hpp"
#include "classSpace.hpp"
#include "testInput.hpp"
#include "classExplorer.hpp"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
// constructor
Planet::Planet()
{
    isFirstVisit = true;
    baseFuelCost = 30;
    spaceType = "Planet";
    fuelFromPlanet = (((std::rand() % 70) + 30) /10) * 10;
    isInhabitable = true; 
    // create a number to determine if the planet has aliens, livable lane,
    // or just uninhabitable land  
    int chanceOfLife = std::rand() % 40 + 1;

    if ((chanceOfLife >= 1) && (chanceOfLife < 20))   
    {
        hasAliens = true;
    }   
    else if ((chanceOfLife >= 20) && (chanceOfLife < 35)) 
    {
        hasAliens = false;
    }   
    else
    {
        isInhabitable = false;
    }
   // create 2D array of char for the visual appearance of this space
   appearance = new char*[5];
   for(int i = 0; i < 5; i++)
   {
       appearance[i] = new char[10]; 
   } 
   // initiate what the space will look like, then copy it to the appearance
   char appearanceCopy[5][10] = {{' ',' ',' ',' ','_','_',' ',' ',' ',' '},
                             {' ',' ','/','%',';',' ',' ','\\',' ',' '},
                             {' ','|','%','@','%',';',' ',' ','|',' '},   
                             {' ',' ','\\','%','_','_',' ','/',' ',' '},
                             {' ','.',' ',' ',' ',' ',' ',' ',' ',' '}};   
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            appearance[i][j] = appearanceCopy[i][j];
        }   
    }        
}
/*******************************************************************************
 * Name: 	searchSpace
 * Called by: 	Game	
 * Calls: 	Explorer functions
 * Passed: 	Explorer pointer
 * Returns: 	void 	
 *
 * Decrements fuel for traveling this space. If the planet is not inhabitable,
 * nothing happens. If the planet can sustain life, it depends whether there
 * are aliends currently there or not. That is decided in the constructor. If
 * there are aliens, the user can choose to make friends resulting in a relic 
 * and fuel, or colonize them which won't wort and will cut off access to 
 * the planet's resources. If there are no aliens, the user can set up a 
 * habitat to gain fuel for each visit or to take the fuel on a one time bassis.   
 * ****************************************************************************/
void Planet::searchSpace(Explorer* spaceCraft)
{ 
    //subtract fuel costs for traveling in this space
    spaceCraft->setFuel(spaceCraft->getFuel() - baseFuelCost);
 if (isFirstVisit)
 { 
    cout << "A planet is ahead, the potential is exciting!" << endl;
    isFirstVisit = false;
    if (getHasAliens())   
    {
        cout << "Wow, there is alien life on this planet!" << endl;  
    }   
    else if (!isInhabitable)
    {
        cout << "The planet looks uninhabitable." << endl;
        cout << "We should keep moving." << endl;
    }
    else if (!getHasAliens()) 
    {
        setHasAliens(false);
        cout << "There is no sophisticated life here." << endl;
        cout << "Although, the landscape is ideal for an experimental habitat."
             << endl;
    }   
    // if there is life possible, ask the user if they want to interact with 
    // aliens, set up experimental habitat, or leave
    if (isInhabitable)
    {
        cout << "Shall we... " << endl;
        if (getHasAliens())
        {
            cout << "1) Try to communicate with the aliens" << endl;
            cout << "2) Colonize the land whether the aliens will cooperate"
                 << " or not" << endl;
        }
        else if (!getHasAliens())
        { 
            cout << "1) Build an experimental habitat" << endl; 
            cout << "2) Only check planet for fuel to collect" << endl;
        } 
        cout << "3) Leave and keep exploring elsewhere" << endl;    
        
        int choice = testInput(1, 3);
        if (choice == 3)
        {    cout << "Prepare to leave the planet's atmosphere." << endl;   }
        else if (getHasAliens())
        {
            if (choice == 1)
            {
                cout << "The aliens accepted our diplomacy, success!" << endl;
                if (hasRelic)
                { 
                    cout << "They also gifted us a relic!" << endl;
                    cout << relic->getRelicName() << " was added to the capsule."
                         << endl;
                    spaceCraft->addRelic(relic);
                    spaceCraft->setScore(spaceCraft->getScore() + relic->getPoints());
 
                    relic = NULL;
                    hasRelic = false; 
                }
                 setHasHabitat(true);
                // gain fuel from planet
                spaceCraft->setFuel(spaceCraft->getFuel() + fuelFromPlanet);
                // add alliance
                spaceCraft->setAlliances(spaceCraft->getAlliances()+1);
                // increment score
                spaceCraft->setScore(spaceCraft->getScore()+500);
            }     
            else if (choice == 2)
            {
                cout << "The aliens resist your attempts to colonize." << endl;
                cout << "We are not welcome to this planet anymore." << endl; 
            }      
        }
        else if (!getHasAliens())
        { 
            if (choice == 1)
            {   
                setHasHabitat(true);
                cout << "The experimental habitat is sustaining life." << endl;
                cout << "We can refuel here any time." << endl;
                
                spaceCraft->setFuel(spaceCraft->getFuel() + fuelFromPlanet);
                spaceCraft->setHabitats(spaceCraft->getHabitats()+1);
                spaceCraft->setScore(spaceCraft->getScore()+200);  
            }
            else if (choice == 2)
            {
                cout << "Extracting materials for fuel..." << endl;
                spaceCraft->setFuel(spaceCraft->getFuel() + fuelFromPlanet);
            }
        }
    }
  }
  // second visit
  else
  {
    // friendly relation with aliens, refuel 
    if((getHasAliens()) && (getHasHabitat()))
    {
        cout << "The alien ambassador from this planet offers us fuel." << endl;  
         spaceCraft->setFuel(spaceCraft->getFuel() + fuelFromPlanet);
    }

    // if there are aliens but no habitat, you tried to colonize and
    // the aliens aren't happy about it  
    else if (getHasAliens()) 
    {
        cout << "You tried to colonize alien life here and must stay away." 
             << endl; 
    } 
    else if (getHasHabitat())
    {
        cout << "We are refilling fuel from our habitat here." << endl;
        spaceCraft->setFuel(spaceCraft->getFuel() + fuelFromPlanet);
    }
    else
    {
        cout << "Nothing to do here. We have already visited this planet."
             << endl;
    }
  }  
}
// getters and setters for private data members
bool Planet::getHasAliens()
{
    return hasAliens;
}
void Planet::setHasAliens(bool trueOrFalse)
{
    hasAliens = trueOrFalse; 
}
bool Planet::getHasHabitat()
{
    return hasHabitat;
}
void Planet::setHasHabitat(bool trueOrFalse)
{
    hasHabitat = trueOrFalse;
}
int Planet::getFuel()
{
    return fuelFromPlanet;
}
void Planet::setFuel(int f)
{
    fuelFromPlanet = f;
}
// destructor
Planet::~Planet()
{
    for (int i = 0; i < 5; i++)
    {
        delete [] appearance[i];
    }
    delete [] appearance;
}
