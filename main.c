#include <stdio.h>
#include "game.h"
int main(void){
    int r1,c1,r2,c2;
    init_board();
    add_test_lines();
    print_board();
   get_move(&r1,&c1,&r2,&c2);
printf("You entered: (%d,%d) to (%d,%d)", r1,c1,r2,c2);
      return 0;
}