#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {

  Move* player1Move = player1->makeMove();
  Move* player2Move = player2->makeMove();

  if (player1Move->checkWin(player2Move) == 'W') {
    return player1;
  } else if (player1Move->checkWin(player2Move) == 'L') {
    return player2;
  } else {
    return nullptr;
  }
  
  
}

