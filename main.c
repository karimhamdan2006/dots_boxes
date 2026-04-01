#include <stdio.h>
#include "game.h"
int main(void){
    int r1,c1,r2,c2;
    init_board();
    add_test_lines();
    print_board();
   get_move(&r1,&c1,&r2,&c2);
if(!is_valid_move(r1,c1,r2,c2)){
    printf("invalid move.\n");
 } else if(line_already_drawn(r1,c1,r2,c2)){
        printf("line is already drawn.\n");
    }else {
        apply_move(r1,c1,r2,c2);
        printf("move is accepted.\n");
    }

print_board();
      return 0;
}