#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int vowelCount(char s1[]);
int constCount(char s1[]);
char *toLower(char s1[]);
char *toUpper(char s1[]);

int main(void) {
  char s1[101];
  printf("pls gib strimg : ");
  scanf("%[^\n]101s", s1);
  char caseCheck = 'm';
  int charCount;
  int i = 0;
  printf("\n\nA)  Count the number of vowels in the string\nB)  Count the number of consonants in the string\nC)  Convert the string to uppercase\nD)  Convert the string to lowercase\nE)  Display the current string\nF)  Enter another string\n\nM)  Display this menu\nX)  Exit the program");
  while(i == 0) {
    printf("\n\nEnter a letter : ");
    scanf(" %c", &caseCheck);
    switch(caseCheck) {
      case 'a' :
      case 'A' :
        charCount = vowelCount(s1);
        printf("\nThat string has %d vowels.", charCount);
        break;
      case 'b' :
      case 'B' :
        charCount = constCount(s1);
        printf("\nThat string has %d consonants", charCount);
        break;
      case 'd' :
      case 'D' :
        toLower(s1);
        printf("\nIn all lowercase, that string is %s", s1);
        break;
      case 'c' :
      case 'C' :
        toUpper(s1);
        printf("\nIn all uppercase, that string is %s", s1);
        break;
      case 'e' :
      case 'E' :
        printf("\nThe current string is %s", s1);
        break;
      case 'f' :
      case 'F' :
        printf("\nPlease enter another string : ");
        scanf(" %[^\n]101s", s1);
        break;
      case 'm' :
      case 'M' :
        printf("\n\nA)  Count the number of vowels in the string\nB)  Count the number of consonants in the string\nC)  Convert the string to uppercase\nD)  Convert the string to lowercase\nE)  Display the current string\nF)  Enter another string\n\nM)  Display this menu\nX)  Exit the program");
        i = 0;
        break;
      case 'x' :
      case 'X' :
        i = 1;
        break;
      default :
        break;
    }
  }
  return 0;
}

int vowelCount(char s1[]) {
  int i = 0;
  int count = 0;
  s1 = toLower(s1);
  while (i < strlen(s1)) {
    if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') {
      count++;
    }
    i++;
  }
  return count;
}

int constCount(char s1[]) {
  int i = 0;
  int count = 0;
  s1 = toLower(s1);
  while (i < strlen(s1)) {
    if (!(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')) {
      count++;
    }
    i++;
  }
  return count;
}

char *toLower(char s1[]) {
  int var = strlen(s1);
  int charNum;
  for (int i = 0; i < var; i++) {
    charNum = (int) s1[i];
    if (charNum <= 90 && charNum >= 65) {
      s1[i] = s1[i] + 32;
    } else {
      s1[i] = s1[i];
    }
  }
  return s1;
}

char *toUpper(char s1[]) {
  int var = strlen(s1);
  int charNum;
  for (int i = 0; i < var; i++) {
    charNum = (int) s1[i];
    if (charNum <= 122 && charNum >= 97) {
      s1[i] = s1[i] - 32;
    } else {
      s1[i] = s1[i];
    }
  }
  return s1;
}
