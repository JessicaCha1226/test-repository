#include <stdio.h>

/* 입력개수 n
1..
별갯수 처음 1
공백 2*n -2. 반복마다 -2
for문, n번 반복
2..
큰반복 size
작은반복 size*2
3..
큰반복 size
작은반복 : 공백 별 \n
공백 처음 0, 1--
별 처음 size*2, 2--
*/
int main(){
    int size;
    int stars, blank1, blank2;
    int i, j;

    scanf("%d", &size);
    //1
    stars= 1;
    blank1= 0; 
    blank2= size*2 -2; 
    for(i=0; i<size; i++){
        for(j=0; j<blank1; j++)
            printf(" ");
        printf("*");
        for(j=0; j<blank2 ; j++)
            printf(" ");
        printf("*");
        for(j=0; j<blank1; j++)
            printf(" ");
        blank1++;
        blank2 -=2;
        printf("\n");
    }
    //2
    for(i=0; i<size; i++){
        for(j=0; j<size*2; j++){
            printf("*");
        }
        printf("\n");
    }
/*
    3..
큰반복 size
작은반복 : 공백 별 \n -*
공백 처음 0, 1++
별 처음 size*2, 2--
*/
    //3
    stars= size*2;
    blank1= 0;
    for(i=0; i<size; i++){
        for(j=0; j<blank1; j++)
            printf(" ");
        for(j=0; j<stars; j++)
            printf("*");
        blank1++;
        stars -=2;
        printf("\n");
    }
    //4
    for(i=0; i<size*2; i++)
        printf("*");
}