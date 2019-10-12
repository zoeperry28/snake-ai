#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "base.h"
#include "control.h"
using namespace std;

int test;

void Snake::create_Snake ()
{
  for ( int i = 0 ; i < snake_size; i++ )
  {
    snake[i] = '$';
  }
}

void Snake::add_Food ()
{
  int j, k;
  char * p;
  srand (time(NULL));

/* generate secret number between 1 and 10: */
  j = rand() % 30 + 1;
  k = rand() % 30 + 1;
  board[j][k] = '%' ;

  start_of_snake_V = rand() % 30 + 1;
  start_of_snake_H = rand() % 30 + 1;
  board[start_of_snake_V][start_of_snake_H] = '$' ;


  }


char Snake::create_Board (int dst) {

  int i, j ;

  for (int i = 0; i < 32; i++ )
  {
    for (int j = 0; j < 32; j++ )
    {

      if ( i == 0 ^ j == 0 || i == 31 ^ j == 31)
      {
         board[i][j] = '*' ;
      }
      else
      {
        board[i][j] = ' ';
      }

    }
  }

  add_Food() ;

      for(i=0; i<32; i++)
      {
        for(j=0; j<32; j++)
         {
           std::cout << board[i][j] ;
         }
          cout<<"\n";
       }

       return 1;

}

void Snake::move_Snake ( )
{
  Control con;
  Snake s;
  int x;
  x = con.ControlSnake();

  printf("%i",x );

  switch (x) {
      case 24:
        test = 24;
        start_of_snake_V++;

        break;
      case 25:
        //DOWN
        test = 25;
        start_of_snake_V--;
        break;
      case 26:
        //LEFT
        test=26;
        start_of_snake_H++;
        break;
      case 27:
        //RIGHT
        test = 27;
        start_of_snake_H--;
        break;


  }
}

int main ()
{

  Snake s; Control c;

  s.move_Snake();
  s.create_Board(test);

  return 1;
}
