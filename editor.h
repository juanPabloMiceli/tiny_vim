#ifndef EDITOR_H
#define EDITOR_H

#include "window.h"

#include <memory>

class Window;

class Editor : public std::enable_shared_from_this<Editor> {
  public:
    Editor();

    void Start();
    void SetWindowState(std::shared_ptr<Window> new_window);

  private:
    std::shared_ptr<Window> window_;
};

#endif  // EDITOR_H
