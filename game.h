#ifndef Game_H
#define Game_H
#define BOX_ROWS 4
#define BOX_COLS 5
#define DOT_ROWS 5
#define DOT_COLS 6
void init_board(void);
void add_test_lines(void);
void print_board(void);
void get_move(int *r1, int *c1, int *r2, int *c2);
int is_valid_move(int r1,int c1, int r2, int c2);
int line_already_drawn(int r1, int c1, int r2, int c2);
void apply_move(int r1,int c1,int r2, int c2);
int box_is_complete(int box_row, int box_col);
int claim_completed_boxes(char player);

#endif 

