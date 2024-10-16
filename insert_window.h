#ifndef INSERT_WINDOW_H
#define INSERT_WINDOW_H

#include "window.h"

#include <string>
#include <memory>

class InsertWindow : public Window {
  public:
    InsertWindow(int height, int width, std::shared_ptr<Editor> editor);

    void ProcessCharacter(char new_character) override;
    void Start() override;

  private:
    std::string text_;
    int screen_height_, screen_width_;
    std::shared_ptr<Editor> editor_;
};

#endif  // INSERT_WINDOW_H
