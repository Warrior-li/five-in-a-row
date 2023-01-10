#include "stdlib.h"
#include "stdio.h"
#include "five_game.h"

void readBoard(char board[row][column]){
    FILE *fp;
    fp = fopen("board.txt","r");
    if(fp != NULL){
        for(int i = 0;i < row ;++i){
            for(int j = 0;j < column;++j){
                board[i][j] = (char)fgetc(fp);
            }
        }
    }
    fclose(fp);
}

void writeBoard(char board[row][column]){
    FILE *fp;
    fp = fopen("board.txt","w");
    if(fp == NULL){
        printf("打开失败");
    }
    for(int i = 0; i < row;++i){
        for(int j = 0;j< column;++j){
            fputc(board[i][j], fp);
        }
    }
    fclose(fp);
}

void initBoard(char board[row][column]){
    for(int i = 0;i < row; ++i){
        for(int j = 0;j < column; ++j){
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[row][column]){
    for(int i = 0; i< row; ++i){
        if(i == 0){
            for(int j = 0;j < column; ++j)printf("|---");
            printf("|\n");
        }
        for(int j = 0; j < column; ++j){
            if(j == 0)printf("|");
            printf(" %c |",board[i][j]);
            if(j == column -1)printf("\n");
        }
        for(int j = 0; j < column;++j)printf("|---");
        printf("|\n");
    }
}

int winThisGame(char board[row][column],int x,int y){
    int count = 1;
    char tag = board[x][y];
    int x_tag = x;
    while(--x_tag>=0 && board[x_tag][y] == tag)++count;
    x_tag = x;
    while(++x_tag<row && board[x_tag][y] == tag)++count;
    if(count>=5)return 1;

    count = 1;
    int y_tag = y;
    while(--y_tag>=0 && board[x][y_tag] == tag)++count;
    y_tag = y;
    while(++y_tag<column && board[x][y_tag] == tag)++count;
    if(count>=5)return 1;

    count = 1;
    x_tag = x,y_tag = y;
    while(--x_tag>=0 && --y_tag>=0 && board[x_tag][y_tag] == tag)++count;
    x_tag = x,y_tag = y;
    while(++x_tag<row && ++y_tag<column && board[x_tag][y_tag] == tag)++count;
    if(count>=5)return 1;

    count = 1;
    x_tag = x,y_tag = y;
    while(--x_tag>=0 && ++y_tag<column && board[x_tag][y_tag] == tag)++count;
    x_tag = x,y_tag = y;
    while(++x_tag<row && --y_tag>=0 && board[x_tag][y_tag] == tag)++count;
    if(count>=5)return 1;

    return 0;
}


int userPlay(char board[row][column]){
    int x,y;
    printf("轮到你了\n");
    while(1){
        printf("你选择下在(输入-1 -1保存):");
        scanf("%d %d",&x,&y);
        if(x == -1 && y == -1){
            writeBoard(board);
            exit(0);
        }
        if( x >= column || x < 0 || y >= row || y < 0){
            printf("超出范围，重新输入\n");
            continue;
        }else if(board[x][y] != ' '){
            printf("已经有棋子在这里了\n");
        }else{
            board[x][y] = '*';
            break;
        }
    }
    return winThisGame(board,x,y);
}

int randomPlay(char board[row][column]){
    int x,y;
    while(1){
        x = rand() % row;
        y = rand() % column;
        if(board[x][y] == ' '){
            board[x][y] = '#';
            printf("电脑下在 %d %d\n",x,y);
            break;
        }
    }
    return winThisGame(board,x,y);
}

int finish(char board[row][column]){
    for(int i = 0;i < row; ++i){
        for(int j = 0;j < column;++j){
            if(board[i][j] == ' ') return 0;
        }
    }
    return 1;
}


void five_game(int mode){
    char board[row][column];
    if(mode == 1){
        initBoard(board);
    }else{
        readBoard(board);
    }
    displayBoard(board);
    while(1){
        if(userPlay(board)){
            displayBoard(board);
            printf("User win\n");
            break;
        }
        displayBoard(board);
        if(finish(board)){
            printf("平局\n");
            break;
        }
        if(randomPlay(board)){
            displayBoard(board);
            printf("Computer win\n");
            break;
        }
        displayBoard(board);
        if(finish(board)){
            printf("平局\n");
            break;
        }
    }
}

