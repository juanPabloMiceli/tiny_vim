#include "normal_window.h"
#include "window.h"

#include <ncurses.h>
#include <string>
#include <memory>

NormalWindow::NormalWindow(int height, int width, std::shared_ptr<Editor> editor) :
  command_(""),
  screen_height_(height),
  screen_width_(width),
  editor_(editor) {
  Start();
};

void NormalWindow::ProcessCharacter(char new_character) {
  if (new_character == ':') {
    //TODO: Change to Command State
    SwitchTo(editor_, COMMAND_WINDOW, screen_height_, screen_height_);
    return;
  } else if (new_character == 'i') {
    //TODO: Change to Insert State
    return;
  }
  return;
}

void NormalWindow::Start() {
  mvprintw(screen_height_ - 2, 0, "Normal");
}
