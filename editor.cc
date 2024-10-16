#include "editor.h"
#include "window_factory.h"
#include "window.h"

#include <ncurses.h>
#include <string>
#include <memory>

Editor::Editor() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  int height, width;
  getmaxyx(stdscr, height, width);
  std::shared_ptr<Window> window_ = WindowFactory().create(WindowType::NORMAL_WINDOW, height, width, shared_from_this());
};

void Editor::Start() {
  while (true) {
    window_->ProcessCharacter(static_cast<char>(getch()));
  }
  endwin();
}

void Editor::SetWindowState(std::shared_ptr<Window> new_window) {
  window_ = new_window;
}
