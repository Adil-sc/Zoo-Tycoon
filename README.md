# Zoo Tycoon Game

Zoo tycoon is a game that allows players to run a zoo business. Different types of animals cost different prices, 
have different maintenance costs, and of course, return a different profit at the end of each day. For this game, 
the player will be the proud owner of a virtual zoo that has spaces to house tigers, penguins and turtles.

The Animal class has the following member variables:
```
Age
  Adult if age >= 3 days
  Baby if age < 3 days
  
Cost
  Tiger cost $10,000
  Penguin cost $1,000
  Turtle cost $100
  
Number of Babies
  Tigers have 1 baby
  Penguins have 5 babies
  Turtles have 10 babies
  
Base Food Cost
  Tigers have a feeding cost of 5 times the base cost
  Penguins have a feeding cost that is the same as the base cost
  Turtles have a feeding cost that is 50% the base cost
  
Payoff
  A tiger’s payoff per day is 20% of their cost per animal. (not counting bonus)
  A penguin’s payoff per day is 10% of their cost per animal
  A turtle’s payoff per day is 5% of their cost per animal
```

The player begins with a 100,000 dollars in the bank. At the start, the user needs to buy three types of animals (tigers, penguins, turtles) to start the business. Each type should have a quantity of either 1 or 2. For each animal bought, the cost is subtracted from the bank. All newly bought animals are 1 day old.

Each turn is a “day”. At the beginning of the day, all animals increase age by 1 day, and the user needs to pay the feeding cost of each animal. Feeding is required so the animals don’t die. After the feeding cost is subtracted from the bank, one randomized event takes place during the day.  You can determine how to implement the random functions by yourself.  The random function will pick one random event from the following list:

Random Events:
```
A sickness occurs to an animal in the zoo:
  Pick an animal at random that will die
  Remove one animal of that type from the exhibit. (dynamic array in the zoo)

A boom in zoo attendance occurs:
  Generate a random bonus between 250 and 500 dollars for each tiger in the zoo for the day 
  Add the bonus payoff for each tiger to the total payoff of the day as a reward

A baby animal is born:
  Pick an animal at random to have a baby
Check if there is an animal old enough to be a parent (age >= 3), add babies to the zoo depending on the “number of babies” specific to the type of animal. If no animal is old enough of the randomly selected type, pick another type of animal. Baby animals start at age 0.  For simplicity, you don’t need to consider the gender of the adult animals in order to have babies. One adult animal is good enough to have babies.

Nothing happens
```
## Installation and Usage
Compile the program with this command:
```
make FinalProject
```
Run with the following command:
```unix
./FinalProject
```

## Built With
c++

