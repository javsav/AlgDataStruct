#include <string>

class Player {
 
 private:
  std::string name;
  char currentMove;

 public:
  Player();

  Player(std::string name);

  virtual char makeMove() = 0;

  char getMove();

  std::string getName();
};