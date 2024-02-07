#include <stdio.h>

void solveSudoku(char ** board[9][9], int boardSize){
    for (int column = 0; column < boardSize; column++){
        for (int line = 0; line < boardSize; line++){

		if(board[column][line] != '.'){
			continue;
            }
            else{
                for (int possibleValue = 0; possibleValue <= 9; possibleValue++ ){
                    if(containOnRow(board,possibleValue,boardSize,column) == 0 && containOnColumn(board,boardSize,column,possibleValue) == 0  && containOnSubBox() == 0){
			printf("o valor para a posição %i,%i  é: %i\n",column,line, possibleValue);
                        board[column][line] = (char)possibleValue;
			break;
                  }
                }
            }
        }
    }
}

int containOnSubBox(char ** board[9][9], int possibleValue, int column, int line){
	int quadranteColuna = 0;	
	int quadranteLinha = 0 ;
	
	int quadrantes[3]  = {2,5,8};
	for (int i = 0; i < 3; i++){
		if (line < i)
			quadranteLinha = i;
		if (column < i)
			quadranteColuna = i;
	}

	for (int i = quadranteColuna - 3; i < quadranteColuna;i++){
		for(int j = quadranteLinha -3; j < quadranteLinha; j++) {
			if( board[quadranteColuna][quadranteLinha] != "." && (int)board[quadranteColuna][quadranteLinha] == possibleValue)
				return 1;
		}
	}
	return 0;

}

int containOnRow(char ** board[9][9],int possibleValue, int boardSize, int columnNumber){
    for (int i = 0; i < boardSize; i ++){
	if (board[columnNumber][i] =='.'){
		continue;
	}
	else if ((int)board[columnNumber][i] == possibleValue){
            return 1;
        }
    }
    return 0;
}

int containOnColumn(char ** board[9][9], int boardSize, int lineNumber,int possibleValue) {
        for (int column = 0; column < boardSize; column++){
            if(board[column][lineNumeber] == '.'){
                continue;
            }
            else if ((int)board[columnNumber][line] == possibleValue){
                    return 1;
                }
                
            }
        return 0;
}

