#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SIZE 8;

int placeQueen(double **available);

double rowColumnTaken[SIZE][SIZE] = false;
dobule
int boardSize = SIZE*SIZE;

int main() {
  for (int firstPiece = 0; firstPiece < SIZE; firstPiece++) {
    for (int position = 0; position < boardSize; position++) {
      rowColumnTaken[position/SIZE] = true;
      rowColumnTaken[position%SIZE] = true;
    }
  }
}
