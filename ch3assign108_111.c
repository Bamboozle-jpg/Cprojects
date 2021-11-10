//pg 108 answers
#include <stdio.h>
#include <time.h>

int main() {
  time_t start,end;

  int t = 0;
  int input = 0;
  int decimal = 0;
  int tempStore = 0;
  int placeVal = 1;
  int count = 0;

  printf("3.28 prints *'s then '+'s and repeats both of these a combined total of 10 times (5 each)");
  printf("\n3.29 prints 10 <'s then 10 >'s repeatedly until both have each done 5 rows");
  printf("\n\nNow for decimal to binary, please enter a binary number up to 5 digits : ");
  scanf("%d", &input);


  while (input != 0 && (tempStore == 0 || tempStore == 1)) {
    tempStore = input % 10;
    if (tempStore == 1) {
      decimal += tempStore*placeVal;
      input -= 1;
      input /= 10;
    } else {
      input /= 10;
    }
    placeVal *= 2;
  }
  if (input == 0) {
    printf("\nThat value in decimal is : %d", decimal);
  } else {
    printf("Oops, there was a problem, please enter a number in binary");
  }

  printf("\n\nNow for the timing section! enter a random number to continue (num does not matter) ");
  scanf("%d", &input);

  start=clock();
  while (count < 1000000000) {
    count++;
    if (count % 100000000 == 0) {
      printf("Count = %d\n", count);
    }
  }
  end=clock();
  t=(end-start)/CLOCKS_PER_SEC;

  printf("\nWow, that took %d seconds!", t);

  return 0;
}
