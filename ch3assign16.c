#include <stdio.h>

int main() {

  float totGal = 0;
  float totMile = 0;
  float totAv = 0;
  float galls;
  float miles;
  float avg;

  printf("Enter the gallons used (-1 to end): ");
  scanf("%f", &galls);
  while (galls != -1) {
      printf("Enter the miles driven: ");
      scanf("%f", &miles);

      totGal += galls;
      totMile += miles;
      avg = miles/galls;
      printf("This tank has given %f miles per gallon.", avg);

      printf("\n\nEnter the gallons used (-1 to end): ");
      scanf("%f", &galls);
  }
  totAv = totMile/totGal;
  printf("Your average miles per gallon is %f", totAv);

}
