#ifndef __BASE_H__
#define __BASE_H__ 

char board [32] [32];
char  start_of_snake_V;
char start_of_snake_H;

char * snake = new char[30] ;
int snake_size = 3;

void create_Snake ();

void add_Food ();

char create_Board ();

#endif

