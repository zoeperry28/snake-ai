#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "base.h"
#include "control.h"
using namespace std;

int init = 0 ;
int food = 0 ;
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

  if (food == 0 )
  {
    j = rand() % 30 + 1;
    k = rand() % 30 + 1;
    board[j][k] = '%' ;
    food++;
  }

  if (init == 0)
  {
    start_of_snake_V = rand() % 30 + 1;
    start_of_snake_H = rand() % 30 + 1;
    board[start_of_snake_V][start_of_snake_H] = '$' ;
    init = 1;

  } else {

    board [start_of_snake_V][start_of_snake_H] = ' ' ;

    if (start_of_snake_V <= 30 )
    {
      start_of_snake_V++;
    }
    else {
      start_of_snake_V = 1;
    }

    if (start_of_snake_H <= 30 )
    {
    start_of_snake_H++;
    }
    else {
      start_of_snake_H = 1;
    }

  }

  board[start_of_snake_V][start_of_snake_H] = '$' ;

  }


char Snake::create_Board () {

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

    while (1)
    {
      add_Food() ;

          printf("\n" );
          for(i=0; i<32; i++)
          {
            for(j=0; j<32; j++)
             {
               std::cout << board[i][j] << ' ';
             }
              cout<<"\n";
           }

         }
           return 1;


}
void move_Snake ( )
{
}

int main ()
{

  Snake s; Control c;
  s.create_Board();


  return 1;
}
