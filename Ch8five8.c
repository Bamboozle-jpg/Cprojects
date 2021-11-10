#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main() {
  char input;


printf("Assign 8.5 : \n\n");
  printf("Please enter a character : ");
  scanf("%c", &input);
  printf("Whether or not your input is a digit : \t\t\t\t%s\n", isdigit(input)?"true":"false");
  printf("Whether or not your input is a letter : \t\t\t%s\n", isalpha(input)?"true":"false");
  printf("Whether or not your input is a letter or digit : \t\t%s\n", isalnum(input)?"true":"false");
  printf("Whether or not your input is a hex digit : \t\t\t%s\n", isxdigit(input)?"true":"false");
  printf("Whether or not your input is a lowercase letter : \t\t%s\n", islower(input)?"true":"false");
  printf("Whether or not your input is an uppercase letter : \t\t%s\n", isupper(input)?"true":"false");
  printf("Whether or not your input is a space : \t\t\t\t%s\n", isspace(input)?"true":"false");
  printf("Whether or not your input is a control character : \t\t%s\n", iscntrl(input)?"true":"false");
  printf("Whether or not your input is a symbol : \t\t\t%s\n", ispunct(input)?"true":"false");
  printf("Whether or not your input is a printable character : \t\t%s\n", isprint(input)?"true":"false");
  printf("Whether or not your input is a printable character besides a space : \t%s\n", isgraph(input)?"true":"false");
  input = toupper(input);
  printf("in uppercase it's : %c\n", input);
  input = tolower(input);
  printf("in lowercase it's : %c", input);


printf("\n\nAssign8.6\n\n");
  char string[100] = "a";
  printf("Please enter a string that is less than 100 characters long : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string);
  for (int i = 0; i < 100; i++) {
    if (isalpha(string[i])) {
      string[i] = tolower(string[i]);
    }
  }
  printf("That string in lower case is : %s\n", string);
  for (int i = 0; i < 100; i++) {
    if (isalpha(string[i])) {
      string[i] = toupper(string[i]);
    }
  }
  printf("That string in upper case is : %s\n", string);


printf("\nAssign8.7\n\n");
  char string1[100], string2[100], string3[100], string4[100];
  printf("Please enter string of integer # 1 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string1);
  printf("Please enter string of integer # 2 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string2);
  printf("Please enter string of integer # 3 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string3);
  printf("Please enter string of integer # 4 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string4);
  printf("\n");
  char *pointer;
  long x1 = strtol(string1, &pointer, 0);
  long x2 = strtol(string2, &pointer, 0);
  long x3 = strtol(string3, &pointer, 0);
  long x4 = strtol(string4, &pointer, 0);
  int xtot = x1 + x2 + x3 + x4;
  printf("The total is : %d", xtot);


printf("\n\nAssign8.8\n\n");
  printf("Please enter string of double # 1 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string1);
  printf("Please enter string of double # 2 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string2);
  printf("Please enter string of double # 3 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string3);
  printf("Please enter string of double # 4 : ");
  scanf("%c", &input);
  scanf("%[^\n]100s", string4);
  printf("\n");
  double y1 = strtod(string1, &pointer);
  double y2 = strtod(string2, &pointer);
  double y3 = strtod(string3, &pointer);
  double y4 = strtod(string4, &pointer);
  double ytot = y1 + y2 + y3 + y4;
  printf("The total is : %.2f", ytot);

  return 0;
}

/*
  output :

  Assign 8.5 :

  Please enter a character : a
  Whether or not your input is a digit :                          false
  Whether or not your input is a letter :                         true
  Whether or not your input is a letter or digit :                true
  Whether or not your input is a hex digit :                      true
  Whether or not your input is a lowercase letter :               true
  Whether or not your input is an uppercase letter :              false
  Whether or not your input is a space :                          false
  Whether or not your input is a control character :              false
  Whether or not your input is a symbol :                         false
  Whether or not your input is a printable character :            true
  Whether or not your input is a printable character besides a space :    true
  in uppercase it's : A
  in lowercase it's : a

  Assign8.6

  Please enter a string that is less than 100 characters long : Hello my FRIEND.
  That string in lower case is : hello my friend.
  That string in upper case is : HELLO MY FRIEND.

  Assign8.7

  Please enter string of integer # 1 : 100
  Please enter string of integer # 2 : 15
  Please enter string of integer # 3 : 35
  Please enter string of integer # 4 : 4

  The total is : 154

  Assign8.8

  Please enter string of double # 1 : 3.56
  Please enter string of double # 2 : 10.5
  Please enter string of double # 3 : 13.89
  Please enter string of double # 4 : 9.9

  The total is : 37.85
*/
