/*********************************************************************
** Program Name: Project 2
** Author: Adil Chaudhry
** Date: 1/26/2019
** Description: Animal.cpp holds the class functions for the Animal class
*********************************************************************/

#include "Animal.h"

/*********************************************************************
** Constructors
*********************************************************************/

//The animal class outlines the member functions and methods that will help derive other animal types
Animal::Animal() {

}

//Use an initalizer list to setup protected member variables
Animal::Animal(int newAge, double newCost, int newNumOfBabbies, double newFoodCost, double newPayoff)
        : age(newAge), cost(newCost), numberOfBabies(newNumOfBabbies), baseFoodCost(newFoodCost), payoff(newPayoff) {


}


/*********************************************************************
** Getters
*********************************************************************/
int Animal::getAge() {
    return age;
}


double Animal::getCost() {
    return cost;
}


int Animal::getNumberOfBabies() {
    return numberOfBabies;
}


double Animal::getPayoff() {
    return payoff;
}


double Animal::getBaseFoodCost() {
    return baseFoodCost;
}


/*********************************************************************
** Setters
*********************************************************************/

void Animal::setAge(int newAge) {
    age = newAge;
}


void Animal::setCost(double newCost) {
    cost = newCost;
}


void Animal::setNumOfBabbies(int newNumBabies) {
    numberOfBabies = newNumBabies;
}


void Animal::setPayoff(double newPayoff) {
    payoff = newPayoff;
}


void Animal::setBaseFoodCost(double newFoodCost) {
    baseFoodCost = newFoodCost;
}
