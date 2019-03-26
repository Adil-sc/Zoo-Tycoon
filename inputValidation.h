/*********************************************************************
** Author: Adil Chaudhry
** Date: Late December
** Description: Class specification file defining the inputValidation class
*********************************************************************/

#ifndef MENU_INPUTVALIDATION_H
#define MENU_INPUTVALIDATION_H

#include <string>

//Input validation for integers
void isValidInt(int &value, std::string message);

//Input validation for integers with a min and max range
void isValidIntRange(int &value, int min, int max, std::string message);

//Inout validation for doubles
void isValidDouble(double &value, std::string message);


#endif //MENU_INPUTVALIDATION_H
