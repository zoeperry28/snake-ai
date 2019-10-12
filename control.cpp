#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include <termios.h>
#include "control.h"
#include "base.h"

int Control::ControlSnake()
{
  int ch;

  Snake snake;
  /* Curses Initialisations */
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  printw("Press E to Exit\n");

  while((ch = getch()) != 'E')
  {
      switch(ch)
      {
      case KEY_UP:
              printw("\nUp Arrow");
              val = 24;
              return val;
      case KEY_DOWN:
              printw("\nDown Arrow");
              val = 25;
              return val;
      case KEY_LEFT:
              printw("\nLeft Arrow");
              val = 26;
              return val;
      case KEY_RIGHT:
              printw("\nRight Arrow");
              val = 27;
              return val;
      default:
              printw("\nThe pressed key is %c",ch);

      }
  }

  printw("\n\Exiting Now\n");
  endwin();
}
