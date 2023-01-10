#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "five_game.h"

void begin_menu();


int main() {
    int choose = 0;
    while(1){
        begin_menu();
        printf("你想选择:");
        scanf("%d",&choose);
        if(choose == 1){
            five_game(1);
        }
        else if(choose == 2){
            five_game(2);
        }else if(choose == 3){
            printf("退出游戏");
            break;
        }else{
            printf("输入错误，重新输入\n");
        }
    }
    return 0;
};


void begin_menu(){
    printf("1:新建对局\n");
    printf("2:复盘\n");
    printf("3:退出游戏\n");
}