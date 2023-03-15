#include "Game.hpp"
#include "Constants.hpp"

Game::Game() {
  logger = std::make_unique<Message>();
  logger->printWelcomeMessage();
  std::string playerName = logger->inputHumanName();
  humanPlayer = std::make_unique<Human>(playerName);
  computerPlayer = std::make_unique<Computer>();
  roundNumber = 1;
  numRounds = logger->inputNumberOfRounds();
}

void Game::playGame() {
  while (roundNumber <= numRounds) {
    logger->printLeaderboard(humanPlayer.get(), computerPlayer.get(),
                             roundNumber);
    int humanMove = humanPlayer->makeMove();
    int computerMove = computerPlayer->makeMove();
    int winnerOfRound = playRound(humanMove, computerMove);

    updateLeaderboard(winnerOfRound);

    roundNumber++;
  }
  logger->printFinalResult(humanPlayer.get(), computerPlayer.get());
}

int Game::playRound(const int &humanMove, const int &computerMove) const {
  int winnerOfRound = 0;

  if (humanMove == computerMove) {
    winnerOfRound = constants::TIE;
  } else if ((humanMove == constants::ROCK &&
              computerMove == constants::SCISSORS) ||
             (humanMove == constants::SCISSORS &&
              computerMove == constants::PAPER) ||
             (humanMove == constants::PAPER &&
              computerMove == constants::ROCK)) {
    winnerOfRound = constants::HUMAN;
  } else {
    winnerOfRound = constants::COMPUTER;
  }

  bool isLastRound = roundNumber == numRounds;
  logger->printRoundResult(winnerOfRound, humanMove, computerMove, isLastRound);

  return winnerOfRound;
}

void Game::updateLeaderboard(const int winnerOfRound) const {
  int newScore = 0;
  if (winnerOfRound == constants::HUMAN) {
    newScore = humanPlayer->getScore() + 1;
    humanPlayer->updateScore(newScore);
  } else if (winnerOfRound == constants::COMPUTER) {
    newScore = computerPlayer->getScore() + 1;
    computerPlayer->updateScore(newScore);
  }
}