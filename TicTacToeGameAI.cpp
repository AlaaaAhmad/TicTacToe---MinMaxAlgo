#include <bits/stdc++.h>
using namespace std;

//Drawing the board
void drawBoard(string board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"["<<board[i][j]<<"]";
        }
        cout<<endl;
    }

}

//Checking the winner
int checkWinner(string board[3][3])
{

    //Checking the rows
    for(int i = 0; i < 3; i++)
    {
          if (board[i][0] == board[i][1] and board[i][0] == board[i][2] and board[i][0] != " ")
          {
              if (board[i][0] == "X") return 2;
              else if (board[i][0] == "O") return -2;
          }
    }

    //Checking the columns
      for(int i = 0; i < 3; i++)
    {
          if (board[0][i] == board[1][i] and board[0][i] == board[2][i] and board[0][0] != " ")
          {
              if (board[0][i] == "X") return 2;
              else if (board[0][i] == "O") return -2;
          }
    }
    //Checking the first Diagonal

    if (board[0][0] == board[1][1] and board[0][0] == board[2][2] and board[0][0] != " ")
    {
        if (board[0][0] == "X") return 2;
        else if (board[0][0] == "O") return -2;
    }

    //Checking the second Diagonal
    if (board[0][2] == board[1][1] and board[0][2] == board[2][0] and board[0][2] != " ")
    {
        if (board[0][2] == "X") return 2;
        else if (board[0][2] == "O") return -2;
    }


   //Checking the tie case
   bool tie = true;
   for (int i = 0; i < 3; i++)
   {
       for (int j = 0; j < 3; j++)
       {
           if(board[i][j] == " ")
           {
               tie = false;
           }
       }
   }
   if (tie) return 0;
   else return 1;


}

// MiniMax Algorithm
int minimax (string board[3][3], int depth, bool isMaximizing, bool firstTurn = true)
{
     int winner = checkWinner(board);
     if (winner != 1 or depth == 0)
        return winner;
    if (isMaximizing)
    {
     int finalScore = -20;
     int finalRow, finalCol;
     for (int i = 0; i < 3; i++)
      {
       for (int j = 0; j < 3; j++)
       {
          if (board[i][j] == " ")
          {
              board[i][j] = "X";
              int score = minimax(board,depth-1, false,false);
              board[i][j] = " ";
              if (finalScore < score)
              {
                  finalScore = score;
                  finalRow = i;
                  finalCol = j;
              }
          }
       }
     }
     if (firstTurn)
     {
         board[finalRow][finalCol] = "O";
     }
     return finalScore;
    }
    else
    {
     int finalScore = 20;
     int finalRow, finalCol;
     for (int i = 0; i < 3; i++)
      {
       for (int j = 0; j < 3; j++)
       {
          if (board[i][j] == " ")
          {
              board[i][j] = "O";
              int score = minimax(board,depth-1, true,false);
              board[i][j] = " ";
              if (score<finalScore)
              {
                  finalScore = score;
                  finalRow = i;
                  finalCol = j;
              }
          }
       }
     }
     if (firstTurn)
     {
         board[finalRow][finalCol] = "O";
     }
     return finalScore;
    }

}

int main ()
{

    string board[3][3] = {{" "," "," "},{" "," "," "},{" "," "," "}};
    cout<<"Welcome to the Tic Tac Toe game!"<<endl;
    string player = "X";
    drawBoard(board);
    int row,col;
    bool hasWinner = false;
    while(!hasWinner)
    {
        cout<<"Please, Enter a row from 0 to 2"<<endl;
        cin>>row;
        cout<<"Please, Enter a column from 0 to 2"<<endl;
        cin>>col;
        if (board[row][col] == " ")
         {
           board[row][col] = player;
           int result = minimax(board, 100,false);
           drawBoard(board);
        if (checkWinner(board) != 1)
        {
            hasWinner = true;
        }
         }
         else
         {
             cout<<"The cell already have a value"<<endl;
         }
    }
  int result = checkWinner(board);
  if (result == 2) cout<<"The winner is Player X!"<<endl;
  else if (result == -2) cout<<"The winner is Player O!"<<endl;
  else cout<<"No winner! It's a tie!"<<endl;




}
