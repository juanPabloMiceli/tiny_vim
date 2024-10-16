#ifndef COMMAND_WINDOW_H
#define COMMAND_WINDOW_H

#include "window.h"

#include <string>
#include <memory>

class CommandWindow : public Window {
  public:
    CommandWindow(int height, int width, std::shared_ptr<Editor> editor);

    void ProcessCharacter(char new_character) override;
    void Start() override;

  private:
    std::string command_;
    int screen_height_, screen_width_;
    std::shared_ptr<Editor> editor_;

    void ProcessCommand();
};

#endif  // COMMAND_WINDOW_H
