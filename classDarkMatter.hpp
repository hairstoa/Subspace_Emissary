/*******************************************************************************
 * Program name: Final Project 
 * Author:       Adriane Hairston
 * Date:         June 1, 2019
 *
 * classDarkMatter.hpp
 * Declaration file.
 * This is a class derived from Space. The Dark Matter represents an area of 
 * space that doesn't have much in it that is larger than particles. There is 
 * a small chance of finding a relic here. 
 * ****************************************************************************/
#ifndef CLASSDARKMATTER_HPP
#define CLASSDARKMATTER_HPP
#include "classSpace.hpp"
#include "classExplorer.hpp"
class DarkMatter : public Space
{
    public:
    DarkMatter(); 
    virtual void searchSpace(Explorer* spaceCraft); 
    ~DarkMatter();
      
};
#endif
