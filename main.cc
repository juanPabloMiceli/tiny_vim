#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>

int main() {
  int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
  while(true) {
    ch = getch();
    if (ch == KEY_BACKSPACE) {
      break;
    }
    printw("%c", ch);
    refresh();
  }
	endwin();

	return 0;
}
