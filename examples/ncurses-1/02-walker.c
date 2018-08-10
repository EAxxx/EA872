#include <ncurses.h>
#include <unistd.h>

int main()
{

	initscr();			       /* Start curses mode 		*/
	raw();				         /* Line buffering disabled	*/
	keypad(stdscr, TRUE);	 /* We get F1, F2 etc..		*/
	noecho();			         /* Don't echo() while we do getch */
  curs_set(0);           /* Do not display cursor */

  for (int i=0; i<20; i++) {
    move(i, i*2);   /* Move cursor to position */
    echochar('*');  /* Prints character, advances a position */
    refresh();      /* Refresh screen */
    usleep(100000);
    move(i, i*2);   /* Move cursor back to position */
    echochar(' ');  /* Erase character by printing a space */
  }

	refresh();			/* Refresh screen */
	endwin();			  /* End curses mode		  */

	return 0;
}
