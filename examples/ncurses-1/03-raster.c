#include <ncurses.h>
#include <unistd.h>

int main()
{
  float xpos=0, ypos=0;
  float xvel=1, yvel=30;
  float yaccel=-7.;

  int oldi=0, oldj=0, newi=0, newj=0;

	initscr();			       /* Start curses mode 		*/
	raw();				         /* Line buffering disabled	*/
	keypad(stdscr, TRUE);	 /* We get F1, F2 etc..		*/
	noecho();			         /* Don't echo() while we do getch */
  curs_set(0);           /* Do not display cursor */

  while (newi < 40) {
    move(newi, newj);   /* Move cursor to position */
    echochar('*');  /* Prints character, advances a position */
    refresh();      /* Refresh screen */
    usleep(1000);

    /* Physical model running */
    xpos += xvel/100;
    ypos += yvel/100;
    yvel += yaccel/100;
    if (ypos<0) {
      ypos *= -1;
      yvel *= -0.8;
    }

    oldi = newi;
    oldj = newj;

    newi = (int)xpos;
    newj = (int)ypos;

    move(oldi, oldj);   /* Move cursor back to position */
    echochar(' ');  /* Erase character by printing a space */
  }

	refresh();			/* Refresh screen */
	endwin();			  /* End curses mode		  */

	return 0;
}
