/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 3, 2019
 *
 * classExplorer.hpp
 * Declaration File.
 * Explorer is the space ship that the commander oversees. It has a tank for 
 * fuel and a capsule for holding Relics.
 * ****************************************************************************/
#ifndef CLASSEXPLORER_HPP
#define CLASSEXPLORER_HPP
#include "classRelic.hpp"
#include <queue>
#include <string>

class Space; // forward declaration

class Explorer
{
   private:
       int fuel;
       int score;
       int habitats;
       int alliances;   
       std::queue <Relic*> capsule; 
       std::string commanderName;
       Space* location;  

   public:
       Explorer(std::string cName);
       int getFuel();
       void setFuel(int f);
       int getScore();
       void setScore(int s); 
       int getHabitats();
       void setHabitats(int h);  
       int getAlliances();
       void setAlliances(int a);     
       std::string getCdrName();
       void setLocation(Space* place);
       Space* getLocation();
       void addRelic(Relic* rlc);
       bool removeRelic();
       void printRelics();
       int getRelicPoints();
       int getRelicCount(); 
       void useRadar(); 
       ~Explorer(); 
};
#endif
