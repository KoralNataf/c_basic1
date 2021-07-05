#include "general.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void printArray(int* arr , int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ",*(arr + i));
	}	
		printf("\n");

}


void printMatrix(int* matrix,int size)
{
	printf("\nThe sudoku board is ready:\n");
	for(int i=0 ; i<size ; i++)
	{
		for(int j=0 ; j < size ; j++)
		{
			printf("%4d",*(matrix+size*i+j));
		}
		printf("\n");	
	}

}
