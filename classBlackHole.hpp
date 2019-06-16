/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston 
 * Date:         June 1, 2019
 *
 * classBlackHole.hpp
 * Declaration file. 
 * Black Hole is derived from the Space Class. It has a unique function to 
 * teleport the player's spaceship to a different random location. 
 * ****************************************************************************/
#ifndef CLASSBLACKHOLE_HPP
#define CLASSBLACKHOLE_HPP
#include "classSpace.hpp"
#include "classExplorer.hpp"
class BlackHole : public Space
{
    private: 
        Space* teleportTo;
    public:
        BlackHole(); 
        void setTeleportTo(Space* t); 
        virtual void searchSpace(Explorer* spaceCraft); 
        ~BlackHole();
      
};
#endif

