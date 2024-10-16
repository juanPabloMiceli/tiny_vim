#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include "window.h"

#include <memory>

class Window;
class Editor;

enum WindowType {
  NORMAL_WINDOW,
  INSERT_WINDOW,
  COMMAND_WINDOW
};

class WindowFactory {
  public:
    std::shared_ptr<Window> create(WindowType type, int height, int width, std::shared_ptr<Editor> editor);
};

#endif  // WINDOW_FACTORY_H
