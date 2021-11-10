#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define CITIES 10

int compString(char *string1, char *string2);

int main(void) {
  char cities[CITIES][100] = {"Vandal", "Dreg", "Captain", "Psion", "Cursed Thrall", "Screeb", "Acolyte", "Unstoppable Ogre", "Hobgoblin", "Undying mind"};
  char tempString[100];

  // is first string larger than second? (pos if yes, neg if no)
  for (int i = CITIES; i > 0; i--) {
    for (int j = 0; j < CITIES; j++) {
      // if first is bigger than second
      if (strcmp(cities[i], cities[j]) < 0) {
          strcpy(tempString, cities[j]);
          strcpy(cities[j], cities[i]);
          strcpy(cities[i], tempString);
      }
    }
  }
  for (int i = 0; i < CITIES; i++) {
    printf("\n%d. %s", i+1, cities[i]);
  }
  return 0;
}
