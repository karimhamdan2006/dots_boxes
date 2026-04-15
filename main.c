#include <stdio.h>
#include "game.h"
int main(void){
    int r1,c1,r2,c2;
    int claimed;
    int scoreA=0, scoreB=0;
    int mode;
    char current_player= 'A';
    mode = choose_game_mode();
    init_board();
    while(1){
        print_board();
        printf("Score - A: %d, B: %d\n", scoreA,scoreB);
        if(mode==1){
            printf("Human vs Human\n");
        } else if (mode==2){
            printf("Human vs Bot\n");
        } else {
            printf("No mode or wrong mode selected, defaulting to Human vs Human");
        }
        printf("Player %c's turn\n",current_player);
        printf("Enter -1 -1 0 0 to quit.\n");
        get_move(&r1,&c1,&r2,&c2);
        if(r1==-1 && c1==-1){
            printf("Game ended by early by user.\n");
            break;
        }
        if(!is_valid_move(r1,c1,r2,c2)){
            printf("invalid move. Dots must be adjacent and within the board\n");
            continue;
        }
        if(line_already_drawn(r1,c1,r2,c2)){
            printf("That line is has already been drawn. try again.\n");
            continue;
        }
        apply_move(r1,c1,r2,c2);
        claimed=claim_completed_boxes(current_player);
        if(current_player== 'A'){
            scoreA+=claimed;
        }else {
            scoreB +=claimed;
        }
        printf("move accepted. Boxes claimed this turn: %d\n", claimed);
        if(claimed==0){
            if(current_player=='A'){
                current_player='B';
            } else {
                current_player='A';
            } } else {
                printf("player %c get another turn.\n", current_player);
            }
        
        if(scoreA + scoreB == BOX_ROWS*BOX_COLS){
            printf("all boxes have been claimed");
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