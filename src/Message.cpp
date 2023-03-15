#include "Message.hpp"
#include "Constants.hpp"

void Message::printWelcomeMessage() {
  std::cout
      << "WELCOME TO ROCK, PAPER, "
         "SCISSORS!!!\nThe rules "
         "to this "
         "game are "
         "quite simple:\nThe player and the computer both choose one of the "
         "three "
         "objects (Paper, Rock, or Scissors). If both choose the same object, "
         "it is a tie.\nOtherwise, the winner is determined based on the "
         "following rules:\n1. If the player chooses Paper and the computer "
         "chooses Rock, the player wins.\n2. If the player chooses Rock and "
         "the computer chooses Scissors, the player wins.\n3. If the player "
         "chooses Scissors and the computer chooses Paper, the player "
         "wins.\nOtherwise, the computer wins.\nNow that you have understood "
         "the game, let's begin!\n";
}

std::string Message::inputHumanName() {
  std::string playerName = "";
  std::cout << "What should I call you?\n";
  std::getline(std::cin, playerName);
  while (playerName.empty()) {
    std::cout << "Sorry, you didn't enter a name. Please enter your name to "
                 "continue.\n";
    std::getline(std::cin, playerName);
  }
  return playerName;
}

int Message::inputNumberOfRounds() {
  int numRounds = 0;
  std::cout << "How many rounds do you wanna play?\n";
  std::cin >> numRounds;
  while (std::cin.fail() || numRounds <= 0) {
    std::cout << "Please enter a number greater than 0.\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> numRounds;
  }
  return numRounds;
}

int Message::inputHumanMove() {
  int humanMove = 0;
  std::cout << "Make a move:\nPress 1 for Rock.\nPress 2 for Paper.\nPress 3 "
               "for Scissors.\n";
  std::cin >> humanMove;
  while (std::cin.fail() ||
         (humanMove != constants::ROCK && humanMove != constants::PAPER &&
          humanMove != constants::SCISSORS)) {
    std::cout << "Sorry, that's not a valid move! Please try again.\n"
                 "Make a move:\nPress 1 for Rock.\nPress 2 for Paper.\nPress 3 "
                 "for Scissors.\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> humanMove;
  }
  return humanMove;
}

void Message::printLeaderboard(const Human *const humanPlayer,
                               const Computer *const computerPlayer,
                               const int &roundNumber) {
  std::cout << "Round " << roundNumber << " - \n";
  std::cout << "Current scores are:\n"
            << humanPlayer->getName() << ": " << humanPlayer->getScore();
  std::cout << "\nComputer: " << computerPlayer->getScore() << std::endl;
}

void Message::printRoundResult(const int &winnerOfRound, const int &humanMove,
                               const int &computerMove,
                               const bool &isLastRound) {
  std::string showMoveName[3] = {"Rock", "Paper", "Scissors"};
  std::string humanMoveName = showMoveName[humanMove - 1];
  std::string computerMoveName = showMoveName[computerMove - 1];
  std::cout << "You chose " << humanMoveName << ", and the computer chose "
            << computerMoveName << ".\n";
  if (winnerOfRound == constants::HUMAN) {
    std::cout << humanMoveName << " beats " << computerMoveName << ".\n";
    std::cout << "You have won this round!\n";
  } else if (winnerOfRound == constants::COMPUTER) {
    std::cout << computerMoveName << " beats " << humanMoveName << ".\n";
    std::cout << "The computer has won this round!\n";
  } else {
    std::cout << "You both chose " << humanMoveName << ".\n";
    std::cout << "It's a tie!\n";
  }
  std::string checkEnterPressed = "";
  std::getline(std::cin, checkEnterPressed);
  do {
    if (isLastRound) {
      std::cout << "All rounds are complete. Press ENTER to view the result.\n";
    } else {
      std::cout << "Press ENTER to move on to the next round.\n";
    }
    std::getline(std::cin, checkEnterPressed);
  } while (checkEnterPressed.length() != 0);
}

void Message::printFinalResult(const Human *const humanPlayer,
                               const Computer *const computerPlayer) {
  int humanScore = humanPlayer->getScore();
  int computerScore = computerPlayer->getScore();

  std::cout << "Final scores are:\n"
            << humanPlayer->getName() << ": " << humanScore;
  std::cout << "\nComputer: " << computerScore << std::endl;

  if (humanScore > computerScore) {
    std::cout << "Congratulations! You have won the game. You are officially "
                 "declared a Rock-Paper-Scissors expert.\n";
  } else if (computerScore > humanScore) {
    std::cout << "Oh no! you have lost the game. Nice try though!\n";
  } else {
    std::cout
        << "The game has ended in a tie! Still better than losing though.\n";
  }
}
