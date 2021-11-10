#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <ncurses.h>

int main(void) {
  WINDOW *mywindow;
  mywindow = initscr();
  mvwprintw( mywindow, 0, 0, "Hello World %d", 123 );
}
