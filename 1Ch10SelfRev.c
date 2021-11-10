#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>

int msleep(long msec);

int main(void) {
  //a)
  struct part {
    int partNumber;
    char partName[25];
  };
  //b)
  typedef struct part Part;
  //c)
  Part a;
  Part b[10];
  Part* ptr;
  //d)
  printf("Enter a part name : ");
  scanf("%s", a.partName);
  printf("\nEnter a part number : ");
  scanf("%d", &a.partNumber);
  //e)
  b[3] = a;
  //f)
  ptr = b;
  //g)
  printf("Hi, number is : %d\n", (ptr + 3)->partNumber);
  printf("Hi, name is : %s\n", (*(ptr + 3)).partName);
  //10.4
  //a) You need parens around the *cPtr or the dot should be a ->, otherwise it will do things in the wrong order
  //b) It's an array and you need the index, should be hearts[10]
  //c) Nope
  //d) need ; at end
  //e) need struct keyword
  //f) Can't assign different type structs to eachother.
}

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
