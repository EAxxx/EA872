#include <ncurses.h>

int main()
{
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}

/* Compilacao:
 * 1) Instale a biblioteca ncurses:
 * sudo apt-get install libncurses5-dev
 *
 * 2) Compile com link para ncurses:
 * gcc -ohello 01-helloworld.c -lncurses */
