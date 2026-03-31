#include <stdio.h>
#include "game.h"
 void print_empty_board(void){
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
        }
        printf("\n");
    }
 }
