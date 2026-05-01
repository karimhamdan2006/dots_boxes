#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "board.h"
#define PORT 8080
int main(){
    int sock=0;
    struct sockaddr_in serv_addr;
    sock= socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(PORT);
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr);
    connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    printf("connected to server\n");

    while(1){
        char turn;
        int t = read(sock,&turn, 1);
        if(t<=0)break;
        char board[5][5];
        int bytes=read(sock,board,sizeof(board));
        if(bytes<=0) break;
        print_board(board);
        if(turn== '1'){
        printf("Your turn\n");
        int r1,c1,r2,c2;
        printf("Enter move (r1,c1,r2,c2): ");
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        char msg[100];
        sprintf(msg,"%d %d %d %d",r1,c1,r2,c2);
        send(sock,msg,strlen(msg),0);
        }else {
            printf("Waiting for opponents move.....\n");
        }
    }
    char result[50];
    int bytes= read(sock,result,sizeof(result)-1);
    if(bytes>0){
        result[bytes]='\0';
        printf("%s\n",result);
    }
close(sock);
return 0;
}