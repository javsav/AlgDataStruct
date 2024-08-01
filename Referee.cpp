#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {

  Move* player1Move = player1->makeMove();
  Move* player2Move = player2->makeMove();

  // Return tie for incompatible moves
  if (player1Move->checkWin(player2Move) == player2Move && player2Move->checkWin(player1Move) == player1Move) {
    return nullptr;
  }
  
  if (player1Move->checkWin(player2Move) == player1Move) {
    return player1;
  } else if (player1Move->checkWin(player2Move) == player2Move) {
    return player2;
  } else {
    return nullptr;
  }
  
  
}

