#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>

void printBits(unsigned int input);
int powerOfTwo(unsigned int input, unsigned int power);

int main(void) {
  unsigned int input;
  unsigned int final;
  unsigned int power;
  printf("Please input an integer : ");
  scanf("%u", &input);
  printBits(input);

  printf("\n\nPROJECT 2 : \n\n");
  printf("You would like to multiply that by 2 to the what? : ");
  scanf("%u", &power);
  final = powerOfTwo(input, power);
  printBits(final);
  return 1;
}

void printBits(unsigned int input) {
  printf("\n");
  unsigned int mask = 1<<15;
  printf("%7u\n", mask);
  for (int i = 1; i <= 16; i++) {

    putchar((input & mask)? '1':'0');
    if (i%8 == 0) {
      putchar(' ');
    }
    input <<= 1;
  }
  printf("\n");
}

int powerOfTwo(unsigned int input, unsigned int power) {
  input <<= power;
  return input;
}

//OUTPUT 1 :
// Please input an integer : 5
//
//   32768
// 00000000 00000101
// kevin@KBLinuxMachine:~/code/Cprojects$ ./shiftKB
// Please input an integer : 10
//
//   32768
// 00000000 00001010
// kevin@KBLinuxMachine:~/code/Cprojects$ ./shiftKB
// Please input an integer : 100
//
//   32768
// 00000000 01100100
// kevin@KBLinuxMachine:~/code/Cprojects$ ./shiftKB
// Please input an integer : 64
//
//   32768
// 00000000 01000000

//OUTPUT 2 :
// Please input an integer : 5
//
//   32768
// 00000000 00000101
//
//
// PROJECT 2 :
//
// You would like to multiply that by 2 to the what? : 1
//
//   32768
// 00000000 00001010
// kevin@KBLinuxMachine:~/code/Cprojects$ ./shiftKB
// Please input an integer : 64
//
//   32768
// 00000000 01000000
//
//
// PROJECT 2 :
//
// You would like to multiply that by 2 to the what? : 2
//
//   32768
// 00000001 00000000
