#include <string>

class Player {
 
 private:
  std::string name;

 public:
  Player();

  Player(std::string name);

  virtual char makeMove() = 0;

  std::string getName();
};