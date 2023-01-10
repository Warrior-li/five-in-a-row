//
// Created by Warrior on 29/12/2022.
//

#ifndef CHESS_FIVE_GAME_H
#define CHESS_FIVE_GAME_H

#endif //CHESS_FIVE_GAME_H

#define row 20
#define column 20


void initBoard(char board[row][column]);

void displayBoard(char board[row][column]);

int winThisGame(char board[row][column],int x,int y);

int userPlay(char board[row][column]);

int randomPlay(char board[row][column]);

int finish(char board[row][column]);

void five_game(int mode);

void readBoard(char board[row][column]);

void writeBoard(char board[row][column]);