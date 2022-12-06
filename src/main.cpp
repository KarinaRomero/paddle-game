
#include <iostream>
#include <memory>

#include "logger.h"
#include "game_controller.h"

int main(int argc, char *argv[])
{
  Logger::LogLibrary("MAIN", "START()");
  std::unique_ptr<GameController> gameController = std::make_unique<GameController>();
  gameController->Run();
  Logger::LogLibrary("MAIN", "END()");
  return 0;
}