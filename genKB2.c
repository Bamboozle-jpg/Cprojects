#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

//Max index, not size
#define WORDS 26

int test = 999;

int getSubString(char *source, char *target,int from, int to);
int  get2SubString(char *source, char *target,int from, int to);

int main(void) {
  char before[999];
  int y;
  // int test = 1;
  char *placeholder;
  char *fileContentsUse;
  int break1, break2;
  char after[999];
  char final[999];
  int temp;
  int gamer;
  char bad[WORDS][999] = {
    "he is",
    "she is",
    "him",
    "her",
    "his",
    "hers",
    "girl",
    "boy",
    "woman",
    "man",
    "daughter",
    "son",
    "wife",
    "husband",
    "king",
    "queen",
    "he's",
    "she's",
    "he",
    "she",
    "brothers",
    "sisters",
    "sister",
    "brothers",
    "father",
    "mother"
  };

  char good[WORDS][999] = {
    "they are",
    "they are",
    "them",
    "them",
    "theirs",
    "theirs",
    "child",
    "child",
    "person",
    "person",
    "spawn",
    "spawn",
    "spouse",
    "spouse",
    "ruler",
    "ruler",
    "they're",
    "they're",
    "they",
    "they",
    "siblings",
    "siblings",
    "sibling",
    "sibling",
    "parent",
    "parent"
  };


  //variables declaration
  FILE *fptr;
  char filename[15] = "genKB.txt";
  char *fileContents;
  char ch;

  /* opening the file for reading */
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    printf("Cannot open file \n");
    exit(0);
  }
  ch = fgetc(fptr);
  int i = 0;
  while (ch != EOF) {
    //Assigns entire file to string fileContents
    fileContents[i] = ch;
    i++;
    ch = fgetc(fptr);
  }
  fclose(fptr);


  //print to test
  strcpy(after, fileContents);
  char *tokenPtr = strtok(fileContents, " ");

  // i = 5;
  // printf("%s", bad[i]);
  while (tokenPtr != NULL) {
    i = 0;
    char tokenP[999];
    strcpy(tokenP, tokenPtr);
    //lowercase first letter
    if(tokenP[0] >= 'A' && tokenP[0] <= 'Z') {
      printf("Lowercaseify : %c\n", tokenP[0]);
      tokenP[0] = tokenP[0] +32;
    }
    temp = 0;
    temp = strlen(tokenP)-1;
    //WHY DOES THIS STRLEN NOT WORK?????
    if (!isalpha(tokenP[temp])) {
      tokenP[temp] = '\0';
      printf("\nIt's working!!\n");
      printf("tokenP = %s\n", tokenP);
      printf("temp = %d\n", temp);
      printf("tokenP[temp] = %s\n", tokenP[temp]);
    }
    printf("hi this is a test\n");
    gamer = 0;
    while (i < WORDS) {
      if(strcmp(tokenP, bad[i]) == 0) {
        printf("\nTHIS IS WORKING\n");
        // tokenPtr = good[i];
        strcpy(final, strcat(final, good[i]));
        strcpy(final, strcat(final, " "));
        gamer = 1;
      }
      //THIS SHOULDN'T CAUSE A SEGMENTATION FAULT ERROR AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA WHY
      // printf("\nchange : %d\n", gamer);
      i++;
    }

    //WHY DOES THIS CREATE A SEGMENTATION FAULT ERROR?
    // if (gamer == 0) {
      strcpy(final, strcat(final, tokenPtr));
      strcpy(final, strcat(final, " "));
    // }
    printf("\nfinal : %s\n", final);
    tokenPtr = strtok(NULL, " ");
  }
  return 0;
}
