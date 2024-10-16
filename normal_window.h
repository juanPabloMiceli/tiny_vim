#ifndef NORMAL_WINDOW_H
#define NORMAL_WINDOW_H

#include "window.h"

#include <memory>
#include <string>

class NormalWindow : public Window {
  public:
    NormalWindow(int height, int width, std::shared_ptr<Editor> editor);

    void ProcessCharacter(char new_character) override;
    void Start() override;

  private:
    std::string command_;
    int screen_height_, screen_width_;
    std::shared_ptr<Editor> editor_;
};

#endif  // NORMAL_WINDOW_H
