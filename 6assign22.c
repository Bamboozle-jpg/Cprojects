#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int takePerson();
int takeSale();
double takeMoney();

int main() {
  float arr[4][5] = {0};
  int person = 0;
  int product = 0;
  double total = 0;
  double totalProduct = 0;
  double totalPerson = 0;

  person = takePerson();
  while (person != 0) {
    product = takeSale();
    total = 0;
    arr[0][0] = 0;
    total = takeMoney(product);
    arr[person - 1][product - 1] += total;
    person = takePerson();
  }
  //take saleperson take what they sold, how much they made
  //organize it and display the total with salesperson as 1 axis, and product as another and the actual amount made in between
  printf("\t\tPerson1\tPerson2\tPerson3\tPerson4\tTotal");
  for (int j = 0; j < 5; j++) {
    printf("\nProduct%d\t", j+1);
    for (int i = 0; i < 4; i++) {
      printf("%2.2f\t", arr[i][j]);
      totalProduct += arr[i][j];
    }
    printf("%2.2f", totalProduct);
    totalProduct = 0;
  }

  printf("\nTotal\t");

  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 5; i++) {
      totalPerson += arr[j][i];
    }
    printf("\t%2.2f", totalPerson);
    totalPerson = 0;
  }

  return 0;
}

int takePerson() {
  int input = 0;
  printf("\nPlease enter which salesperson you'd like to see (or hit 0 to exit) : ");
  scanf("%d", &input);
  return input;
}

int takeSale() {
  int input = 0;
  printf("\nPlease enter which product you'd like to buy : ");
  scanf("%d", &input);
  return input;
}

double takeMoney(int caze) {
  double gamer = 0;
  int input = 0;
  switch (caze) {
    case 1 :
      gamer = 1.55;
      break;
    case 2 :
      gamer = 2.70;
      break;
    case 3 :
      gamer = 3.35;
      break;
    case 4 :
      gamer = 0.65;
      break;
    case 5 :
      gamer = 5.25;
      break;
    default :
      gamer = 0;
      break;
  }
    printf("\nPlease enter how many you'd like to buy : ");
    scanf("%d", &input);
    gamer = gamer*input;
    return gamer;
}
