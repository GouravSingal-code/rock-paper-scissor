#ifndef GAME_HPP
#define GAME_HPP

#include "Computer.hpp"
#include "Human.hpp"
#include "Message.hpp"
#include <memory>

class Game {
private:
  // Object for human player
  std::unique_ptr<Human> humanPlayer;
  // Object for computer player
  std::unique_ptr<Computer> computerPlayer;
  // Object for dis
  std::unique_ptr<Message> logger;
  int roundNumber;
  int numRounds;

public:
  // Constructor for Game class
  Game();
  /*
   * Handles primary gameplay
   */
  void playGame();
  /*
   * Computes winner of current round
   * @param humanMove Move played by human
   * @param computerMove Move played by computer
   * @return winner of the round
   */
  int playRound(const int &humanMove, const int &computerMove) const;
  /*
   * Updates scores of both players
   * @param Winner of the current round
   */
  void updateLeaderboard(const int winnerOfRound) const;
};
#endif