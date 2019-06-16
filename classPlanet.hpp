/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 2, 2019
 *
 * classPlanet.hpp
 * Declaration file. 
 * Derived from the Space base class. Class planet is a section of space where 
 * a planet can host aliens or can be colonized by our people. A planet can 
 * have a relic on it or offer fuel benefits.  
 * ****************************************************************************/
#ifndef CLASSPLANET_HPP
#define CLASSPLANET_HPP
#include "classSpace.hpp"
#include "classExplorer.hpp"
class Planet : public Space
{
    private:
        int fuelFromPlanet;
        bool hasAliens;
        bool hasHabitat;
        bool isInhabitable;
        bool isFirstVisit; 
    public:
         Planet();
         void searchSpace(Explorer* spaceCraft);
         bool getHasAliens();
         void setHasAliens(bool trueOrFalse);
         bool getHasHabitat();
         void setHasHabitat(bool trueOrFalse);
         int getFuel();
         void setFuel(int f);
         ~Planet();
};
#endif  
