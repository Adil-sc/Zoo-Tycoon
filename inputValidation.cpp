/*********************************************************************
** Author: Adil Chaudhry
** Date: Late December
** Description: Outlines the class functions for the inputValidation class
*********************************************************************/

#include <string>
#include <iostream>
#include "inputValidation.h"

using namespace std;

/*********************************************************************
** Description: Validation for ints
*********************************************************************/
void isValidInt(int &value, std::string message) {


    while ( cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n')) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Validation Error. Please Try Again: " << message << std::endl;
        cin >> value;
    }

}


void isValidIntRange(int &value, int min, int max, std::string message) {

    while ( cin.fail() || (value < min || value > max )|| (cin.peek() != '\r' && cin.peek() != '\n')) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Validation Error. Please Try Again: " << message << std::endl;
        cin >> value;

    }


}


/*********************************************************************
** Description: Validation for doubles
*********************************************************************/
void isValidDouble(double &value, std::string message) {

    while ( cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n')) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Validation Error. Please Try Again: " << message << std::endl;
        cin >> value;
    }

}