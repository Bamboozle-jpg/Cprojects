#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>

int packCharacters(char a, char b);
char unpackCharacters(unsigned int num);
void printBits(unsigned int input);

int main(void) {
  char a, b;
  int num;
  printf("Please give a character : ");
  scanf("\n%c", &a);
  printf("\nPlease give another character : ");
  scanf("\n%c", &b);
  num = packCharacters(a, b);
  printf("In bits, these two characters are : ");
  printBits(num);
  unpackCharacters(num);


  return 1;
}

int packCharacters(char a, char b) {
  unsigned int num;
  num = (int) a;
  num += (int) b*1000;
  //Will be b b b a a a
  printf("%u\n", num);
  return num;
}

char unpackCharacters(unsigned int num) {
  int anum = num%1000;
  int bnum = num/1000;
  char a = (char) anum;
  char b = (char) bnum;
  printf("The characters are : \n");
  printf("1st = %c, 2nd = %c\n", a, b);
}

void printBits(unsigned int input) {
  printf("\n");
  unsigned int mask = 1<<15;
  for (int i = 1; i <= 16; i++) {

    putchar((input & mask)? '1':'0');
    if (i%8 == 0) {
      putchar(' ');
    }
    input <<= 1;
  }
  printf("\n");
}


//THE RESULT :
// kevin@KBLinuxMachine:~/code/Cprojects$ ./packKB 
// Please give a character : c
//
// Please give another character : e
// 101099
// In bits, these two characters are :
// 10001010 11101011
// The characters are :
// 1st = c, 2nd = ekevin@KBLinuxMachine:~/code/Cprojects$ gcc -Wall packKB.c -o packKB
// packKB.c: In function ‘unpackCharacters’:
// packKB.c:44:1: warning: control reaches end of non-void function [-Wreturn-type]
//    44 | }
//       | ^
// kevin@KBLinuxMachine:~/code/Cprojects$ ./packKB
// Please give a character : !
//
// Please give another character : &
// 38033
// In bits, these two characters are :
// 10010100 10010001
// The characters are :
// 1st = !, 2nd = &
// kevin@KBLinuxMachine:~/code/Cprojects$ ./packKB
// Please give a character : X
//
// Please give another character : Z
// 90088
// In bits, these two characters are :
// 01011111 11101000
// The characters are :
// 1st = X, 2nd = Z
