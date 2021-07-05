#ifndef _S
#define _S


int getSudokuSize();
void createMatrix(int* matrix,int size);
int checkOneRow(int* matrix,int size,char* tempArr);
int checkRows(int* matrix,int size,char* tempArr);
int checkOneCol(int* matrix,int size,char* tempArr);
int checkCols(int* matrix,int size,char* tempArr);
int checkOneSquare(int* matrix,int size,char* tempArr);
int checkSquares(int* matrix,int size,char* tempArr);
int checkBoard(int* matrix,int size);
void sudokuGame();



#endif
