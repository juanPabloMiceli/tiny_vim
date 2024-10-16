#include "window_factory.h"
#include "normal_window.h"
#include "insert_window.h"
#include "command_window.h"
#include "window.h"

#include <memory>

std::shared_ptr<Window> WindowFactory::create(WindowType type, int height, int width, std::shared_ptr<Editor> editor) {
  switch(type) {
    case WindowType::NORMAL_WINDOW:
      return std::make_unique<NormalWindow>(height, width, editor);
    case WindowType::INSERT_WINDOW:
      return std::make_unique<InsertWindow>(height, width, editor);
    case WindowType::COMMAND_WINDOW:
      return std::make_unique<CommandWindow>(height, width, editor);
    default:
      // TODO: This should raise an error
      return std::make_unique<InsertWindow>(height, width, editor);
  }
}
