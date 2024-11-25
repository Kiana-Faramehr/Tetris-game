#include "game.c"
void printboard(char board[20][40],int score2);
void zorro(int x,int y,char board[20][40]);
void line(int x,int y,char board[20][40]);
void opposite_T(int x,int y,char board[20][40]);
void square(int x,int y,char board[20][40]);
int random_shape(int z,char board[20][40]);
void comming_down(int x,int y,char board[20][40],int z);
void go_right(int x,int y,char board[20][40],int z);
void go_left(int x,int y,char board[20][40],int z);
int check_stop(int x,int y,char board[20][40],int z);
int clear_row(char board[20][40],int z,int score,int h);