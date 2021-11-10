#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>

int msleep(long msec);
void printGameState(int board[12][12], int posX, int posY);
int move(int board[12][12], int posX, int posY, int dirMoved);


int main(void) {
  //Sets up game board
  int maze[12][12] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };

  //Sets starting position for player and movement
  int posX = 0, posY= 1, dirMoved = 3;
  //Sets initial starting y
  for (int i = 0; i < 12; i++) {
    if (maze[i][0] == 0) {
      posY = i;
    }
  }
  //Game state print (mainly to test)
  printGameState(maze, posX, posY);

  //Main game loop
  while(!(posX == 11)) {
    //Calls the move function and sets it to the just moved variable
    dirMoved = move(maze, posX, posY, dirMoved);
    //Moves the position based on return from move
    switch (dirMoved) {
      case 0:
        posY--;
        break;
      case 1:
        posX--;
        break;
      case 2:
        posY++;
        break;
      case 3:
        posX++;
        break;
      default:
        break;
    }
    //prints game state for user to See
    printGameState(maze, posX, posY);
    //Waits to give illusion of moving character
    msleep(200);
  }

  //when the loop ends, the game ends with congratulations
  printf("Yay, you found the exit!");
  //Ends the main function because that is good etiquette (It would still work if I didn't do that tho)
  return 0;
}


//takes in current board state, and prints it out
void printGameState(int board[12][12], int posX, int posY) {
  //Space so it looks like the thing is actually moving and you don't see the after images going up
  for(int i = 0; i < 20; i++) {
    printf("\n");
  }

  //prints all the rows
  for(int i = 0; i < 12; i++) {
    //prints a row
    for (int j = 0; j < 12; j++) {
      if(posY == i && posX == j) {
        //prints you (the gamer)
        printf(" G ");
      //prints out a board piece based on the integer 2D array
      } else if (board[i][j] == 1) {
        //Prints a wall if the corresponding number is 1
        printf("=#=");
      } else {
        //Prints an empty space if there's a corresponding 0
        printf("   ");
      }
    }
    printf("\n");
  }

}


//Given a location and sends out a new location of the playuer
//Returns 0 for up, 1 for left, 2 for down, 3 for right
int move(int board[12][12], int posX, int posY, int dirMoved) {
  //Given an initial movement that it just took, chooses which way to turn and what that means
  switch (dirMoved) {
    //Moved up
    case 0:
      //Attempts to turn right
      if (board[posY][posX+1] == 0) {
        return 3;
      //attempts to keep going
    } else if (board[posY-1][posX] == 0) {
        return 0;
      //attempts to turn left
    } else if (board[posY][posX-1] == 0) {
        return 1;
      //otherwise turns around
      } else {
        return 2;
      }
      break;

    //Moved left
    case 1:
      //Attempts to turn right
      if (board[posY-1][posX] == 0) {
        return 0;
      //attempts to keep going
    } else if (board[posY][posX-1] == 0) {
        return 1;
      //attempts to turn left
    } else if (board[posY+1][posX] == 0) {
        return 2;
      //otherwise turns around
      } else {
        return 3;
      }
      break;

    //moved down
    case 2:
      //Attempts to turn right
      if (board[posY][posX-1] == 0) {
        return 1;
      //attempts to keep going
    } else if (board[posY+1][posX] == 0) {
        return 2;
      //attempts to turn left
    } else if (board[posY][posX+1] == 0) {
        return 3;
      //otherwise turns around
      } else {
        return 0;
      }
      break;

    //moved right
    case 3:
      //Attempts to turn right
      if (board[posY+1][posX] == 0) {
        return 2;
      //attempts to keep going
      } else if (board[posY][posX+1] == 0) {
        return 3;
      //attempts to turn left
      } else if (board[posY-1][posX] == 0) {
        return 0;
      //otherwise turns around
      } else {
        return 1;
      }
      break;
  }
  //Just in case something fails, default case for if nothing happens.
  printf("Uh oh, there was an error");
  return 0;
}

//Sleep function for less than a second
//input x/1000 seconds
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
