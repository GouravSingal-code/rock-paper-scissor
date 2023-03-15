#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "Computer.hpp"
#include "Human.hpp"
#include <iostream>
#include <string>

class Message {
public:
  // Prints game rules and welcome message on startup
  void printWelcomeMessage();

  /*
   * Takes human name as input from the user
   * @return Human name
   */
  std::string inputHumanName();
  /*
   * Takes number of rounds as input from the user
   * @return Number of rounds
   */
  int inputNumberOfRounds();
  /*
   * Takes human move as input from the user
   * @return Human move
   */
  int inputHumanMove();
  /*
   * Prints current scores of the player
   * @param humanPlayer Human player object
   * @param computerPlayer Computer player object
   * @param roundNumber Current round number
   */
  void printLeaderboard(const Human *const humanPlayer,
                        const Computer *const computerPlayer,
                        const int &roundNumber);
  /*
   * Prints result of the current round
   * @param winnerOfRound Winner of the current round
   * @param humanMove Move played by human
   * @param computerMove Move played by computer
   *
   */
  void printRoundResult(const int &winnerOfRound, const int &humanMove,
                        const int &computerMove, const bool &isLastRound);
  /*
   * Prints final result of the game
   * @param humanPlayer Human player object
   * @param computerPlayer Computer player object
   */
  void printFinalResult(const Human *const humanPlayer,
                        const Computer *const computerPlayer);
};
#endif