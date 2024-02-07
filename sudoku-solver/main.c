#include "sudoku.c"
#include <stdio.h>
int main (){
char ** board[9][9]= { 
	{ '5','3','.','.','7','.','.','.','.'} ,
	{ '6','.','.','1','9','5','.','.','.'} ,
	{ '.','9','8','.','.','.','.','6','.'} ,
	{ '8','.','.','.','6','.','.','.','3'} ,
	{ '4','.','.','8','.','3','.','.','1'} ,
	{ '7','.','.','.','2','.','.','.','6'} ,
	{ '.','6','.','.','.','.','2','8','.'} ,
	{ '.','.','.','4','1','9','.','.','5'} ,
	{ '.','.','.','.','8','.','.','7','9'} } ;

	printf("initial sudoku\n");
	printMatrix(board, 9);
	solveSudoku(board,9);
	printf("solution sudoku\n");
	printMatrix(board, 9);
	return 0;
}

void printMatrix(char ** board[9][9],int size){
	for ( int i =0;i < size; i++){
		for (int j = 0; j < size;j++){
			printf("%c, ",board[i][j]);
		}
		printf("\n");
	}
}

