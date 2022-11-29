
#include <iostream>

#include "logger.h"
#include "game.h"

int main(int argc, char *argv[])
{
  Logger::LogLibrary("MAIN", "START()");
  Game * game = new Game();
  game->Run();
  Logger::LogLibrary("MAIN", "END()");
  return 0;
}