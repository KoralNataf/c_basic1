#include "sudoku.h"
#include "general.h"

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



#define MAT_SIZE 25

int getSudokuSize()
{	//get sudoku size from user
	int size;
	do
	{
		printf("\nPlease enter sudoku size:\n");	
		scanf("%d",&size);
	}while(size !=4 && size !=9 &&  size !=16 && size != MAT_SIZE); 
	
	return size;
}

void createMatrix(int* matrix,int size)
{	//create the matrix
	printf("\nPlease enter numbers for sudoku board:\n");
	for(int i =0 ; i< size ; i++)
	{
		scanf("%d",matrix+i);
	}
}

int checkOneRow(int* matrix,int size,char* tempArr)
{	//check if every number appears one time only in the row
	for(int i =0 ; i<size ; i++)
	{
		if(*(tempArr+*(matrix+i)+1) == '1' || *(matrix+i) > size || *(matrix+i) < 1)
			return 0;
		else
			*(tempArr+*(matrix+i)+1)='1';	
	}
	return 1;
}

int checkRows(int* matrix,int size,char* tempArr)
{	//send every row to check
	for(int i=0 ; i<size ; i++)
	{
		memset(tempArr,'0',MAT_SIZE+1);
		int ok=checkOneRow(matrix+i*size,size,tempArr);
		if(ok == 0 )
			return 0 ;
	}
	return 1;
}


int checkOneCol(int* matrix,int size,char* tempArr)
{	//check if every number appears one time only in the col
	for(int i =0 ; i<size*size ; i+=size)
	{
		if(*(tempArr+*(matrix+i)+1) == '1' || *(matrix+i) > size || *(matrix+i) <1)
			return 0;
		else
			*(tempArr+*(matrix+i)+1)='1';	
	}
	return 1;
}


int checkCols(int* matrix,int size,char* tempArr)
{	//send every col to check
	for(int i=0 ; i<size ; i++)
	{
		memset(tempArr,'0',MAT_SIZE+1);
		int ok=checkOneCol(matrix+i,size,tempArr);
		if(ok == 0 )
			return 0 ;
	}
	return 1;
}


int checkOneSquare(int* matrix,int size,char* tempArr)
{	//check if every number appears one time only in the square
	int root=sqrt(size);
	for(int i = 0 ; i<root ; i++)
	{
		for(int j=0 ; j<root ; j++)
		{
			if(*(tempArr+*(matrix+i*size+j)+1) == '1' || *(matrix+i*size+j)> size || *(matrix+i*size+j) < 1)
				return 0 ;
			else
				*(tempArr+*(matrix+i*size+j)+1)='1';
		}

	}
		return 1;	
}


int checkSquares(int* matrix,int size,char* tempArr)
{	//send every square to check
	int root=sqrt(size);
	for(int i =0 ; i<root; i++)
	{
		for(int j = 0 ; j<root;j++)
		{
			memset(tempArr,'0',MAT_SIZE+1);
			int ok=checkOneSquare(matrix+i*size*root+j*root,size,tempArr);
				if(ok == 0)
					return 0 ;
		}
	}

	return 1;
}


int checkBoard(int* matrix,int size)
{	//check the board by methods
	char tempArr[MAT_SIZE+1];
	int okRows=checkRows(matrix,size,tempArr);
	if(okRows == 0)
		return 0;
	int okCols=checkCols(matrix,size,tempArr);
	if(okCols==0)
		return 0;		
	int okSquare=checkSquares(matrix,size,tempArr);
	if(okSquare ==0)
		return 0 ;
	return 1;
}

void sudokuGame()
{	//main method that start the checking of the board
	int matrix[MAT_SIZE][MAT_SIZE];
	int size=getSudokuSize();
	createMatrix((int*)matrix,size*size);
	printMatrix((int*)matrix,size);
	int ok=checkBoard((int*)matrix,size);
	if(ok == 0)
		printf("\nSoduku board is incorrect!");
	else
		printf("\nSoduku board is correct!");

}
