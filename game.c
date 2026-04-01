#include <stdio.h>
#include "game.h"
static int horizontal[DOT_ROWS][BOX_COLS];
static int vertical[BOX_ROWS][DOT_COLS];
void init_board(void){
    int r,c;
    for(r=0; r< DOT_ROWS;r++){
      for(c=0; c<BOX_COLS;c++){
        horizontal[r][c]=0;
      }   
    }
    for(r=0; r<BOX_ROWS;r++){
        for(c=0; c<DOT_COLS;c++){
            vertical[r][c]=0;
        }
    }
}
void add_test_lines(void){
    horizontal[0][0]= 1;
    horizontal[0][1]= 1;
    vertical[0][0]=1;
    vertical[0][DOT_COLS-1]= 1;
}
 void print_board(void){
    int row, col;
    printf(" ");
    for(col = 0 ; col < DOT_COLS; col++){
        printf("%d ", col);
    }
    printf("\n");
    for( row = 0; row< DOT_ROWS; row++){
        printf("%d", row);
        for (col=0; col< DOT_COLS; col++){
            printf(".");
            if (col<BOX_COLS){
                if(horizontal[row][col]==1){
                    printf("-");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
        if(row<BOX_ROWS){
            printf(" ");
            for(col=0;col<DOT_COLS;col++){
                if(vertical[row][col]==1){
                    printf("|");
                } else{
                    printf(" ");
                } if(col<BOX_COLS){
                    printf(" ");
                }
            }
            printf("\n");
                }
    }
 }
