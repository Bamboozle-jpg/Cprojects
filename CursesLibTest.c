//To Compile : gcc -Wall CursesLibTest.c -o CursesLibTest -lncurses

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <ncurses.h>

int msleep(long msec);

int main()
{
// 	//IT WORKSSSSSS!!!!!!!!!!!
// 	initscr();			/* Start curses mode 		  */
// 	WINDOW test;
// 	printw("Hello World !!!");	/* Print Hello World		  */
// 	refresh();			/* Print it on to the real screen */
// 	// getch();			/* Wait for user input */
// 	// endwin();			/* End curses mode		  */
// 	int i = 0;
//
// 	while(i >= 0) {
// 		endwin();
// 		initscr();
// 		printw("Hello World !!! + %d\n", i);
// 		scroll(stdscr);
// 		refresh();
// 		msleep(100);
// 		i++;
// 	}
//
// 	return 0;
// }
	int i = 2, height, width;
	WINDOW *new;

	initscr();
	getmaxyx(stdscr, height, width);
	new = newwin(height - 2, width - 2, 1, 1);

	scrollok(new,TRUE);

	while(1)
	{
		for(int j = 0; j < 20; j++) {
			wprintw(new, "\n");
		}
		wprintw(new, "%d - lots and lots of lines flowing down the terminal\n", i);
		msleep(100);
		++i;
		wrefresh(new);
	}

	endwin();
	return 0;
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
