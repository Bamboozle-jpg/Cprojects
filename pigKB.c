// K. Bachelor
// The Game of Pig
// 9/16/21

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int dieRollPerson();
int dieRoll();
int dieRollComp();

int main()
{
  // Seeds random
  srand(time(NULL));
  // Set up player score
  int total = 0;
  // Set max/goal here
  int goal = 100;
  // Computer total
  int compTotal = 0;
  printf("Hi, let's play pig, roll the die, do it now.\n");
  sleep(1);
  printf("Here's how to play : \n");
  sleep(2);
  printf("You and the computer take turns rolling the die\n");
  sleep(3);
  printf("On your turn, you roll the die as many times as you want\n");
  sleep(3);
  printf("When you decide to stop, you add the total to your overall score\n");
  sleep(3);
  printf("But if you roll a 1, it skips your turn.\n");
  sleep(2);
  printf("Computer follows the same rules. First to %d wins, good luck!\n\n", goal);
  sleep(3);
  // While game is still going
  while (total < goal && compTotal < goal)
  {
    // Player turn goes
    total += dieRollPerson();
    // Computer turn goes
    compTotal += dieRollComp(compTotal, goal);
    sleep(1);
    //prints total scores
    printf("\nYour current score is %d\nComputer's current score is %d\n\n", total, compTotal);
    sleep(1);
  }
  // Misses print statement if game ends, so putting it here
  printf("\nYour current score is %d\nComputer's current score is %d\n\n", total, compTotal);
  // Prints who won
  if (total > goal)
  {
    printf("Congratulations you did it!");
  }
  else
  {
    printf("oops, looks like the computer beat you!");
  }
  return 0;
}

// Person turn
int dieRollPerson()
{
  int current = 0;
  // Enums. Fuuuuuun.
  enum diecheck{STOP, CONTINUE};
  enum diecheck dieCheck;
  int die = 0;
  dieCheck = CONTINUE;
  // While it's still going keep the turn going
  while (dieCheck != STOP)
  {
    // Print score for current attempt and ask if they want to keep going or not
    printf("Your current score for this attempt is %d", current);
    printf("\nEnter 1 to roll the die, or 0 to stop this attempt : ");
    // Reads whether they want to continue or not
    scanf("%u", &dieCheck);
    if (dieCheck == STOP)
    {
      // Tells how much they've added and ends if they want to stop
      sleep(1);
      printf("\nCongrats! You've added %d to your score!\n\n", current);
      return current;
    }
    else if (dieCheck == CONTINUE)
    {
      // If they want to continue makes a die roll
      die = dieRoll();
      if (die == 1) {
        // If they rolled a 1, mocks them and ends turn
        sleep(1);
        printf("\nYOU FOOL!!! YOU ROLLED A ONE!! NEXT TIME DON'T BE SO GREEDY!\n\n");
        return 0;
      }
      else
      {
        // If they didn't roll a 1, adds roll to score
        current += die;
      }
    }
    else {
      // Just in case they don't know how to type
      printf("I'm sorry, that's not a valid number\n");
    }
  }
  return 0;
}

// Computer turn
int dieRollComp(int hundCheck, int goal)
{
  // Computer turn setup
  sleep(1);
  printf("COMPUTER TURN\n");
  // Randomly assigns number they'll go to
  int stop = (rand() % 10 + 10);
  int current = 0;
  int die;
  // Main computer turn cycle
  while (current < stop) {
    if (hundCheck + current >= goal) {
      printf("\nComputer finished their turn and added %d to their total\n", current);
      return current;
    }
    die = dieRoll();
    // If computer rolls a 1, end their turn
    if (die == 1) {
      sleep(1);
      printf("\nComputer went too far and rolled a 1\n");
      return 0;
    }
    else
    {
      // While they haven't reached said number, rolls die and adds it, and informs person
      current += die;
      sleep(1);
      printf("Current computer score for this attempt : %d\n", current);
    }
  }
  // If they reach their goal, ends the turn and adds it and informs player
  sleep(1);
  printf("\nComputer finished their turn and added %d to their total\n", current);
  return current;
}

// Rolls the die and returns roll
int dieRoll()
{
  int ret = 0;
  ret = rand() % 6 + 1;
  return ret;
}
