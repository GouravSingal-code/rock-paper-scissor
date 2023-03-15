#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Player.hpp"
#include <chrono>
#include <random>

typedef std::uniform_int_distribution<std::mt19937::result_type>
    uniformDistribution;
typedef std::mt19937 RNG;

class Computer : public Player {
private:
  // Random Number Generator
  RNG rng;

public:
  /*
   * Constructor for Computer class which seeds the
   * RNG on instantiation
   */
  Computer();
  /*
   * Makes a random move using RNG
   * @return Random integer between 1 and 3
   */
  int makeMove();
};
#endif