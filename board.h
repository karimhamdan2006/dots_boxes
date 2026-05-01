#ifndef BOARD_H
#define BOARD_H

void init_board(char board[5][5]);
void print_board(char board[5][5]);
int is_valid_move(int r1, int c1, int r2, int c2);
void apply_move(char board[5][5],int r1, int c1, int r2, int c2);
int check_box(char board[5][5],int r, int c);
int is_game_over(char board[5][5]);
#endif