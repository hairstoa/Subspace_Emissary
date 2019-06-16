/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston 
 * Date:         June 1, 2019
 *
 * classSpace.cpp
 * Implementation file.
 * Base class that represents a section of a Fictional Subspace. The space links
 * to other spaces around it by North South East and West Pointers. A space may 
 * also contain a relic. 
 * ****************************************************************************/
#include "classSpace.hpp"
#include "classRelic.hpp"
#include <string>
//constructor
Space::Space()
{
    north = NULL;
    east = NULL;
    south = NULL; 
    west = NULL;

    relic = NULL;   
   
    hasRelic = false;
    isVisible = false;
 
}
// getters and setters for member variables
std::string Space::getSpaceType()
{
    return spaceType;
}
char** Space::getAppearance()
{
    return appearance;
}
bool Space::getHasRelic()
{
    return hasRelic;
}
void Space::setHasRelic(bool trueOrFalse)
{
     hasRelic = trueOrFalse;
}
bool Space::getIsVisible()
{
    return isVisible;
}
void Space::setIsVisible(bool trueOrFalse)
{
    isVisible = trueOrFalse;
}
Relic* Space::getRelic()
{
    return relic;
}
void Space::setRelic(Relic* relic)
{
    this->relic = relic;
}
void Space::setNorth(Space* n)
{
    north = n;
}
void Space::setEast(Space* e)
{
    east = e;
}
void Space::setSouth(Space* s)
{
    south = s;
}
void Space::setWest(Space* w)
{
    west = w;
}
Space* Space::getNorth()
{
    return north;
}
Space* Space::getEast()
{
    return east;
}
Space* Space::getSouth()
{
    return south;
}
Space* Space::getWest()
{
    return west;
}
//destructor
Space::~Space()
{
} 

