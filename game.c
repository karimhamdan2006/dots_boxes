#include <stdio.h>
#include "game.h"
static int horizontal[DOT_ROWS][BOX_COLS];
static int vertical[BOX_ROWS][DOT_COLS];
static char boxes[BOX_ROWS][BOX_COLS];
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
    for( r=0; r<BOX_ROWS;r++){
        for(c=0;c<BOX_COLS;c++){
            boxes[r][c]=' ';
        }
    }
}
void add_test_lines(void){
    horizontal[0][0]= 1;
    horizontal[1][0]= 1;
    vertical[0][0]=1;
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
                    printf("--");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
        if(row<BOX_ROWS){
            printf("  ");
            for(col=0;col<DOT_COLS;col++){
                if(vertical[row][col]==1){
                    printf("|");
                } else{
                    printf(" ");
                } if(col<BOX_COLS){
                    printf("%c",boxes[row][col]);
                }
            }
            printf("\n");
                }
    }
}

 
void get_move(int *r1,int *c1, int *r2, int *c2){
    printf("Enter row and coloumn of first dot, then row and coloumn of second dot: ");
    scanf("%d %d %d %d", r1, c1, r2, c2);
}
int is_valid_move(int r1, int c1, int r2,int c2){
    if(r1<0||r1>=DOT_ROWS||r2<0||r2>=DOT_ROWS){
        return 0;
    }
    if(c1<0||c1>=DOT_COLS|| c2<0||c2>=DOT_COLS){
        return 0;
    }
    if(r1==r2 &&(c1==c2+1|| c2==c1+1)){
        return 1;
    }
    if(c1==c2 &&(r1==r2+1|| r2==r1+1)){
        return 1;
    }
    return 0;
}
int line_already_drawn(int r1, int c1, int r2, int c2){
    if(r1==r2){
        if(c1>c2){
            int temp= c1;
            c1=c2;
            c2=temp;
        }
        return horizontal[r1][c1]==1;
    }
    if (c1==c2){
        if(r1>r2){
            int temp=r1;
            r1=r2;
            r2=temp;
        }
        return vertical[r1][c1]==1;
    }
    return 0;
}
void apply_move(int r1,int c1,int r2, int c2){
    if(r1==r2){
        if(c1>c2){
            int temp= c1;
            c1=c2;
            c2=temp;
        }
        horizontal[r1][c1]=1;
    } else if (c1==c2){
        if(r1>r2){
            int temp = r1;
            r1=r2;
            r2=temp;
        }
        vertical[r1][c1]=1;
    }
}
int box_is_complete(int box_row, int box_col){
    if( horizontal[box_row][box_col]==0){
        return 0;
    }
    if(horizontal[box_row+1][box_col]==0){
        return 0;
    }
    if(vertical[box_row][box_col]==0){
        return 0;
    }
    if(vertical[box_row][box_col+1]==0){
        return 0;
    }
    return 1;
}
int claim_completed_boxes(char player){
    int row,col;
    int claimed=0;
    for(row=0;row<BOX_ROWS;row++){
        for(col=0; col<BOX_COLS;col++){
            if(boxes[row][col]== ' ' && box_is_complete(row,col)){
                boxes[row][col]= player;

                claimed++;
            }
        }
    }
    return claimed;
}
int choose_game_mode(void){
    int mode;
    printf("choose game mode/n");
    printf("1. Human vs Human");
    printf("2. Human vs Bot");
    printf("Enter choice: ");
    scanf("%d", &mode);
    return mode;

}