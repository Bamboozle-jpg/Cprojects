//Lol get ncurses
//COMPILE THIS PROGRAM USING gcc -Wall PreBuiltGet.c -o YOURFILENAMEHERE -lncurses
//DA DOCUMENTATION : https://linux.die.net/man/3/keypad  ,  https://linux.die.net/man/3/mvwprintw , https://www.mkssoftware.com/docs/man3/curs_clear.3.asp ,
//Most of these are just for me, the important one is ncurses
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <ncurses.h>

//Sets Width of Window
#define WIDTH 30
//Sets Height of Window
#define HEIGHT 10

//Setup for later when it centers the window in the screen
int startx = 0;
int starty = 0;

//Array for menu
char *choices[] = {
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
		  };
//N choices is an integer representing the number of choices the player has
int n_choices = sizeof(choices) / sizeof(char *);
//Sets up the function that prints it
void print_menu(WINDOW *menu_win, int highlight, int q);
//Sleep function, I think this should work
int msleep(long msec);

int main() {
  //Creates the Window
  WINDOW *menu_win;
  // Sets up Var for which thing to highlight?
	int highlight = 1;
	int choice = 0;
	int c;

//Setup and stuff
  //Sets it up to print with ncurses
	initscr();
  //Clears the screen.... for some reason (removing this does nothing)
	clear();
  //Makes it so typed characters don't show up on the screen
	noecho();
  //Makes it so any character typed is immediately inputted and read
  //THIS IS THE IMPORTANT ONE
	halfdelay(1);	/* Line buffering disabled. pass on everything */
  //Centers it in the screen
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
  //Sets up the window with a height, width, and centers it
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
  //Makes it so any key presses are gotten and read through the window
	keypad(menu_win, TRUE);
  //prints out the line at the coordinates (static location.... I think) (use wprintw for something that can be scrolled I think)
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
  //Takes everything that's been told to be printed and puts it on the screen
	refresh();
  //Set up for future proof
  int q = 1;
  //Calls print_menu (oh boy, this is gonna be interesting)
	print_menu(menu_win, highlight, q);

//While loop to go through and change what's highlighted
  //While true (uh oh, don't tell ms. Voldstad :flushed:)
	while(1) {
    //When a character is put up, it acquires it and looks at it in the window
    c = wgetch(menu_win);
    //Takes that character and sets it to a switch (hah, get fucked jack)
		switch(c) {
      //moves the highlight depending on what's pressed
		  case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else
					++highlight;
				break;
      //I think this is enter? Confirms choice based on what's highlighted
			case 10:
				choice = highlight;
				break;
      //Hey fucker, you messed up on entering either up down or enter, idiot
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}

//Still in loop, choice is made,
    //calls print menu again
		print_menu(menu_win, highlight, q);
    //User made their choice
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
    //Ups q so you can see the program is still running even while getch doesn't return anything
    q++;
    //Wait to test my theory that this should work.
    msleep(900);
	}

//Out of loop
	//Print outside the window :
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	//clear to end of line (lets see what happens when I get rid of it :flushed:, ABSOLUTELY NOTHING, I DON'T KNOW WHAT THIS LINE IS DOING HERE, but I'll keep it)
	clrtoeol();
	//takes everything from printws and puts it on the screen
	refresh();
	//turns off the window
	endwin();
	//aaaaaaand it's done
	return 0;
}


//Takes in a window (I'd call it a structure), which thing's highlighted, and q which keeps going up to prove that it will keep going when a key isn't pressed
void print_menu(WINDOW *menu_win, int highlight, int q)
{
	//
	int x, y, i;
	//where to print it
	x = 2;
	y = 2;
	//
	box(menu_win, 0, 0);
	//cycles through choices and prints it highlighted if it is and normal if it's not
	for(i = 0; i < n_choices; ++i) {
		if(highlight == i + 1) {/* High light the present choice */
			//Yooooo I think this inverts the colors
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			//un inverts the colors
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
  mvwprintw(menu_win, y, x, "It's moving! --> %d", q);
	//refreshes the window, I think this does the same as refresh
	wrefresh(menu_win);
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
