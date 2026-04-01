#include <stdio.h>
#include "game.h"
int main(void){
    int r1,c1,r2,c2;
    init_board();
    add_test_lines();
    print_board();
   get_move(&r1,&c1,&r2,&c2);
if(is_valid_move(r1,c1,r2,c2)){
    apply_move(r1,c1,r2,c2);
        printf("move is accapted");
    } else {
        printf("invalid move");
    }

print_board();
      return 0;
}