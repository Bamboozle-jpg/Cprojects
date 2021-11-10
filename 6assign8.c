#include <stdio.h>

int main() {
  int scores[9] = {0,1,2,3,4,5,6,7,8};
  printf("scores[6] or the 7th element is %d\n", scores[6]);
  float waves[6] = {0};
  printf("Give number to add to waves pls : ");
  scanf("%f", &waves[3]);
  int gross[5] = {0,1,2,3,4};
  printf("\nhi %d", gross[4]);
  float arr[20];
  float total = 0;
  for (size_t i = 0; i <= 19; i++) {
    arr[i] = 1;
    total += arr[i];
  }
  printf("\n\ntotal is %f", total);
  return 0;
}
