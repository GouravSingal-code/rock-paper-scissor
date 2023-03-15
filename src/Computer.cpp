#include "Computer.hpp"

Computer::Computer() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  rng.seed(seed);
}

int Computer::makeMove() {
  uniformDistribution dist3(1, 3);
  return dist3(rng);
}
