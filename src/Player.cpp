#include "Player.hpp"

Player::Player() { score = 0; }

int Player::getScore() const { return score; }

void Player::updateScore(const int &newScore) { score = newScore; }