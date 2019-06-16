/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston 
 * Date:         June 1, 2019
 *
 * classRelic.cpp
 * Implementation file.
 * Relics are objects scattered throughout space for the player to collect.
 * They are worth points and help our understanding of the universe. 
 * ****************************************************************************/
#include "classRelic.hpp"  
#include <string>
#include <cstdlib>
Relic::Relic()
{
    //randomly assign the relic a name
    std::string rName;
    int randName = std::rand() % 9 + 1;
    
    if (randName == 1)
    {   rName = "Meteorite";    }
    else if (randName == 2)
    {   rName = "Alien-Tech";   }
    else if (randName == 3) 
    {   rName = "Dust";         } 
    else if (randName == 4)    
    {   rName = "Star-Diamond"; }
    else if (randName == 5)
    {   rName = "Gaseous-Cloud";} 
    else if (randName == 6)
    {   rName = "Apple-Pie";    }
    else if (randName == 7) 
    {   rName = "Golden-Record";}
    else if (randName == 8)
    {   rName = "Shiny-Dust";   }
    else
    {   rName = "Starstuff";    }       
      
    relicName = rName;
    points = (((std::rand() % 209) + 50)/10)*10;
}
int Relic::getPoints()
{
    return points;
}
std::string Relic::getRelicName()
{
    return relicName;
}
Relic::~Relic()
{ 
}

