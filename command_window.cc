#include "command_window.h"

#include <ncurses.h>
#include <string>
#include <memory>


CommandWindow::CommandWindow(int height, int width, std::shared_ptr<Editor> editor) :
  command_(""),
  screen_height_(height),
  screen_width_(width),
  editor_(editor) {
  Start();
};

void CommandWindow::ProcessCharacter(char new_character) {
  if (new_character == '\n') {
    ProcessCommand();
    move(screen_height_ - 1, 0);
    clrtoeol(); 
    command_ = "";
    //TODO: Change to Normal State
  } else {
    if (command_ == "") {
      move(screen_height_ - 1, 0);
    }
    command_.push_back(new_character);
    printw("%c", new_character);
  }
}

void CommandWindow::Start() {
  mvprintw(screen_height_ - 2, 0, "Command");
  mvprintw(screen_height_ - 1, 0, ":");
}

void CommandWindow::ProcessCommand() {
  //TODO: Add commands
  return;
}
