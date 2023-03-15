#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Player.hpp"
#include <memory>
#include <string>

class Human : public Player {
private:
  std::string name;

public:
  /*
   * Constructor for the Human class
   * @param name Name of the player
   */
  Human(const std::string &playerName);
  /*
   * Returns name of the human
   */
  std::string getName() const;
  /*
   * Fetches human move input
   */
  int makeMove();
};
#endif