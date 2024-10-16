#include "window.h"
#include "insert_window.h"
#include "window_factory.h"

#include <ncurses.h>
#include <string>
#include <memory>

InsertWindow::InsertWindow(int height, int width, std::shared_ptr<Editor> editor) :
  text_(""),
  screen_height_(height),
  screen_width_(width), 
  editor_(editor) {
  Start();
};

void InsertWindow::ProcessCharacter(char new_character) {
  if (new_character == 27) {
    //TODO: Change to Normal State
    SwitchTo(editor_, NORMAL_WINDOW, screen_height_, screen_height_);
    return;
  }
  text_.push_back(new_character);
  printw("%c", new_character);
}

void InsertWindow::Start() {
  mvprintw(screen_height_ - 2, 0, "Insert");
  move(0, 0);
}

