#include <iostream>
#include "play.hpp"

std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
std::string playerLetter[2] = {"X", "O"};
int position = 0;

void drawBoard()
{
  std::cout << "     |     |      \n";

  std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  std::cout << "     |     |      \n";

  std::cout << "\n";
}

void intro()
{
  std::cout << "---Terminal Tic Tac Toe!--- \n \n";

  std::cout << "Player 1: X \n";
  std::cout << "Player 2: O \n";

  std::cout << "Press enter to start! \n";
  std::cin.ignore();
}

void updateBoard()
{
  board[position - 1] = playerLetter[player - 1];
}

bool isWinner()
{
  bool winner = false;
  // rows
  if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")
  {
    winner = true;
  }
  else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ")
  {
    winner = true;
  }
  else if ((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ")
  {
    winner = true;
  }
  // columns
  else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ")
  {
    winner = true;
  }
  else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ")
  {
    winner = true;
  }
  else if ((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ")
  {
    winner = true;
  } // diagonals
  else if ((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ")
  {
    winner = true;
  }
  else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ")
  {
    winner = true;
  }

  return winner;
}

bool filled()
{
  bool filled = true;

  for (int i = 0; i < 9; i++)
  {
    if (board[i] == " ")
    {
      filled = false;
    }
  }

  return filled;
}

void placeLetter()
{
  while (!(std::cin >> position))
  {
    std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
    std::cin.clear();
    std::cin.ignore();
    std::cout << "\n";
  }

  while (board[position - 1] != " ")
  {
    std::cout << "Oops, there's already something there! \n";

    std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";

    std::cin >> position;
    std::cout << "\n";
  }
}

void takeTurn()
{
  while (!filled() && !isWinner())
  {
    std::cout << "It is Player " << player << "'s turn! \n";
    std::cout << "Where would you like to place your " << playerLetter[player - 1] << "? (Num 1 - 9)\n";

    placeLetter();

    std::cout << "\nYou placed it at " << position << "\n";

    updateBoard();

    drawBoard();

    //changing the turn
    if (!isWinner())
    {
      if (player == 1)
      {
        player++;
      }
      else
      {
        player--;
      }
    }
  }
}

void end()
{
  if (isWinner())
  {
    std::cout << "Player " << player << " won! \n";
  }
  else if (filled())
  {
    std::cout << "It's a tie! \n";
  }
}
