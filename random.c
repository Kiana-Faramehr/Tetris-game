#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846
int random_number(){
    srand(clock() +time(NULL)+ PI);     //Getting a random number
    return rand()%4;
}