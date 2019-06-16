/*******************************************************************************
 * Program name: Final Project
 * Author:       Adriane Hairston
 * Date:         June 2, 2019
 *
 * classAsteroidField.hpp
 * Declaration file.
 * Derived from the Space class. The Asteroid Belt may have a relic, or it may
 * cause you to loose a relic if an asteroid hits your ship. It takes more fuel
 * to cross an asteroid field because of the movement around each rock. 
 * ****************************************************************************/
#ifndef CLASSASTEROIDFIELD_HPP
#define CLASSASTEROIDFIELD_HPP
#include "classSpace.hpp"
#include "classExplorer.hpp"
class AsteroidField : public Space
{
    public: 
        AsteroidField();
        virtual void searchSpace(Explorer* spaceCraft);
        void dodgeAsteroids(Explorer* shuttle);
        ~AsteroidField();

};
#endif
