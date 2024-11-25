#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "random.h"
#define PI 3.14159265358979323846
void printboard(char board[20][40],int score2){             //Print board function(2D array)
    int score=score2;
    int i;
    for(i=0;i<20;i++){
        printf("|");
        for(int j=0;j<40;j++){
            printf("%c",board[i][j]);
            if(j==39){
                printf("|");
                if(i==0){
                    printf("score=%d\n",score);
                }else{
                    printf("\n");
                }
            }
        }
    }
    for(i=0;i<21;i++){
        printf("- ");
    }
}
//////////////////
void zorro(int x,int y,char board[20][40]){                // Z shape function 
    int i=0;
    int k=0;
    while(k<2){
        for(i=y-1;i<y+3;i=i+2){
                board[x-1][i]='[';
            }
        for(i=y;i<y+4;i=i+2){
            board[x-1][i]=']';
        }    
        k=k+1;
        x=x+1;
        y=y+2;
    }
}
//////////////////
void opposite_T(int x,int y,char board[20][40]){            // Opposite T shape function
    int i=0;
    board[x-1][y-1]='[';
    board[x-1][y]=']';
    for(i=y-3;i<=y+2;i=i+2){
        board[x][i]='[';
    }
    for(i=y-2;i<=y+2;i=i+2){
        board[x][i]=']';
    }   
}
//////////////////
void line(int x,int y,char board[20][40]){                  // Line shape function
    int i=0;
    int j=0;
    for(i=y-1;i<y+7;i=i+2){
        board[x-1][i]='[';
    }
    for(i=y;i<y+7;i=i+2){
        board[x-1][i]=']';
    }
}
//////////////////
void square(int x,int y,char board[20][40]){                // Square shape function
    int k=0;
    int i=0;
    int j=0;
    while(k<2){
        for(i=y-1;i<y+3;i=i+2){
            board[x-1][i]='[';
        }
        for(i=y;i<y+3;i=i+2){
            board[x-1][i]=']';
        }
        x=x+1;
        k=k+1;
    }
}
//////////////////
int random_shape(int z,char board[20][40]){    // This function generates random shapes and check if the game is over or not
    int key2=5;                                                                     
    switch(z){
        case 0:
            int x=1;
            int y=17;
            int k=0;
            int i=0;
            while(k<2){
                for(i=y-1;i<y+3;i=i+2){
                    if(board[x-1][i]=='['){
                        key2=0;
                        break;
                    }
                }
                if(key2==0){
                    break;
                }
                for(i=y;i<y+4;i=i+2){
                    if(board[x-1][i]==']'){
                        key2=0;
                        break;
                    }
                }
                if(key2==0){
                    break;
                }    
                k=k+1;
                x=x+1;
                y=y+2;
            }
            if(key2!=0){
                zorro(1,17,board);
            }
        break;
        case 1:
            x=1;
            y=19;
            i=0;
            key2=5;
            if(board[x-1][y-1]=='['){
                key2=0;
            }
            if(board[x-1][y]==']'){
                key2=0;
            }
            for(i=y-3;i<=y+2;i=i+2){
                if(board[x][i]=='['){
                    key2=0;
                    break;
                }
            }
            for(i=y-2;i<=y+2;i=i+2){
                if(board[x][i]==']'){
                    key2=0;
                    break;
                }
            }
            if(key2!=0){ 
                opposite_T(1,19,board);
            }
        break;
        case 2:
            x=1;
            y=17;
            i=0;
            key2=5;
            for(i=y-1;i<y+7;i=i+2){
                if(board[x-1][i]=='['){
                    key2=0;
                    break;
                }
            }
            for(i=y;i<y+7;i=i+2){
                if(board[x-1][i]==']'){
                    key2=0;
                    break;
                }
            }
            if(key2!=0){
                line(1,17,board);
            }
        break;
        case 3:
            x=1;
            y=19;
            k=0;
            i=0;
            key2=5;
            while(k<2){
                for(i=y-1;i<y+3;i=i+2){
                    if(board[x-1][i]=='['){
                        key2=0;
                        break;
                    }
                }
                for(i=y;i<y+3;i=i+2){
                    if(board[x-1][i]==']'){
                        key2=0;
                        break;
                    }
                }
                x=x+1;
                k=k+1;
            }
            if(key2!=0){
                square(1,19,board);
            }
        break;
        default:
        break;
    }
    return key2;
}
void comming_down(int x,int y,char board[20][40],int z){        //Coming down function
    switch(z){
        case 0:
            int i=0;
            int k=0;
            while(k<2){
                for(i=y-1;i<y+5;i++){
                    board[x-1][i]=' ';
                }
                k=k+1;
                x=x+1;
                y=y+2;
            }
            zorro(x-1,y-2,board);
        break;
        case 1:
            i=0;
            board[x-1][y-1]=' ';
            board[x-1][y]=' ';
            for(i=y-3;i<=y+2;i++){
                board[x][i]=' ';
            }
            opposite_T(x+1,y,board);
        break;
        case 2:
            i=0;
            int j=0;
            for(i=y-1;i<y+7;i++){
                board[x-1][i]=' ';
            }
            line(x+1,y,board);
        break;
        case 3:
            k=0;
            i=0;
            j=0;
            while(k<2){
                for(i=y-1;i<y+3;i++){
                    board[x-1][i]=' ';
                }
                x=x+1;
                k=k+1;
            }
            square(x-1,y,board);    
        break;
        default:
        break;
        }
}
void go_right(int x,int y,char board[20][40],int z){        //Going right function
    switch(z){
        case 0:
            int i=0;
            int k=0;
            while(k<2){
                for(i=y-1;i<y+5;i++){
                    board[x-1][i]=' ';
                }
                k=k+1;
                x=x+1;
                y=y+2;
            }
            zorro(x-2,y,board);
        break;
        case 1:
            i=0;
            board[x-1][y-1]=' ';
            board[x-1][y]=' ';
            for(i=y-3;i<=y+2;i++){
                board[x][i]=' ';
            }
            opposite_T(x,y+2,board);
        break;
        case 2:
            i=0;
            int j=0;
            for(i=y-1;i<y+7;i++){
                board[x-1][i]=' ';
            }
            line(x,y+2,board);
        break;
        case 3:
            k=0;
            i=0;
            j=0;
            while(k<2){
                for(i=y-1;i<y+3;i++){
                    board[x-1][i]=' ';
                }
                x=x+1;
                k=k+1;
            }
            square(x-2,y+2,board);    
        break;
        default:
        break;
    }
}
void go_left(int x,int y,char board[20][40],int z){             //Going left function  
    switch(z){
        case 0:
            int i=0;
            int k=0;
            while(k<2){
                for(i=y-1;i<y+5;i++){
                    board[x-1][i]=' ';
                }
                k=k+1;
                x=x+1;
                y=y+2;
            }
            zorro(x-2,y-4,board);
        break;
        case 1:
            i=0;
            board[x-1][y-1]=' ';
            board[x-1][y]=' ';
            for(i=y-3;i<=y+2;i++){
                board[x][i]=' ';
            }
            opposite_T(x,y-2,board);
        break;
        case 2:
            i=0;
            int j=0;
            for(i=y-1;i<y+7;i++){
                board[x-1][i]=' ';
            }
            line(x,y-2,board);
        break;
        case 3:
            k=0;
            i=0;
            j=0;
            while(k<2){
                for(i=y-1;i<y+3;i++){
                    board[x-1][i]=' ';
                }
                x=x+1;
                k=k+1;
            }
            square(x-2,y-2,board);    
        break;
        default:
        break;
    }
}
int check_stop(int x,int y,char board[20][40],int z){           //In this function the shape will stop moving at the right time and spot
    int key=5;
    switch (z){
        case 0:
            int i=0;
            for(i=y+3;i<y+7;i++){
                if(board[x+1][i]==']'){
                    key=1;
                    break;
                }else if(x==19){
                    key=1;
                    break;
                }else {
                    key=0;
                }
            }
            if(key==0){
                i=0;
                //for(i=y+3;i<=y+4;i++){
                    if(board[x+1][y+2]==']'){
                        comming_down(x,y,board,0);
                        key=1;
                    }
                //}   
            }
        break;    
        case 1:
            i=0;
            for(i=y-3;i<=y+2;i++){
                if(board[x+1][i]==']'){
                    key=1;
                    break;
                }else if(x==19){
                    key=1;
                    break;
                }else{
                    key=0;
                }
            }       
        break;
        case 2:
            i=0;
            for(i=y-1;i<y+7;i++){
                if(board[x][i]=='['){
                    key=1;
                    break;
                }else if(x==20){
                    key=1;
                    break;
                }else{
                    key=0;
                }
            }
        break;
        case 3:
            i=0;
            for(i=y-1;i<y+3;i++){
                if(board[x+1][i]=='['){
                    key=1;
                    break;
                }else if(x==19){
                    key=1;
                    break;
                }else{
                    key=0;
                }
            }
        break;
        default:
        break;
    }
    return key;
}
int clear_row(char board[20][40],int z,int score,int h){            //This function will delete the completed row and give points to the user
    char fake_board[20][40];                                         
    int k=0;
    int f=0;
            for(k=0;k<40;k++){
                board[0][k]=' ';
            }
            for(k=0;k<20;k++){
                for(f=0;f<40;f++){
                    fake_board[k][f]=board[k][f];
                }
            }
            for(k=1;k<=h;k++){
                for(f=0;f<40;f++){
                    board[k][f]=fake_board[k-1][f];
                }
            }
    score=score+10;
    return score;
}