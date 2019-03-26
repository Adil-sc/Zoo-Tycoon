/*********************************************************************
** Program Name: Project 2
** Author: Adil Chaudhry
** Date: 1/26/2019
** Description: Zoo.h is the class specification file for the Zoo class
*********************************************************************/
#ifndef PROJECT2_ZOO_H
#define PROJECT2_ZOO_H

#include "inputValidation.h"
#include "Animal.h"
#include "Tiger.h"
#include "Penguin.h"
#include "Turtle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>






using std::cin;
using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;
using std::memcpy;

//Zoo class is where the majority of the Zoo simulation occurs. It helps outline methods like showing the menu, feeding the animals, aging them, and playing the simulation
class Zoo {

private:

    int currentDay = 0;
    double bankBalance = 0;
    double zooBoomPayoff = 0;
    double newProfit = 0;
    double foodCost = 0;

    //Bonus feed variable
    double bonusFeedModifier = 0;
    string bonusFeedModifierType();
    void bonusFeed();
    void bonusReadRandomEventFromFile();
    void bonusWriteRandomEventToFile(string s);


    Tiger *tigerArray;
    int tigerArraySize = 10;
    int numberOfTigers = 0;
    int numberOfTigersBought = 0;

    Penguin *penguinArray;
    int penguinArraySize = 10;
    int numberOfPenguins = 0;
    int numberOfPenguinsBought = 0;


    Turtle *turtleArray;
    int turtleArraySize = 10;
    int numberOfTurtles = 0;
    int numberOfTurtlesBought = 0;




public:

    Zoo();
    ~Zoo();
    void zooMenu();
    void zooStart();


    void addTurtle(int turtles_bought);
    void addTiger(int tigers_bought);
    void addPenguin(int penguins_bought);

    void resizeTigerArray();
    void resizePenguinArray();
    void resizeTurtleArray();

    void ageAnimals();
    void feedAnimals();
    void randomEventSickness();
    void randomEventBirth();
    void randomEventBoomAttendance();
    void profitCalculation();
    void randomEventOccurs();

    int getBankBalance();
    int getNumberOfTurtles();
    int getNumberOfPenguins();
    int getNumberOfTigers();

    void setNumerOfTigers(int numberOfTigers);
    void setNumberOfPenguins(int numberOfPenguins);
    void setNumberOfTurtles(int numberOfTurtles);


    void setBankBalance(double bankBalance);


};


#endif //PROJECT2_ZOO_H
