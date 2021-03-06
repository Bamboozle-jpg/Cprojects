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
#define WIDTH 60
//Sets Height of Window
#define HEIGHT 20

#define ENEMGENX 1
#define ENEMGENY 10
#define ENEMGENTX 8
#define ENEMGENTY 10

#define OFFSETX 12
#define OFFSETY 4
#define SCOOL 5
// #define GAMESPEED 200
#define ENEMCOOL 5

int enemy1X, enemy1Y, playerX, playerY, move1, move2, enemy2X, enemy2Y, shot1X, shot1Y, shot2X, shot2Y, score, sCool, cool1, cool2, end, choice;
char c;
//Setup for later when it centers the window in the screen
int startx = 0;
int starty = 0;
int gamespeed = 200;
int highlight = 1;

//Array for menu
char *choices[] = {
			"Play Game",
			"Change speed",
			"Exit",
		  };
//N choices is an integer representing the number of choices the player has
int n_choices = sizeof(choices) / sizeof(char *);
//Sets up the function that prints it
void printGameState(WINDOW *menu_win, int highlight, int q, int board[12][12], int choose);
//Sleep function, I think this should work
int msleep(long msec);
//Move enemies
int enemyMove(int board[12][12], int posX, int posY, int dirMoved);
//Make sure there's always an enemy
void createEnemy(int gen);
//Print the menu
void print_menu(WINDOW *menu_win, int highlight);
//Print the speed menu
void print_menu_speed(WINDOW *menu_win);

int main() {
	end = 0;
  //Creates the Window
  WINDOW *menu_win;
  // Sets up Var for which thing to highlight?
	int highlight = 1;
	int choice = 0;
	int c;

	//GAME STUFF
	//Sets up game board
	int maze[12][12] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
		{1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	sCool = 0;

//Setup and stuff
	playerX = 1;
	playerY = 1;
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
	mvprintw(0, 0, "Arrow Keys up and down to navigate, enter to select. While playing, arrow keys to move, A and D to swing sword left and right");
  //Takes everything that's been told to be printed and puts it on the screen
	refresh();
  //Set up for future proof
  int q = 1;
	choice = 4;

	//menu
	while(choice == 4) {
		choice = 4;
		while(1)
		{	c = wgetch(menu_win);
			switch(c)
			{	case KEY_UP:
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
				case 10:
					choice = highlight;
					break;
				default:
					refresh();
					break;
			}
			print_menu(menu_win, highlight);
			if(choice == 1 || choice == 2 || choice == 3)	{/* User did a choice come out of the infinite loop */
				break;
			}
		}

		//Prepares game board for if they want to play/play again
		if(choice == 1) {
		//Setup for game
			score = 0;
			//Sets enemy1 to start offscreen
			enemy1X = -1;
		  enemy1Y = -1;
			//Decreases cooldowns
			cool1 = -1;
			cool2 = -1;
			//Creates the enemies
		  createEnemy(1);
		  createEnemy(2);
			//Sets the direction of the enemies
		  move1 = 3;
		  move2 = 3;
			//Sets the starting point for the player
			playerX = 1;
			playerY = 1;
		}

		if (choice == 2) {
			int close = 0;
			while (close == 0) {
				print_menu_speed(menu_win);
				c = wgetch(menu_win);
				switch(c) {
					case KEY_UP:
						gamespeed += 10;
						break;
					case KEY_DOWN:
						gamespeed -= 10;
						break;
					case 10:
						close = 1;
						break;
				}
				if (gamespeed < 10) {
					gamespeed = 10;
				}
				if (gamespeed > 500) {
					gamespeed = 500;
				}
			}
			choice = 4;
		}

		if (choice == 3) {
			clrtoeol();
			//takes everything from printws and puts it on the screen
			refresh();
			//turns off the window
			endwin();
			return 0;
		}

		//main game loop
	  while(choice == 1) {
			if (sCool > 0) {
				sCool--;
			}

			if (cool1 == 0) {
				enemy1X = ENEMGENX;
				enemy1Y = ENEMGENY;
				move1 = 3;
				cool1--;
			} else {
				cool1--;
			}

			if (cool2 == 0) {
				enemy2X = ENEMGENTX;
				enemy2Y = ENEMGENTY;
				move2 = 3;
				cool2--;
			} else {
				cool2--;
			}

	    if (enemy1X != -1) {
	      move1 = enemyMove(maze, enemy1X, enemy1Y, move1);
	      switch (move1) {
	        case 0:
	          enemy1Y--;
	          break;
	        case 1:
	          enemy1X--;
	          break;
	        case 2:
	          enemy1Y++;
	          break;
	        case 3:
	          enemy1X++;
	          break;
	        default:
	          break;
	      }
	      if (enemy2X != -1) {
	        move2 = enemyMove(maze, enemy2X, enemy2Y, move2);
	        switch (move2) {
	          case 0:
	            enemy2Y--;
	            break;
	          case 1:
	            enemy2X--;
	            break;
	          case 2:
	            enemy2Y++;
	            break;
	          case 3:
	            enemy2X++;
	            break;
	          default:
	            break;
	        }
	      }

				if ( (playerX == enemy1X && playerY == enemy1Y) || (playerX == enemy2X && playerY == enemy2Y) ) {
					end = 1;
					printGameState(menu_win, highlight, q, maze, choice);
				}

				c = wgetch(menu_win);
				shot1X = -4;
				shot1Y = -4;
				shot2X = -4;
				shot2Y = -4;
				switch(c) {
					//moves the highlight depending on what's pressed
					case KEY_UP:
						if(maze[playerY-1][playerX] == 0) {
							playerY--;
						}
						break;
					case KEY_DOWN:
						if(maze[playerY+1][playerX] == 0) {
							playerY++;
						}
						break;
					case KEY_RIGHT:
						if(maze[playerY][playerX+1] == 0) {
							playerX++;
						}
						break;
					case KEY_LEFT:
						if(maze[playerY][playerX-1] == 0) {
							playerX--;
						}
						break;
					case 'd':
						if (sCool == 0) {
							sCool = SCOOL;
							if(maze[playerY][playerX+1] == 0) {
								shot1Y = playerY;
								shot1X = playerX+1;
								if(maze[playerY][playerX+2] == 0) {
									shot2Y = playerY;
									shot2X = playerX+2;
								}
							}
						}
						break;
					case 'a':
						if (sCool == 0) {
							sCool = SCOOL;
							if(maze[playerY][playerX-1] == 0) {
								shot1Y = playerY;
								shot1X = playerX-1;
								if(maze[playerY][playerX-2] == 0) {
									shot2Y = playerY;
									shot2X = playerX-2;
								}
							}
						}
						break;
					default:
						break;
				}
				if ((shot1X == enemy1X && shot1Y == enemy1Y) || (shot2X == enemy1X && shot2Y == enemy1Y)) {
					score++;
					enemy1X = -100;
					enemy1Y = -100;
					cool1 = ENEMCOOL;
				}
				if ((shot1X == enemy2X && shot1Y == enemy2Y) || (shot2X == enemy2X && shot2Y == enemy2Y)) {
					score++;
					enemy2X = -100;
					enemy2Y = -100;
					cool2 = ENEMCOOL;
				}
	    }
	    printGameState(menu_win, highlight, q, maze, choice);
	    msleep(gamespeed);
			if ( (playerX == enemy1X && playerY == enemy1Y) || (playerX == enemy2X && playerY == enemy2Y) ) {
				choice = 4;
				printGameState(menu_win, highlight, q, maze, choice);
			}
	  }
	}

//out of loop
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
void printGameState(WINDOW *menu_win, int highlight, int q, int board[12][12], int choose) {
	//setup
	//where to print it
	//
	box(menu_win, 0, 0);
	//Yooooo I think this inverts the colors
	// wattron(menu_win, A_REVERSE);
	//i is vertical, j is horizontal
	if (choose == 1) {
		for(int i = 0; i < 12; i++) {
			//prints a row
			for (int j = 0; j < 12; j++) {
				if ((i == ENEMGENY && j == ENEMGENX) || (i == ENEMGENTY && j == ENEMGENTX)) {
	        if((i == enemy1Y && j == enemy1X) || (i == enemy2Y && j == enemy2X)) {
	          mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "[M ");
	        } else if (i == playerY && j == playerX) {
	          mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "[G ");
	        } else {
	          mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "[  ");
	        }
	      } else if (playerY == i && playerX == j) {
	        //prints you (the gamer)
	        mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, " G ");
	      } else if (shot1Y == i && shot1X == j) {
	        //prints beginning of sword
	        mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "=[=");
	      } else if (shot2Y == i && shot2X == j) {
					//prints the end of sword
	        if (shot2X > playerX) {
	        	mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "==>");
					} else if (shot2X < playerX) {
	        	mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "<==");
					}
	      } else if(enemy1Y == i && enemy1X == j) {
	        //prints monster
	        mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", " M ");
	      } else if(enemy2Y == i && enemy2X == j) {
	        //prints monster
	        mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", " M ");
	      } else if (board[i][j] == 1) {
	        //Prints a wall if the corresponding number is 1
	        mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "=#=");
	      } else {
	        //Prints an empty space if there's a corresponding 0
	        mvwprintw(menu_win, i+OFFSETY, 3*j+OFFSETX, "%s", "   ");
	      }
			}
			if (sCool == 0) {
				mvwprintw(menu_win, OFFSETY+12, OFFSETX, "%s", "Sword Swing Ready!            ");
			} else {
				mvwprintw(menu_win, OFFSETY+12, OFFSETX, "Sword Almost ready, Cooldown %d", sCool);
			}
			mvwprintw(menu_win, OFFSETY+13, OFFSETX, "Score : %d ", score);
		}
	} else {
		for (int i = 0; i < 5; i++) {
			mvwprintw(menu_win, OFFSETY+i, OFFSETX, "                                     ");
		}
		mvwprintw(menu_win, OFFSETY+5, OFFSETX-3, "CONGRATULATIONS! YOU GOT A SCORE OF : %d!!!", score);
		mvwprintw(menu_win, OFFSETY+6, OFFSETX, "  Press enter to continue            ");
		for (int i = 7; i < 14; i++) {
			mvwprintw(menu_win, OFFSETY+i, OFFSETX, "                                     ");
		}
		int closed = 0;
		while(closed == 0) {
			c = wgetch(menu_win);
			switch(c) {
				case 10:
					closed = 1;
					break;
			}
		}

	}
	// wattroff(menu_win, A_REVERSE);
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

//Given a location and sends out a new location of the enemy
//Returns 0 for up, 1 for left, 2 for down, 3 for right
int enemyMove(int board[12][12], int posX, int posY, int dirMoved) {
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
  }gamespeed = 200;

  //Just in case something fails, default case for if nothing happens.
  printf("Uh oh, there was an error");
  return 0;
}

void createEnemy(int gen) {
  if (gen == 1) {
    enemy1X = ENEMGENX;
    enemy1Y = ENEMGENY;
  }
  if (gen == 2) {
    enemy2X = ENEMGENTX;
    enemy2Y = ENEMGENTY;
  }
}

void print_menu(WINDOW *menu_win, int highlight) {
	int x, y, i;

	x = 20;
	y = OFFSETY + 6;
	box(menu_win, 0, 0);
	for (int i = 1; i < 10; i++) {
		mvwprintw(menu_win, i, 5, "                                                      ");
	}
	mvwprintw(menu_win, 10, 29, "          ");
	mvwprintw(menu_win, 10, OFFSETX+2, "     ");
	mvwprintw(menu_win, 11, 32, "   ");
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

void print_menu_speed(WINDOW *menu_win) {
	clear();
	box(menu_win, 0, 0);
	mvwprintw(menu_win, 7, 5, "Change the Game speed using the up and down arrows.", gamespeed);
	mvwprintw(menu_win, 8, 5, "Default is 200. Higher is slower, lower is faster.");
	mvwprintw(menu_win, 9, 20, "              A");
	mvwprintw(menu_win, 10, 20, "GAME SPEED : %d ", gamespeed);
	mvwprintw(menu_win, 11, 20, "              V");
	mvwprintw(menu_win, 12, 20, "                ");
	wrefresh(menu_win);
}
