#include <stdio.h>
#include <string.h>

void strCat(char s[], char t[]);
int strEnd(char s[], char t[]);

int main(void) {
  int i = 0;
  char char1[] = "Bababooie";
  char char2[] = "Hello";
  char char3[] = "o";
  char char5[] = "O";
  char char6[] = "This is a string";
  i = strEnd(char2, char3);
  printf("should be 1 : %d\n", i);
  i = strEnd(char1, char3);
  printf("should be 0 : %d\n", i);
  i = strEnd(char2, char5);
  printf("should be 0 : %d\n", i);
  strCat(char1, char2);
  printf("Bababooie + Hello = %s\n", char1);
  for (int i = 0; i < 10; i++) {
    strCat(char2, char3);
  }
  printf("Long hello = %s\n", char2);
  strCat(char2, char6);
  printf("Long Hello + This is a string = %s\n", char2);
}

void strCat(char *s, char *t){
  //moves spt to the end of s
  while(*++s);
  //Adds whole of t to p by going along using tpt
  while(*s++ = *t++) {
  }
}

int strEnd(char *s, char *t){
  char* starts = s;
  char* startt = t;
  int ret;
  while(*s) {s++;}
  //move to end of s
  while(*t) {t++;}
  //move to the end of t
  while(*t == *s) {
    if(t == startt) {
      if (*t == *s) {
        return 1;
      } else {
        return 0;
      }
    }
    t--;
    s--;
  }
  return 0;
}
