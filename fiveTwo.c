#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>

struct point { int x; int y; };

void changeX1 (struct point pt)  { pt.x = 10; }
// void changeX2 (struct point *pt) { pt.x = 20; }
// void changeX3 (struct point *pt) { pt->x = 30; }


int main() {
  struct point my_pt;
     changeX1(&my_pt);
     printf("%d\n", my_pt.x);
}
