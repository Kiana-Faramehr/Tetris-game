#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "game.h"
#define PI 3.14159265358979323846
int main(){
    int score=0;                            
    int time2=750;
    int x=1,y=17;
    char board[20][40];                     //Defining our board
    for(int i=0;i<20;i++){
        for(int j=0;j<40;j++){              //Removing garbage values
            board[i][j]=' ';
        }
    }
    int rand=random_number();
    if(rand==0){
        y=17;
    }else if(rand==1){
        y=19;
    }else if(rand==2){
        y=17;
    }else{
        y=19;
    }
    random_shape(rand,board);               //Generating a random shape
    while(1){
        printboard(board,score);            //Printing the board and waiting for a period which is given by the user
        Sleep(time2);                       
        comming_down(x,y,board,rand);
        x=x+1;
        if(kbhit()){                        //beresi vojood input va anjam amaliat dar soorat niaz
            char input=getch();             //checking for any input or keyboard hit and taking action
            switch(input){
                case 'a':
                    if(rand==1){
                        if(y>3){
                            go_left(x,y,board,rand);
                            y=y-2; 
                        }
                    }
                    else if(rand==0){ 
                        if(y>0){
                            go_left(x,y,board,rand);
                            y=y-2;
                        }
                    }else{
                        if(y>1){
                            go_left(x,y,board,rand);
                            y=y-2;
                        }
                    }
                break;
                case 'd':
                    if(rand==1||rand==3){
                        if(y<36){
                            go_right(x,y,board,rand);
                            y=y+2;
                        }
                    }else{
                        if(y<32){
                            go_right(x,y,board,rand);
                            y=y+2; 
                        }
                    }       
                break;
                case 's':
                    if(time2>300){
                        time2=time2-100;
                    }else{
                        time2=200;
                    }
                break;
                default:
                    printf("wrong input");
                    Sleep(2000);
                break;
            }           
        }
        int i=0;
        int j=0;
        int k=0;
        int f=0;
        int key3=5;
        for(i=0;i<20;i++){
            key3=5;
            for(j=0;j<40;j++){
                if(board[i][j]==' '){           //Checking if a line is complete or not and giving points to the user
                    key3=0;
                    break;
                }
            }
            if(key3!=0){
                score=clear_row(board,rand,score,i);
            }
        }
        if(key3==0){
            system("cls");
            if(check_stop(x,y,board,rand)){         //Checking when the movement of a shape is over and generating the next shape
                rand=random_number();               
                time2=750;
                if(random_shape(rand,board)==0){    //Generating random shapes and checking if the game is over or not
                    printboard(board,score);
                    printf("\n                game over");
                    printf("\n        please press ctrl+c to exit");
                    break;
                }
                x=1;
                if(rand==0){
                    y=17;
                }else if(rand==1){
                    y=19;
                }else if(rand==2){
                    y=17;
                }else{
                    y=19;
                }
            }
        }
    }
    while(1){}
}