#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>

//Rands movement and makes move change
void Hmove(int* pos);
void Tmove(int* pos);
int printGameState(hPos, tPos);
int msleep(long msec);

int main(void) {
  //setup
  int hPos = 1;
  int tPos = 1;
  srand(time(NULL));

  //start
  printf("BANG!!!!!\nAND THEY'RE OFF!!!!!\n\n");

  //main game loop
  while (hPos < 70 && tPos < 70) {
    //clock Animals (call clock which will figure out move and then it will call move to move them)
    Hmove(&hPos);
    Tmove(&tPos);

    //Makes sure neither is behind starting line
    if (hPos < 1) {
      hPos = 1;
    }
    if (tPos < 1) {
      tPos = 1;
    }

    //PRINTING OUT THE GAME
    printGameState(hPos, tPos);

    //Sleeps for 1/5 of a second
    msleep(200);
  }
  printf("\n");
  msleep(800);

  //test for win
  if (hPos == tPos) {
    printf("WOULD YOU LOOK AT THAT FOLKS!! IT'S A TIE!\n");
    msleep(800);
    printf("BOTH OUR COMPETETORS CROSSED THE LINE AT THE SAME TIME!!\n");
    msleep(800);
    printf("BOTH ENDED IN POSITION %d!! CONGRATS TO EVERYONE!!", hPos);
  }
  printf("AND THE RACE IS DONE, WE HAVE OUR WINNER!!\n");
  msleep(800);
  if (tPos > hPos) {
    printf("THE TORTOISE ");
  } else {
    printf("THE HARE ");
  }
  printf("HAS WON THE RACE!!");

  return 0;
}

void Hmove(int* pos) {
  int i = rand()%10 + 1;
  if (i <= 2) {
    //do nothing
  } else if (i <= 4) {
    //9 forward
    *pos += 9;
  } else if (i <= 5) {
    //12 backwards
    *pos -= 12;
  } else if (i <= 8) {
    //1 forward
    *pos += 1;
  } else {
    //2 backwards
    *pos -= 2;
  }
}

void Tmove(int* pos) {
  int i = rand()%10 + 1;
  if (i <= 5) {
    //3 squares forward
    *pos += 3;
  } else if (i <= 7) {
    //6 squares backward
    *pos -= 6;
  } else {
    //1 square forward
    *pos += 1;
  }

}

//Prints out game state
int printGameState(int hPos, int tPos) {
  int before = 0;
  int middle = 0;
  int after = 69;

  //Sets up number of spaces before and after and in between
  if (tPos < hPos) {
    before = tPos - 1;
    after = 69 - hPos;
    middle = 68 - after - before;
  } else if (hPos > tPos) {
    before = hPos - 1;
    after = 69 - tPos;
    middle = 68 - after - before;
  } else {
    before = hPos -1;
    after = 69 - hPos;
    middle = 0;
  }

  //checks if they're on top of each other, and if so, prints the bang at the spot
  if (tPos == hPos) {
    for (int i = 0; i < before; i++) {
      printf(" ");
    }
    printf("💥");
    for (int i = 0; i < after; i++) {
      printf(" ");
    }
    printf("| <--FINISH LINE, OOOOOH! THAT'S GOTTA HURT!\n");
  }

  //print for if they are not on top of each other
  else {
    for (int i = 0; i < before; i++) {
      printf(" ");
    }
    if (hPos > tPos) {
      printf("T");
      for (int i = 0; i < middle; i++) {
        printf(" ");
      }
      printf("H");
      for (int i = 0; i < after; i++) {
        printf(" ");
      }
      printf("| <--FINISH LINE, tort pos : %d\n", tPos);
    } else {
      printf("H");
      for (int i = 0; i < middle; i++) {
        printf(" ");
      }
      printf("T");
      for (int i = 0; i < after; i++) {
        printf(" ");
      }
      printf("| <--FINISH LINE, tort pos : %d\n", tPos);
    }
  }
  printf("\n");
}

//Sleeps
int msleep(long msec) {
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}
