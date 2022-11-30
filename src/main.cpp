
#include <iostream>
#include <memory>

#include "logger.h"
#include "game.h"

int main(int argc, char *argv[])
{
  Logger::LogLibrary("MAIN", "START()");
  std::unique_ptr<Game> game = std::make_unique<Game>();
  game->Run();
  Logger::LogLibrary("MAIN", "END()");
  return 0;
}