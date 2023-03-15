#include "Game.hpp"
#include <memory>

int main() {
  std::unique_ptr<Game> game(new Game());
  game->playGame();
}