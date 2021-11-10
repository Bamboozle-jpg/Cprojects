#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

//Number of different words that are searched for and changed
#define WORDS 32
#define TITLE "sexistKB.txt"

//Makes sure it goes multiple times to find multiple instances of the same word
int loopCheck = 99;

//Gets the substring of a string
int getSubString(char *source, char *target,int from, int to);

int main(void) {
  //String that stores string before the word that is being changed
  char before[999];
  //Holds the string of the first instance of the word needing to be changed
  char *placeholder;
  //Where the breaks are for getting the word that is being changed alone
  int break1, break2;
  //Stores the string that is after the word being changed
  char after[999];
  //Stores final string that is then copied to original to prevent weird pointer issues
  char *final;
  //List of words that are searched for and changed
  char *bad[WORDS] = {
    "policeman",
    "policewoman",
    "steward",
    "stewardess",
    "businessman",
    "businesswoman",
    "girlfriends",
    "boyfriends",
    "boys",
    "girls",
    "boy",
    "girl",
    "he is",
    "she is",
    "him",
    "her",
    "girl",
    "boy",
    "daughter",
    "son",
    "daughters",
    "sons",
    "wife",
    "husband",
    "he",
    "she",
    "brothers",
    "sisters",
    "sister",
    "brother",
    "father",
    "mother",
  };

  //Corresponding list of what bad[] is changed to
  char *good[WORDS] = {
    "officer",
    "officer",
    "house manager",
    "house manager",
    "businessperson",
    "businessperson",
    "significant others",
    "significant others",
    "childeren",
    "children",
    "child",
    "child",
    "they are",
    "they are",
    "them",
    "them",
    "child",
    "child",
    "spawn",
    "spawn",
    "spawn",
    "spawn",
    "spouse",
    "spouse",
    "they",
    "they",
    "siblings",
    "siblings",
    "sibling",
    "sibling",
    "parent",
    "parent"
  };


  //variable that goes along file copying it
  FILE *fptr;
  //says what file should be looked at
  char filename[15] = TITLE;
  //Creates variable to hold file contents
  char *fileContents;
  //Character to copy contents over as it moves along
  char ch;

  //Open file for reading
  fptr = fopen(filename, "r");
  //If it can't find the file, print an error and exit
  if (fptr == NULL) {
    printf("Cannot open file \n");
    exit(0);
  }

  //sets the character to the first character of the file
  ch = fgetc(fptr);
  //setup for loop
  int i = 0;
  //Loop through the file until the file's end
  while (ch != EOF) {
    //Assigns entire file to string fileContents
    fileContents[i] = ch;
    i++;
    //Gets the next character
    ch = fgetc(fptr);
  }
  //Closes the file
  fclose(fptr);


  //Creates cont to check if there are more words that need to be changed
  int cont = 1;

  //Makes sure there are still words needing to be changed and it hasn't gone through too many times
  while (cont == 1 || loopCheck >= 0) {

    //Loops through list of words so each can be checked
    for (int i = 0; i < WORDS; i++) {
      //placeholder stores first instance of the word in the string
      placeholder = strstr(fileContents, bad[i]);
      //Continue is set to true (or false) so that it won't keep going if it doesn't go through the if statement
      cont = 2;

      //if the placeholder exists, it means it contains a bad word, so it goes through the process of changing it.
      if(placeholder) {
        //Sets placeholder again because sometimes it fails if this isn't here
        placeholder = strstr(fileContents, bad[i]);

        //Math to calculate where to split up the string
        //x represents the end of the string
        int x = strlen(fileContents);
        //creates y
        int y;
        //Sets y to the length of placeholder
        y = strlen(placeholder);
        //creates and sets z to the length of the bad word
        int z = strlen(bad[i]);
        //the first break will be at the length of the whole string minus the length of the string starting at the placeholder
        //AKA break1 is at the beginning of the placeholder
        break1 = x-y;
        //break2 is at the beginning of the placeholder plus it's length
        break2 = z + break1;
        //break1 gives where to start at, and doesn't end up including the first character so this fixes it
        break1--;

        //if it starts and ends with a letter actually do the change (prevents inclusion of punctuation and stuff)
        if (isalpha(fileContents[break1]) || isalpha(fileContents[break2])) {} else {

          //HERE IS THE ACTUAL SWAPPING
          //gets a substring from the beginning to the break and assigns it to before
          getSubString(fileContents, before, 0, break1);
          //gets a substring from the second break to the end and sets it to after
          getSubString(fileContents, after, break2, strlen(fileContents)-1);

          //the final becomes the before, followed by the replacement followed by after
          final = strcat(before, good[i]);
          final = strcat(final, after);
          //copies final over to fileContents so the process can be repeated
          strcpy(fileContents, final);
          //Tells it that it needs to loop through again in case there are later instances of the bad word
          cont = 1;
        }
      }
    }
    //Decreases loop check so that it doesn't go on forever (this makes it so that it will only change up to 999 words as we don't want infinite loop in case some weird recursion happens)
    loopCheck--;
  }

  //Finally prints out the string with all the words changed
  printf("\nfinal : %s", fileContents);
  return 0;
}

//Function to get the substring of a string (because doing that in c is a pain and a half)
int getSubString(char *source, char *target,int from, int to) {
  //Sets up variables that go through each string to the beginning
	int length=0;
	int i=0,j=0;

	//get length of first string
	while(source[i++]!='\0')
		length++;

  //Prints an error if the from integer is too big or too small (off of the string)
	if(from<0 || from>length){
		printf("Invalid \'from\' index\n");
		return 1;
	}

  //if the to integer is past the end of the string, prints an error
	if(to>length){
		printf("Invalid \'to\' index\n");
		return 1;
	}

  //Sets the output string to the input string letter by letter
  //goes from from to to so you only get the string within those integers
	for(i=from,j=0;i<=to;i++,j++){
		target[j]=source[i];
	}

  //Resets the pointer back to the beginning so it doesn't mess up the source string
  while(i != 0) {
    source++;
    i--;
  }

	//assign NULL at the end of string
	target[j]='\0';

	return 0;
}
