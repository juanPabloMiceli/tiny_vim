#ifndef WINDOW_H
#define WINDOW_H

#include "editor.h"
#include "window_factory.h"

#include <memory>
#include <string>

class Window {
  public:
    virtual ~Window() = default;
    virtual void ProcessCharacter(char new_character) = 0;
    virtual void Start() = 0;
    virtual void SwitchTo(std::shared_ptr<Editor> editor, WindowType type, int height, int width) {
      editor->SetWindowState(WindowFactory().create(type, height, width, editor));
    }
};

#endif  // WINDOW_H
