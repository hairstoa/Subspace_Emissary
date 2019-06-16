/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 3, 2019
 *
 * classExplorer.cpp
 * Implemenation File.
 * Explorer is the space ship that the commander oversees. It has a tank for 
 * fuel and a capsule for holding Relics.
 * ****************************************************************************/
#include "classExplorer.hpp"
#include "classRelic.hpp"
#include "classSpace.hpp"
#include <queue>
#include <string>
#include <iostream>
//constructor  
Explorer::Explorer(std::string cName)
{
    commanderName =  cName;
    fuel = 200;
    location = NULL; 
    score = 0;
    habitats = 0;
    alliances = 0;
}
//setters and getters for data members
int Explorer::getFuel()
{
    if (fuel < 0)
    { 
        fuel = 0;
    }  
    return fuel;
}
void Explorer::setFuel(int f)
{
    fuel = f;
}
int Explorer::getScore()
{
    return score;
}
void Explorer::setScore(int s)
{
    score = s;
}
int Explorer::getHabitats()
{
    return habitats;
} 
void Explorer::setHabitats(int h)
{
    habitats = h;
}
int Explorer::getAlliances()
{
     return alliances;
}
void Explorer::setAlliances(int a)
{
    alliances = a;
}  
std::string Explorer::getCdrName()
{
    return commanderName;
}
void Explorer::setLocation(Space* place)
{
    location = place;
}
Space* Explorer::getLocation()
{
    return location;
}
// add a Relic to the capsule
void Explorer::addRelic(Relic* rlc)
{
    capsule.push(rlc);
} 
/*******************************************************************************
 * Name:        removeRelic 
 * Called by: 	asteroidField
 * Calls: 	none    
 * Passed: 	nothing   
 * Returns: 	bool
 *
 * If the capsule is not empty, this function removes the first relic. It
 * returns true if a relic was removed and false if not. 
 * ****************************************************************************/
bool Explorer::removeRelic()
{
    bool wasRelicRemoved = false;
    if (!capsule.empty())
    {
        capsule.pop();
        wasRelicRemoved = true;
    }
    return wasRelicRemoved;
}
/*******************************************************************************
 * Name: 	printRelics
 * Called by: 	various functions
 * Calls: 	none    
 * Passed: 	nothing   
 * Returns: 	void 	
 *
 * If the capsule is empty, it prints an error message, else the items are 
 * printed. 
 * ****************************************************************************/
void Explorer::printRelics()
{
    if (capsule.empty()) 
    {
        std::cout << "The capsule is empty." << std::endl;
    }
    else
    {
    std::queue <Relic*> copyCapsule = capsule;
    while(!copyCapsule.empty()) 
    {
        std::cout << copyCapsule.front()->getRelicName() << " | ";
        copyCapsule.pop();
    }
    std::cout << std::endl;
    }
}
/*******************************************************************************
 * Name: 	getRelicPoints 
 * Called by: 	various functions
 * Calls: 	none    
 * Passed: 	nothing   
 * Returns:     int
 *
 * If the capsule is empty, it returns 0, else the points from the items are 
 * summed. 
 * ****************************************************************************/
int Explorer::getRelicPoints()
{
    int pointSum = -1;
    if (capsule.empty()) 
    {
        pointSum = 0;
    }
    else
    {
    std::queue <Relic*> copyCapsule = capsule;
    pointSum = 0;
    while(!copyCapsule.empty()) 
    {
        pointSum += copyCapsule.front()->getPoints();
        copyCapsule.pop();
    }
    }
    return pointSum;
}
//getter for how many objects are in the capsule
int Explorer::getRelicCount()
{
    return capsule.size();
}
/*******************************************************************************
 * Name: 	useRadar
 * Called by: 	Game
 * Calls: 	none    
 * Passed: 	nothing   
 * Returns:     void
 *
 * Sets the space the explorer is on to visible and the 4 space around it in  
 * N, E, S, W directions. 
 * ****************************************************************************/
void Explorer::useRadar()
{
    location->setIsVisible(true);
    if (location->getNorth() != NULL)
    {
        location->getNorth()->setIsVisible(true);
    }
    if (location->getEast() != NULL)
    {
        location->getEast()->setIsVisible(true);
    }
    if (location->getSouth() != NULL)
    {
        location->getSouth()->setIsVisible(true);
    }
    if (location->getWest() != NULL)
    {
        location->getWest()->setIsVisible(true);
    }
  
}
//destructor
Explorer::~Explorer()
{

}
