/*******************************************************************************
 * Program name: Project 2
 * Author:       Adriane Hairston
 * Date:         April 23, 2019 
 *
 * testInput.cpp
 * Provides input validation function for my programs.
 * ****************************************************************************/
#include "testInput.hpp"
#include <iostream>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl; 
/*******************************************************************************
 * Name: 	testInput 	
 * Called by:  	classZoo
 * Calls: 	None.
 * Passed: 	min , max integer value   
 * Returns: 	integer
 *
 * This function workds to validate integer input. The min and max values are 
 * tested and input containing non integers is rejected. The function returns 
 * an int value ready to be assigned.  
 ******************************************************************************/
int testInput(int min, int max)
{   
    int verifyNum;                // the number to be returned from the function
    std::string inString;         // string to hold user input
    char* ch_array;               // character array to analyze user input
    bool isValidInput = false;    // variable to flag to exit the input loop
    bool isInteger;               // flag variable 

    while (isValidInput == false)
    {   
        // get user input until \n, store it in string   
        std::getline(cin, inString);
        // dynamically create a char array the size of the string
        ch_array = new char[inString.length()];
        isInteger = true;  
        // isInteger is only set to false is a character is anything other than
        // 0-9, in which case, the loop starts over 
        for (int i = 0; i < (inString.length()); i++)
        { 
            // this loop assigns each character of the string to the char array
            // if it isn't a digit, an error message is printed.   
            ch_array[i] = inString[i];
            if (!isdigit(ch_array[i]))
            {   
                cout <<  ch_array[i];  
                isInteger = false; 
                cin.clear();
            }
        }
        if (isInteger == false)
        {
            cout << " is not a valid integer. Please try again." << endl;
        }   
        if (isInteger == true)
        {   
            // then the original string is essentially "cast" as a int
            // and tested within the max and min limits for valid input 
            std::stringstream checkBounds(inString);
            verifyNum = 0;
            checkBounds >> verifyNum;
            
            if (( verifyNum < min ) || (verifyNum > max))
            {
                cout << "Please enter a number between " << min
                     << " and " << max << "." << endl;
                cin.clear();
            }
            else
            {
                isValidInput = true;
            }
        }
        delete [] ch_array;    
    }
    return verifyNum;
} 







