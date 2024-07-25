#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {

  char player1Move = player1->makeMove();
  char player2Move = player2->makeMove();

  // Player 1 move is rock
  if (player1Move == 'R') {
    if (player2Move == 'R') {
      return nullptr;
    } else if (player2Move == 'P') {
      return player2;
    } else if (player2Move == 'S') {
      return player1;
    }
  }

  // Player 1 move is paper
  if (player1Move == 'P') {
    if (player2Move == 'R') {
      return player1;
    } else if (player2Move == 'P') {
      return nullptr;
    } else if (player2Move == 'S') {
      return player2;
    }
  }

  // Player 1 move is scissors
  if (player1Move == 'S') {
    if (player2Move == 'R') {
      return player2;
    } else if (player2Move == 'P') {
      return player1;
    } else if (player2Move == 'S') {
      return nullptr;
    }
  }
  
  return nullptr;
}

