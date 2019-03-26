/*********************************************************************
** Program Name: Project 2
** Author: Adil Chaudhry
** Date: 1/26/2019
** Description: Zoo.cpp holds the class functions for the Zoo class
*********************************************************************/

#include "Zoo.h"


/*********************************************************************
** Zoo Constructor
*********************************************************************/
Zoo::Zoo() {

    //Sets current day to 1
    currentDay = 1;
    //Sets the bank balance to $100,000
    bankBalance = 100000;

    //Tigers dynamic array
    tigerArray = new Tiger[tigerArraySize];

    //Pengin dynamic array
    penguinArray = new Penguin[penguinArraySize];

    //Turtle dynamic array
    turtleArray = new Turtle[turtleArraySize];


}

/*********************************************************************
** Destructor, deallocates memmory for the tiger, penguin, and turtle objects
*********************************************************************/
Zoo::~Zoo() {

    delete[] tigerArray;
    delete[] penguinArray;
    delete[] turtleArray;


}


/*********************************************************************
** Starts the simulation, the majority of the simulation occurs here
*********************************************************************/
void Zoo::zooStart() {

    cout << "---------------------------------------------------------------------------------------------"
         << std::endl;
    cout << "                               ** Welcome to the Zoo game **                                  "
         << std::endl;
    cout << "---------------------------------------------------------------------------------------------"
         << std::endl;
    cout << "Bonus Extra Credit Implemented:" << std::endl;
    cout << "1. Status messages: All random events are written and read from a file called RandomEvent.txt"
         << std::endl;
    cout << "2. Different Feed Types: User is able to select different feed types" << std::endl;
    cout << "---------------------------------------------------------------------------------------------"
         << std::endl;
    cout << " " << std::endl;


    //Variable to track if the user has quit the simulation
    bool quitZoo = false;
    //Variable to track the users choice of quitting or playing the game
    int quitZooAnswer = 0;
    //Variable to track if the choice of the user wanting to purchase an adult animal at the end of the day
    int buyAdultAnimalChoice = 0;

    //While loop that runs whole the game has not been quit AND the user has not run out of money
    while (quitZoo == false && bankBalance >= 0) {

        cout << "You have $" << bankBalance << " in the bank" << std::endl;
        cout << "The Zoo has been open for " << currentDay << " day(s)" << std::endl;

        //Function that calls the Zoo menu
        zooMenu();
        //Function that ages the animals
        ageAnimals();
        //Function that aks the user to select a feed type (Bonus)
        bonusFeed();
        //Function that handles calculating the feeding costs for the animals
        feedAnimals();
        //Function that decides on a random event to occur
        randomEventOccurs();



        //Profit calculation and summary happens here
        cout << "--------------------------------------------------" << std::endl;
        cout << "|             Zoo Inventory Summary              |" << std::endl;
        cout << "--------------------------------------------------" << std::endl;
        cout << "Number of tigers:" << numberOfTigers << std::endl;
        cout << "Profit from tigers:" << numberOfTigers * tigerArray->getPayoff() << std::endl;

        cout << "Number of penguins:" << numberOfPenguins << std::endl;
        cout << "Profit from penguins:" << numberOfPenguins * penguinArray->getPayoff() << std::endl;

        cout << "Number of turtles:" << numberOfTurtles << std::endl;
        cout << "Profit from turtles:" << numberOfTurtles * turtleArray->getPayoff() << std::endl;
        cout << " " << std::endl;
        cout << "Food cost for the Zoo: " << foodCost << ", Feed Type: " << bonusFeedModifierType() << std::endl;

        //Function that calcualts and displays the profit for the end of day
        profitCalculation();
        //If the bank balance is less than 0, the game ends
        if (bankBalance < 0) {
            cout << "Out of funds. The game is over" << std::endl;
            quitZoo = true;
            return;
        }

        //Asks the user if they want to buy an adult animal at the end of the day
        cout << "Would you like to buy an Adult animal?" << std::endl;
        cout << "1. Yes" << std::endl;
        cout << "2. No" << std::endl;
        cin >> buyAdultAnimalChoice;
        isValidIntRange(buyAdultAnimalChoice, 1, 2, "");

        switch (buyAdultAnimalChoice) {
            case 1:

                cout << "Which Animal would you like to buy?" << std::endl;
                cout << "1. Tiger" << std::endl;
                cout << "2. Penguin" << std::endl;
                cout << "3. Turtle" << std::endl;
                cin >> buyAdultAnimalChoice;
                isValidIntRange(buyAdultAnimalChoice, 1, 3, "");
                switch (buyAdultAnimalChoice) {
                    case 1:
                        numberOfTigers++;
                        resizeTigerArray();
                        tigerArray[numberOfTigers].setAge(3);
                        bankBalance -= tigerArray->getCost();
                        if (bankBalance < 0) {
                            cout << "Out of funds. The game is over" << std::endl;
                            quitZoo = true;
                            return;
                        }

                        break;

                    case 2:
                        numberOfPenguins++;
                        resizePenguinArray();
                        penguinArray[numberOfPenguins].setAge(3);
                        bankBalance -= penguinArray->getCost();
                        if (bankBalance < 0) {
                            cout << "Out of funds. The game is over" << std::endl;
                            quitZoo = true;
                            return;
                        }
                        break;

                    case 3:
                        numberOfTurtles++;
                        resizeTurtleArray();
                        turtleArray[numberOfTurtles].setAge(3);
                        bankBalance -= turtleArray->getCost();
                        if (bankBalance < 0) {
                            cout << "Out of funds. The game is over" << std::endl;
                            quitZoo = true;
                            return;
                        }
                        break;
                }

                break;

            case 2:
                break;
        }

        //Asks the user if they want to keep playing once the day is over
        cout << "Do you want to keep playing?" << std::endl;
        cout << "1. Yes" << std::endl;
        cout << "2. No, quit game" << std::endl;
        cin >> quitZooAnswer;
        isValidIntRange(quitZooAnswer, 1, 2, "");
        switch (quitZooAnswer) {
            case 1:
                quitZoo = false;
                break;

            case 2:
                quitZoo = true;
                break;

        }
        currentDay++;
    }


}

/*********************************************************************
** Displays the initial menu asking users to buy animals
*********************************************************************/
void Zoo::zooMenu() {

    cout << "How many Tigers do you want to buy [choose 1 to 2] [cost:$10,000]" << std::endl;
    cin >> numberOfTigersBought;
    isValidIntRange(numberOfTigersBought, 1, 2, "How many Tigers do you want to buy [choose 1 or 2] [cost:$10,000]");
//function to add tigers bought to array
    addTiger(numberOfTigersBought);

    cout << "How many Penguins do you want to buy [choose 1 to 2] [cost:$1000]" << std::endl;
    cin >> numberOfPenguinsBought;
    isValidIntRange(numberOfPenguinsBought, 1, 2, "How many Penguins do you want to buy [choose 1 to 2] [cost:$1000]");
    //function to add penguiins bought to array
    addPenguin(numberOfPenguinsBought);

    cout << "How many Tutrles do you want to buy [choose 1 to 2] [cost:$100]" << std::endl;
    cin >> numberOfTurtlesBought;
    isValidIntRange(numberOfTurtlesBought, 1, 2, "\"How many Tutrles do you want to buy [choose 1 to 2] [cost:$100]");
    //function to add tutrles bought to array
    addTurtle(numberOfTurtlesBought);


}


/*********************************************************************
** Function that deals with aging the animals
*********************************************************************/
void Zoo::ageAnimals() {


    //Age tiger
    for (int i = 0; i < numberOfTigers; i++) {

        tigerArray[i].setAge(tigerArray[i].getAge() + 1);

    }

    //Age Penguines
    for (int i = 0; i < numberOfPenguins; i++) {

        penguinArray[i].setAge(penguinArray[i].getAge() + 1);


    }

    //Age for Turtles
    for (int i = 0; i < numberOfTurtles; i++) {
        turtleArray[i].setAge(turtleArray[i].getAge() + 1);
    }


}


/*********************************************************************
** Function that deals with calculating the feed cost for each animal and subtracting it from the bank balance
*********************************************************************/
void Zoo::feedAnimals() {


    //If the number of tigers in the zoo are greater than 0, feed them.

    if (numberOfTigers > 0) {
        foodCost += (tigerArray->getBaseFoodCost() * bonusFeedModifier) * numberOfTigers;
    }

    if (numberOfPenguins > 0) {
        foodCost += (penguinArray->getBaseFoodCost() * bonusFeedModifier) * numberOfPenguins;
    }

    if (numberOfTurtles > 0) {
        foodCost += (turtleArray->getBaseFoodCost() * bonusFeedModifier) * numberOfTurtles;
    }

    // cout<<"Food cost for the zoo: "<<foodCost<<std::endl;
    bankBalance -= foodCost;

}


/*********************************************************************
** Bonus Function that allows a user to select a varifty of feed choices
*********************************************************************/
void Zoo::bonusFeed() {

    int feedSelection = 0;
    cout << "Select the quality of Feed you want to give to your animals" << std::endl;
    cout << "1. Cheap" << std::endl;
    cout << "2. Generic" << std::endl;
    cout << "3. Premium" << std::endl;
    cin >> feedSelection;
    isValidIntRange(feedSelection, 1, 3, "");
    switch (feedSelection) {
        case 1:
            //Sets food cost to be half the base food cost
            bonusFeedModifier = 0.5;
            break;

        case 2:
            //Sets food cost to be the normal base food cost
            bonusFeedModifier = 1;
            break;

        case 3:
            //Sets the food cost to be twice as expensive as the base food cost
            bonusFeedModifier = 2;
            break;
    }


}


/*********************************************************************
** Function that returns the current selected Feed varity
*********************************************************************/
string Zoo::bonusFeedModifierType() {
    string st;
    if (bonusFeedModifier == 0.5) {
        st = "Cheap";

    } else if (bonusFeedModifier == 1) {
        st = "Generic";

    } else if (bonusFeedModifier == 2) {
        st = "Premium";

    }
    return st;
}


/*********************************************************************
** addTiger, addPenguin, addTurtle functions deal with addign new animals to the Zoo and resizing the array accordingly
*********************************************************************/
//Adds the number of tigers bought to the numberOfTigers variable to keep track of them. Then subtracts the current bank balance by the cost of the tigers purchased.
void Zoo::addTiger(int tigers_bought) {

    setNumerOfTigers(getNumberOfTigers() + tigers_bought);

    resizeTigerArray();

    bankBalance -= tigerArray->getCost() * tigers_bought;

}


//Adds the number of penguins bought to the numberOfPenguins variable to keep track of them. Then subtracts the current bank balance by the cost of the penguins purchased.
void Zoo::addPenguin(int penguins_bought) {
    setNumberOfPenguins(getNumberOfPenguins() + penguins_bought);
    resizePenguinArray();
    bankBalance -= penguinArray->getCost() * penguins_bought;
}


//Adds the number of turtles bought to the numberOfTurtles variable to keep track of them. Then subtracts the current bank balance by the cost of the turtles purchased.
void Zoo::addTurtle(int turtles_bought) {
    setNumberOfTurtles(getNumberOfTurtles() + turtles_bought);

    resizeTurtleArray();

    bankBalance -= turtleArray->getCost() * turtles_bought;
}


/*********************************************************************
** Function to resize Tiger Array
*********************************************************************/
void Zoo::resizeTigerArray() {

    if (getNumberOfTigers() > (tigerArraySize - 1)) {
        //Make temp array to hold new array
        Tiger *tempArray = new Tiger[2 * tigerArraySize];
        memcpy(tempArray, tigerArray, tigerArraySize * 2);
        delete[]tigerArray;
        tigerArraySize *= 2;
        tigerArray = tempArray;
    }

}


/*********************************************************************
** Function to resize Penguin Array
*********************************************************************/
void Zoo::resizePenguinArray() {


    if (getNumberOfPenguins() > (penguinArraySize - 1)) {
        //Make temp array to hold new array
        Penguin *tempArray = new Penguin[2 * penguinArraySize];
        memcpy(tempArray, penguinArray, penguinArraySize * 2);
        delete[]penguinArray;
        penguinArraySize *= 2;
        penguinArray = tempArray;
    }


}


/*********************************************************************
** Function to resize Turtle Array
*********************************************************************/
void Zoo::resizeTurtleArray() {

    if (getNumberOfTurtles() > (turtleArraySize - 1)) {
        //Make temp array to hold new array
        Turtle *tempArray = new Turtle[2 * turtleArraySize];
        std::memcpy(tempArray, turtleArray, turtleArraySize * 2);
        delete[]turtleArray;
        turtleArraySize *= 2;
        turtleArray = tempArray;
    }

}


/*********************************************************************
** Function that generats a random event in which one animal gets sick
*********************************************************************/
void Zoo::randomEventSickness() {



    //Randomly select a value from 1-3, which represetns the 3 animals we have.
    int randomAnimalToKill = rand() % 3 + 1;

    switch (randomAnimalToKill) {

        case 1:
//Find the last element in the tiger array, and set its age to 0;
            tigerArray[numberOfTigers - 1].setAge(0);
            numberOfTigers--;
            bonusWriteRandomEventToFile("Oh dear! One of your tigers has gotten sick and has died");
            bonusReadRandomEventFromFile();
            break;

        case 2:
            penguinArray[numberOfPenguins - 1].setAge(0);
            numberOfPenguins--;
            bonusWriteRandomEventToFile("Oh dear! One of your penguins has gotten sick and has died");
            bonusReadRandomEventFromFile();
            break;

        case 3:
            turtleArray[numberOfTurtles - 1].setAge(0);
            numberOfTurtles--;
            bonusWriteRandomEventToFile("Oh dear! One of your turtles has gotten sick and has died");
            bonusReadRandomEventFromFile();
            break;
    }


}


/*********************************************************************
** Function that generates a random event in which the Zoo experiences a boom
*********************************************************************/
void Zoo::randomEventBoomAttendance() {

    double randomBonus = rand() % 500 + 250;

    for (int i = 0; i < numberOfTigers; i++) {

        zooBoomPayoff += randomBonus;

    }

    bonusWriteRandomEventToFile(
            "Attendance boom at the Zoo! Each tiger gets a bonus of $" + std::to_string(randomBonus) + "\n" +
            "You've earned an additional $" + std::to_string(zooBoomPayoff) + " dollars");
    bonusReadRandomEventFromFile();
    bankBalance += zooBoomPayoff;


}


/*********************************************************************
** Function that generates a random event in which a new animal is born
*********************************************************************/
void Zoo::randomEventBirth() {

    int randomAnimalIsBorn = rand() % 3 + 1;
    bool animalIsAdult = false;
    int counter = 0;

    switch (randomAnimalIsBorn) {

        case 1:

            while ((animalIsAdult == false && counter < numberOfTigers)) {

                //Check if the animal is over the age of 3, if so, add it to the Zoo
                if (tigerArray[0].getAge() >= 3) {
                    addTiger(tigerArray->getNumberOfBabies());
                    bonusWriteRandomEventToFile("A baby Tiger was born!");
                    bonusReadRandomEventFromFile();
                    animalIsAdult = true;
                }


                counter++;
            }
            break;


        case 2:
            while (animalIsAdult == false && counter < numberOfPenguins) {


                if (penguinArray[0].getAge() >= 3) {
                    addPenguin(penguinArray->getNumberOfBabies());
                    bonusWriteRandomEventToFile("5 baby Penguins were born!");
                    bonusReadRandomEventFromFile();
                    animalIsAdult = true;
                }


                counter++;
            }

            break;
        case 3:
            while (animalIsAdult == false && counter < numberOfTurtles) {


                if (turtleArray[0].getAge() >= 3) {
                    addTurtle(turtleArray->getNumberOfBabies());
                    bonusWriteRandomEventToFile("10 baby Turtles were born!");
                    bonusReadRandomEventFromFile();
                    animalIsAdult = true;
                }


                counter++;
            }
            break;

        default:
            cout << "No animal old enough to give birth" << std::endl;
            break;

    }


    if (animalIsAdult == false) {
        // cout << "No animals old enough to give birth" << std::endl;
        bonusWriteRandomEventToFile("No animals old enough to give birth");
        bonusReadRandomEventFromFile();
    }


}


/*********************************************************************
** Function that randomly determins which event will occur
*********************************************************************/
void Zoo::randomEventOccurs() {

    //Random seed
    srand((time(0)));

    //Randomly select a random event to conduct
    int randomEventArray[4] = {1, 2, 3, 4};
    int randIndex = rand() % 4;
    int randomEvent = randomEventArray[randIndex];

    //Sickness twice as likely to occur. Original chance of sickness occuring is 25%, now it will be 50%
    if (bonusFeedModifier == 0.5) {
        int randomEventArray[6] = {1, 1, 1, 2, 3, 4};
        int randIndex = rand() % 6;
        int randomEvent = randomEventArray[randIndex];
    }

    //Sickness half as likely to occur. Originally chance of sickness occuring is 25%, now it will be 12.5%. Slight increase in the chance of nothing happening is one drawback here
    if (bonusFeedModifier == 2) {
        int randomEventArray[8] = {1, 2, 2, 3, 3, 4, 4, 4};
        int randIndex = rand() % 8;
        int randomEvent = randomEventArray[randIndex];
    }


    switch (randomEvent) {

        case 1:
            cout << "--------------------------------------------------" << std::endl;
            cout << "|          Random event: SICKNESS OCCURS         |" << std::endl;
            cout << "--------------------------------------------------" << std::endl;
            randomEventSickness();
            break;

        case 2:
            cout << "--------------------------------------------------" << std::endl;
            cout << "|      Random event: BOOM IN ZOO ATTENDENCE      |" << std::endl;
            cout << "--------------------------------------------------" << std::endl;
            randomEventBoomAttendance();
            break;

        case 3:
            cout << "--------------------------------------------------" << std::endl;
            cout << "|          Random event: BABY IS BORN            |" << std::endl;
            cout << "--------------------------------------------------" << std::endl;
            randomEventBirth();
            break;

        case 4:
            cout << "--------------------------------------------------" << std::endl;
            cout << "|                Random event: NONE              |" << std::endl;
            cout << "--------------------------------------------------" << std::endl;
            bonusWriteRandomEventToFile(" ");
            bonusReadRandomEventFromFile();
            break;

    }


}


/*********************************************************************
** Function that calculates and summarizes the profit at the end of the day
*********************************************************************/
void Zoo::profitCalculation() {

    newProfit = (numberOfTigers * tigerArray->getPayoff() + numberOfPenguins * penguinArray->getPayoff() +
                 numberOfTurtles * turtleArray->getPayoff());
    double endOfDayBalance = bankBalance + newProfit;

    cout << "--------------------------------------------------" << std::endl;
    cout << "|           END OF DAY PROFIT SUMMARY            |" << std::endl;
    cout << "--------------------------------------------------" << std::endl;
    cout << "Total profit at end of day: " << newProfit + zooBoomPayoff << std::endl;
    cout << "Balance before new profit:" << bankBalance << std::endl;
    cout << "Balance with new profit: " << endOfDayBalance << std::endl;
    cout << " " << std::endl;
    bankBalance = endOfDayBalance;
    zooBoomPayoff = 0;

}


/*********************************************************************
** Function that deals with writing the random event to a file
*********************************************************************/
void Zoo::bonusWriteRandomEventToFile(string s) {

    ofstream outf("RandomEvent.txt", std::ios::trunc);
    if (!outf) {
        cout << "Unable to open or find RandomEvent.txt" << std::endl;
        return;
    }

    outf << s << std::endl;
    outf.close();

}


/*********************************************************************
** Function that deals with reading the random event from a file
*********************************************************************/
void Zoo::bonusReadRandomEventFromFile() {
    ifstream inf("RandomEvent.txt");

    if (!inf) {
        cout << "Could not open or read file RandomEvent.txt" << std::endl;
        return;
    }

    while (inf) {
        string strInput;
        getline(inf, strInput);
        cout << strInput << std::endl;
    }
    inf.close();

}


/*********************************************************************
** Setters
*********************************************************************/
void Zoo::setNumerOfTigers(int numberOfTigers) {
    this->numberOfTigers = numberOfTigers;
}


void Zoo::setNumberOfPenguins(int numberOfPenguins) {
    this->numberOfPenguins = numberOfPenguins;
}


void Zoo::setNumberOfTurtles(int numberOfTurtles) {
    this->numberOfTurtles = numberOfTurtles;
}


void Zoo::setBankBalance(double bankBalance) {
    this->bankBalance = bankBalance;
}


/*********************************************************************
** Getters
*********************************************************************/
int Zoo::getNumberOfTigers() {
    return numberOfTigers;
}


int Zoo::getNumberOfPenguins() {
    return numberOfPenguins;
}


int Zoo::getNumberOfTurtles() {
    return numberOfTurtles;
}


int Zoo::getBankBalance() {
    return bankBalance;
}
