#include <stdio.h>
#include "board.h"

void init_board(char board[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            board[i][j]='.';
        }
    }
}
void print_board(char board[5][5]){
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        printf("%c",board[i][j]);
    }
    printf("\n");
}
printf("\n");
}
int is_valid_move(int r1, int c1, int r2, int c2){
    if(r1<0||r1>=5||c1<0||c1>=5)return 0;
    if(r2<0||r2>=5||c2<0||c2>=5)return 0;
    if(abs(r1-r2) + abs(c1-c2)!=1)return 0;
    return 1;
}
void apply_move(char board[5][5],int r1, int c1, int r2, int c2){
    int mr= (r1+r2)/2;
    int mc= (c1+c2)/2;
        if(board[mr][mc] == '*'){
            return 0;
        }
        board[mr][mc]='*';
}
int check_box(char board[5][5], int r, int c){
    if(r<=0||r>=4||c<=0||c>=4)return 0;
    if(board[r-1][c]=='*' &&
       board[r+1][c]=='*' &&
       board[r][c-1]=='*' &&
       board[r][c+1]=='*'){
        return 1;
       }
       return 0;
}
int is_game_over(char board[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(board[i][j]=='.'){
                return 0;
            }
        }
    }
    return 1;
}