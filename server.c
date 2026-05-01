#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "board.h"

#define PORT 8080

int main(){
    int server_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int player1,player2;
    server_fd= socket(AF_INET, SOCK_STREAM,0);
    address.sin_family=AF_INET;
    address.sin_addr.s_addr= INADDR_ANY;
    address.sin_port=htons(PORT);
    bind(server_fd,(struct sockaddr *)&address,sizeof(address));
    listen(server_fd,2);
    printf("server waiting for players...\n");
    char board[5][5];
    init_board(board);
    player1= accept(server_fd,(struct sockaddr *)&address, (socklen_t*)&addrlen);
    printf("player1 connected\n");
    player2=accept(server_fd,(struct sockaddr *)&address,(socklen_t*)&addrlen);
    printf("player2 connected\n");
    int current_player= 1;
    int score1= 0;
    int score2=0;
    char buffer[1024];
    char t1= '1';
    char t2= '0';
    send(player1, &t1,1,0);
    send(player1,board,sizeof(board),0);
    turn ='0';
    send(player2,&t2,1,0);
    send(player2,board,sizeof(board),0);
    while(1){
int bytes;
    if(current_player==1){
       bytes= read(player1,buffer,1023);
    }else {
      bytes=  read(player2,buffer,1023);
    }
    if(bytes<=0) break;
    buffer[bytes]='\0';
    int r1,c1,r2,c2;
    sscanf(buffer,"%d %d %d %d", &r1,&c1,&r2,&c2);
     if(!is_valid_move(r1,c1,r2,c2)){
        printf("Invalid move!\n");
        continue;
    }
    printf("Move received: (%d,%d) -> (%d,%d)\n", r1,c1,r2,c2);
    apply_move(board,r1,c1,r2,c2);
    int scored=0;
    if(check_box(board,r1,c1)) scored++;
    if(check_box(board,r2,c2))scored++;
    if(scored>0){
        if(current_player==1)
            score1 += scored;
        else 
            score2 += scored;
        
    }
   print_board(board);
    printf("Score P1: %d | Score P2: %d", score1, score2);
     if(is_game_over(board)){
        printf("Game over!\n");
        break;
    }
    
    if(scored==0){
    if(current_player==1)
        current_player=2;
    else  current_player=1;}

    if(current_player==1){
        char t1='1';
        char t2='0';
        send(player1,&t1,1,0);
        send(player1,board,sizeof(board),0);
        send(player2,&t2,1,0);
        send(player2,board,sizeof(board),0);
    }else{
        char t1='0';
        char t2='1';
        send(player1,&t1,1,0);
        send(player1,board,sizeof(board),0);
        send(player2,&t2,1,0);
        send(player2,board,sizeof(board),0);
    }
}
char result[50];
if(score1>score2){
    sprintf(result, "Player 1 wins");
}
else if(score2>score1){
    sprintf(result, "Player 2 wins");
} else {
    Sprintf(result, "Draw");
}
close(player1);
close(player2);
close(server_fd);
    return 0;
}