#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calculateCharges();

int main() {
  srand(time(NULL));

  float car1, car2, car3, cost1, cost2, cost3, carTot, costTot;
  int input = 0, myNum;
  printf("Please enter how long car 1 has stayed : ");
  scanf("%f", &car1);
  cost1 = calculateCharges(car1);
  printf("Please enter how long car 2 has stayed : ");
  scanf("%f", &car2);
  cost2 = calculateCharges(car2);
  printf("Please enter how long car 3 has stayed : ");
  scanf("%f", &car3);
  cost3 = calculateCharges(car3);

  carTot = car1 + car2 + car3;
  costTot = cost1 + cost2 + cost3;

  printf("\nCar\tHours\tCharge\n1\t%.1f\t%.2f\n2\t%.1f\t%.2f\n3\t%.1f\t%.2f\n", car1, cost1, car2, cost2, car3, cost3);
  printf("TOTAL\t%.1f\t%.2f", carTot, costTot);

  myNum = rand() % 1000 + 1;

  printf("\n\nI have a number between 1 and 1,000.\nCan you guess my number?\nPlease type your first guess : ");
  scanf("%d", &input);
  while (input != myNum) {
    if (input < myNum) {
      printf("Too low try again : ");
      scanf("%d", &input);
    } else if (input > myNum) {
      printf("Too high try again : ");
      scanf("%d", &input);
    } else {
      printf("Please enter a valid number : ");
      scanf("%d", &input);
    }
  }

  printf("Congrats! You got it! The number was %d!", myNum);


  return 0;
}

float calculateCharges(float car) {
  if (car <= 3) {
    return 2.00;
  } else if (car >= 19) {
    return 10.00;
  } else {
    return ((car-3)/2)+2;
  }
}
