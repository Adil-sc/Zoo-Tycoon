/*********************************************************************
** Program Name: Project 2
** Author: Adil Chaudhry
** Date: 1/26/2019
** Description: Animal.h is the class specification file for the Animal class
*********************************************************************/
#ifndef PROJECT2_ANIMAL_H
#define PROJECT2_ANIMAL_H

//Constant that helps define the base food cost for feeding the animals
const double BASE_FOOD_COST = 500;
class Animal {

protected:
    int age = 0;
    double cost = 0;
    int numberOfBabies = 0;
    double baseFoodCost = 0;
    double payoff = 0;



public:

    Animal();
    Animal(int newAge, double newCost, int newNumOfBabies, double newFoodCost, double newPayoff);

    virtual int getAge();
    virtual double getCost();
    virtual int getNumberOfBabies();
    virtual double getPayoff();
    virtual double getBaseFoodCost();

    virtual void setAge(int newAge);
    virtual void setCost(double newCost);
    virtual void setNumOfBabbies(int newNumBabies);
    virtual void setPayoff(double newPayoff);
    virtual void setBaseFoodCost(double newFoodCost);


};


#endif //PROJECT2_ANIMAL_H
