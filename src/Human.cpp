#include "Human.hpp"
#include "Message.hpp"

Human::Human(const std::string &playerName) : name(playerName) {}

std::string Human::getName() const { return name; }

int Human::makeMove() {
  std::unique_ptr<Message> message(new Message());
  return message->inputHumanMove();
}