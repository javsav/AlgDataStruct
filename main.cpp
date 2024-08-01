#include "Player.h"
#include "Human.h"
#include "Referee.h"
#include "Computer.h"

int main() {

  std::cout << "Rock Paper Scissors\n";

  std::cout << "1. Player vs Player (PVP)\n";
  std::cout << "2. Player vs Computer (PVE)\n";

  int versus;

  std::cin >> versus;

  std::string name1;
  std::string name2;
  // Create players on the stack //
  Human player1;
  Human player2;
  Computer computer;
  Referee referee;

  if (versus == 1) {
    std::cout << "Enter Player 1 Name\n";
    std::cin >> name1;
    std::cout << "Enter Player 2 Name\n";
    std::cin >> name2;

    player1.setName(name1);
    player2.setName(name2);
  } else {
    std::cout << "Enter Player 1 Name\n";
    std::cin >> name1;
    player1.setName(name1);
  }

  // Player 1 is always Human //
  Player* p1 = &player1;  
  Player* p2;
  // Player 2 pointer can point to Human or Computer //
  if (versus == 1) {
    p2 = &player2;
  } else {
    p2 = &computer;
  }

  int numRounds = 0;

  std::cout << "Enter number of rounds: ";
  std::cin >> numRounds;

  int currentRound = 0;
  int p1Score = 0;
  int p2Score = 0;

  while (currentRound < numRounds) {
    
    Player* round = referee.refGame(p1, p2);

    if (round == p1) {
      std::cout << "\n" << p1->getName() << " Wins\n\n";
      p1Score ++;
    } else if (round == p2) {
      std::cout << p2->getName() << " Wins\n\n";
      p2Score ++;
    } else {
      std::cout << "\n" << "\nIt's a Tie\n\n";
    }

    std::cout << "Player 1 score: " << p1Score << "\n";
    std::cout << "Player 2 score: " << p2Score << "\n";
    currentRound ++;
  }


}