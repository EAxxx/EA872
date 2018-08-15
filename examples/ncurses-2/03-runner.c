#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>


volatile char keypress;
volatile int keyboard_thread_running;

void *keyboard_thread(void *params)
{
  char c;
  while (keyboard_thread_running == 1) {
    c = getch();
    if (c!=ERR) keypress = c;
    else keypress = 0;
    usleep(10000);
  }
  return NULL;
}

int main()
{

  int i, j, i_, j_;

  char c;
  pthread_t kb_thread;

	initscr();			       /* Start curses mode 		*/
	raw();				         /* Line buffering disabled	*/
	keypad(stdscr, TRUE);	 /* We get F1, F2 etc..		*/
	noecho();			         /* Don't echo() while we do getch */
  curs_set(0);           /* Do not display cursor */

  keyboard_thread_running = 1;
  pthread_create(&kb_thread, NULL, keyboard_thread, NULL);

  i = 0;
  j = 0;
  while (1) {
    i_ = i;
    j_ = j;
    move(i_, j_);   /* Move cursor to position */
    echochar('*');  /* Prints character, advances a position */
    refresh();      /* Refresh screen */

    if (keypress != 0) {
      c = keypress;
      keypress = 0;
      if (c=='q') break;
      if (c=='w') i++;
      if (c=='s') i--;
      if (c=='d') j++;
      if (c=='a') j--;
      if (i<0) i=15;
      if (i>15) i=0;
      if (j<0) j=15;
      if (j>15) j=0;
    }
    usleep(5000);
    move(i_, j_);   /* Move cursor back to position */
    echochar(' ');  /* Erase character by printing a space */
  }

	refresh();			/* Refresh screen */

  keyboard_thread_running = 0;
  pthread_join(kb_thread, NULL);

	endwin();			  /* End curses mode		  */

	return 0;
}
