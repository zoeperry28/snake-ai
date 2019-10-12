#include <stdio.h>

#include <iostream>
#include <cstdlib>
#include "base.h"
using namespace std;


void control_Snake ()
{



}

void create_Snake ()
{
  for ( int i = 0 ; i < snake_size; i++ )
  {
    snake[i] = '$';
  }
}

void add_Food ()
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

  printf("%x\n%x\n", start_of_snake_V, start_of_snake_H);
  }


char create_Board () {

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
        board[i][j] = '-';
      }

    }
  }

  add_Food() ;

      cout<<"\n Two Dimensional Array is : \n";
      for(i=0; i<32; i++)
      {
        for(j=0; j<32; j++)
         {
           cout<<" "<<board[i][j]<<" ";
         }
          cout<<"\n";
       }

       return 1;

}



int main ()
{

  create_Board();


  return 1;
}
