#include <stdio.h>

int main() {
  int total = 0, input, count, answer, boolean = 0;
  double totald = 0;

  printf("Enter a number (enter 9999 to complete) : ");
  scanf("%d", &input);
  total += input;
  count = 1;
  while (input != 9999) {
    printf("Enter another number (enter 9999 to complete): ");
    scanf("%d", &input);
    total += input;
    count++;
  }
  answer = total/count;
  printf("The average of those numbers (including 9999) is %d", answer);

  total = 999999999;
  for (int i = 0; i <= 10; i++) {
    printf("\nPlease enter a number: ");
    scanf("%d", &input);
    if (input < total) {
      total = input;
    }
  }
  printf("The smallest of those numbers is : %d", total);

  printf("Hi, you should purchase something from me. now. or else.");

  totald = 0;
  while (boolean == 0) {
    printf("Your optiosn are as follows : \n1 for $2.98\n2 for $4.50\n3 for $9.98\n4 for $4.49\n5 for $6.87\n (or 6 for finish)\n");
    printf("Please say what number you'd like to purchase : ");
    scanf("%d", &input);
    switch (input) {
      case 1 :
        totald += 2.98;
        break;
      case 2 :
        totald += 4.5;
        break;
      case 3 :
        totald += 9.98;
        break;
      case 4 :
        totald += 4.49;
        break;
      case 5 :
        totald += 6.87;
        break;
      default :
        boolean = 1;
        break;
    }
  }
  printf("Your total is %lf", totald);

}
