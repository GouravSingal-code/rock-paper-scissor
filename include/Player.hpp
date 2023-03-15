#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
private:
  int score;

public:
  // Constructor for the player class
  Player();
  /*
   * Return score of the player
   */
  int getScore() const;
  /*
   * Updates score of the player
   * @param newScore score of the player after round ends
   */
  void updateScore(const int &newScore);
  virtual int makeMove() = 0;
};
#endif