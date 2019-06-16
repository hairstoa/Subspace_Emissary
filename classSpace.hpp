/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston 
 * Date:         June 1, 2019
 *
 * classSpace.hpp
 * Declaration file.
 * Base class that represents a section of a Fictional Subspace. The space links
 * to other spaces around it by North South East and West Pointers. A space may 
 * also contain a relic. 
 * ****************************************************************************/
#ifndef CLASSSPACE_HPP
#define CLASSSPACE_HPP
#include <string>
#include "classRelic.hpp"

class Explorer; //forward declaration

class Space
{
    protected:
        Space* north;
        Space* east;
        Space* south;
        Space* west;
        Relic* relic;
        bool hasRelic;
        bool isVisible;
        int baseFuelCost; 
        std::string spaceType;
        char** appearance;
 
    public:
        Space(); 
        char** getAppearance(); 
        std::string getSpaceType(); 
        bool getHasRelic();
        void setHasRelic(bool trueOrFalse);
        bool getIsVisible();
        void setIsVisible(bool trueOrFalse);
        Relic* getRelic();
        void setRelic(Relic* relic);
        void setNorth(Space* n);
        void setEast(Space* e);
        void setSouth(Space* s);
        void setWest(Space* w);   
        Space* getNorth();
        Space* getEast();
        Space* getSouth();
        Space* getWest();   
        virtual void searchSpace(Explorer* spaceCraft) = 0;  
        virtual ~Space();           

};
#endif
