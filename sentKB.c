#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
  //Sets up list of words
  char a1[] = "the", a2[] = "a", a3[] = "one", a4[] = "some", a5[] = "any";
  char n1[] = "boy", n2[] = "girl", n3[] = "dog", n4[] = "town", n5[] = "car";
  char v1[] = "drove", v2[] = "jumped", v3[] = "ran", v4[] = "walked", v5[] = "skipped";
  char p1[] = "to", p2[] = "from", p3[] = "over", p4[] = "under", p5[] = "on";

  //organizes words into arrays
  char* article[] = {a1, a2, a3, a4, a5};
  char* noun[] = {n1, n2, n3, n4, n5};
  char* verb[] = {v1, v2, v3, v4, v5};
  char* prep[] = {p1, p2, p3, p4, p5};

  //Seeds rand with time
  srand(time(NULL));

  //Capitalization checking
  char capCheck[10];

  //Loop 20 times, 1 per sentence
  for (int i = 0; i < 20; i++) {
    strcpy(capCheck, article[rand()%5]);
    capCheck[0] = toupper(capCheck[0]);
    printf("%s %s %s %s %s %s.\n", capCheck, noun[rand()%5], verb[rand()%5], prep[rand()%5], article[rand()%5], noun[rand()%5]);
  }

  return 0;
}
