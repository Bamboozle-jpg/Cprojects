#include <stdio.h>

int main() {
  int max, min, count;
  double sales[] = {100, 1200, 2400, 2400, 3000, 9000, 4200, 200, 1500, 8500, 3300, 10000, 1000, 2200};
  double saleCosts[14];
  for (int i = 0; i <= 13; i++) {
    saleCosts[i] = 200 + (sales[i]*0.09);
  }
  for (int i = 0; i <= 7; i++) {
    count = 0;
    max = 200 + 100*i;
    min = 299 + 100*i;
    for (int i = 0; i <= 13; i++) {
      if (saleCosts[i] >= max) {
        if (saleCosts[i] >= min) {
          count++;
        }
      }
    }
    printf("$%d-%d\t%d\n", min, max, count);
  }
  count = 0;
  min = 1000;
  for (int i = 0; i <= 13; i++) {
    if (saleCosts[i] >= min) {
      count++;
    }
  }
  printf("$1000\t\t%d", count);
}
