#include <ncurses.h>
#include <unistd.h>

int main()
{

  int i, j, i_, j_;
  char c;

	initscr();			       /* Start curses mode 		*/
	raw();				         /* Line buffering disabled	*/
	keypad(stdscr, TRUE);	 /* We get F1, F2 etc..		*/
	noecho();			         /* Don't echo() while we do getch */
  curs_set(0);           /* Do not display cursor */

 i = 0;
 j = 0;
 for (int k=0; k<20; k++) {
    i_ = i;
    j_ = j;
    move(i_, j_);   /* Move cursor to position */
    echochar('*');  /* Prints character, advances a position */
    refresh();      /* Refresh screen */

    c = getch();

    if (c=='w') i++;
    if (c=='s') i--;
    if (c=='d') j++;
    if (c=='a') j--;
    if (i<0) i=15;
    if (i>15) i=0;
    if (j<0) j=15;
    if (j>15) j=0;

    move(i_, j_);   /* Move cursor back to position */
    echochar(' ');  /* Erase character by printing a space */
  }

	refresh();			/* Refresh screen */
	endwin();			  /* End curses mode		  */

	return 0;
}
