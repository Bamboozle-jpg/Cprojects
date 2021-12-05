#include <stdio.h>
#include <math.h>

int ComputeFactorial(int number);
double ComputeSeriesValue(double x, int n);


int ComputeFactorial(int number) {
  int fact = 0;

  for (int j = 1; j <= number; j++) {
    fact = fact * j;
  }

  return fact;
}

double ComputeSeriesValue(double x, int n) {
  double seriesValue = 0.0;
  double xpow = 1;

  for (int k = 0; k <= n; k++) {
    seriesValue += xpow / ComputeFactorial(k);
    xpow = xpow * x;
  }

  return seriesValue;
}

int main() {
  printf("This program is used to compute the value of the following series : \n");

  printf("(x^0)/0! + (x^1)/1! + (x^2)/2! + (x^3)/3! + (x^4)/4! + ........ + (x^n)/n! \n");

  printf("Please enter the value of x : ");

  double x;
  scanf("%f", x);

  int n;
  printf("\nPlease enter an integer value for n : ");
  scanf("%d", n);
  printf("\n");

  double seriesValue = ComputeSeriesValue(x, n);
  printf("The value of the series for the values entered is ");
  printf("%f\n", seriesValue);
}
