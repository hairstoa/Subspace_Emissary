/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston 
 * Date:         June 1, 2019
 *
 * classRelic.hpp
 * Declaration file.
 * Relics are objects scattered throughout space for the player to collect.
 * They are worth points and help our understanding of the universe. 
 * ****************************************************************************/
#ifndef CLASSRELIC_HPP
#define CLASSRELIC_HPP
#include <string>
class Relic
{
    private:
        std::string relicName;
        int points;

    public:
        Relic();
        int getPoints();
        std::string getRelicName();
        ~Relic();  
};
#endif
