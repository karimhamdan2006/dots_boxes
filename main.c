#include <stdio.h>
#include "game.h"
int main(void){
    int r1,c1,r2,c2;
    int claimed;
    int scoreA=0, scoreB=0;
    char current_player= 'A';
    init_board();
    while(1){
        print_board();
        printf("Score - A: %d, B: %d\n", scoreA,scoreB);
        printf("Player %c's turn\n",current_player);
        get_move(&r1,&c1,&r2,&c2);
        if(!is_valid_move(r1,c1,r2,c2)){
            printf("invalid move.\n");
            continue;
        }
        if(line_already_drawn(r1,c1,r2,c2)){
            printf("That line is already drawn.\n");
            continue;
        }
        apply_move(r1,c1,r2,c2);
        claimed=claim_completed_boxes(current_player);
        if(current_player== 'A'){
            scoreA+=claimed;
        }else {
            scoreB +=claimed;
        }
        printf("move accepted. Boxes claimed: %d\n", claimed);
        if(claimed==0){
            if(current_player=='A'){
                current_player='B';
            } else {
                current_player='A';
            }
        }
        if(scoreA + scoreB == BOX_ROWS*BOX_COLS){
            break;
        }
    }
    print_board();
    printf("final score -A: %d, B: %d\n", scoreA, scoreB);
    if(scoreA>scoreB){
        printf("player A WINS!\n");
    } else if(scoreB>scoreA){
        printf("player B WINS!\n");
    } else {
        printf("It's a TIE\n");
    }
    return 0;
}