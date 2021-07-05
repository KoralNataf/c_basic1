#include "tickets.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 7


void getUserInput(int *pDay,int *pNumOfTickets)
{	//get information about festival from user
		printf("\nplease enter a day number(between 1-7 , 0 for finish): \n");
		scanf("%d",pDay);
		if(*pDay <=7 && *pDay > 0 ) 
		{
			printf("\nplease enter number of tickets:\n");
			scanf("%d",pNumOfTickets);
		}
}

void findMaxMin(int* arr,int* pMaxDay,int* pMinDay)
{	//find the best and the worst salse day
	int maxNum=*arr;
	int minNum=*arr;
	*pMaxDay=0;
	*pMinDay=0;


	for(int i = 0 ; i < SIZE; i++)
	{
		if(*(arr+i) > maxNum)
		{
			maxNum=*(arr+i);
			*pMaxDay=i;
		
		}else if(*(arr+i) < minNum)
		{
			minNum=*(arr+i);
			*pMinDay=i;
		}
	}
}


void printResultFestival(int* arr,int *pMaxDay,int *pMinDay)
{	//print the reasult
	printf("\nBest sales day is :	%d\n%d tickets are sold",*(pMaxDay)+1,*(arr+*pMaxDay));
	printf("\nWorst sales day is :	%d\n%d tickets are sold",*(pMinDay)+1,*(arr+*pMinDay));	
}


void doTickets()
{	// main method of game
	int day,numOfTickets,maxDay,minDay;

	int* pDay=&day;
	int* pNumOfTickets=&numOfTickets;
	int* pMaxDay=&maxDay;
	int* pMinDay=&minDay;

	int arr[SIZE];
	
	do{

		getUserInput(pDay,pNumOfTickets);
		if(day !=0)
			*(arr+day-1)=numOfTickets;

	}while(day !=0);

		findMaxMin(arr,pMaxDay,pMinDay);
		printResultFestival(arr,pMaxDay,pMinDay);
}
