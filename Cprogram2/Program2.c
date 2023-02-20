/*
============================================================================
Author: Ky Le
KUID: 3050474
Date: 2/19/2023
EECS 368 Lab 3
Last modified: 2/19/2023
Purpose: Eclipse IDE, compiled programs (C programming), Git: Program 2
============================================================================
 */
#include <stdio.h>

//points
int TDcount;
int FGcount;
int Safetycount;
int TDpCcount;
int TDpFGcount;


void scorecount(int score)
{
	Safetycount = 0;
	while ((2 * Safetycount) <= score)
	{
		if ((2 * Safetycount) == score)
		{
			printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 0, 0, 0, 0, Safetycount);
		}
		FGcount = 0;
		while (((2 * Safetycount) + (3 * FGcount)) <= score)
		{
			if (((2 * Safetycount) + (3 * FGcount)) == score && (FGcount!=0))
			{
				printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 0, 0, 0, FGcount, Safetycount);
			}
			TDcount = 0;
			while (((2 * Safetycount) + (3 * FGcount) + (6 * TDcount)) <= score)
			{
				if (((2 * Safetycount) + (3 * FGcount) + (6 * TDcount)) == score && (TDcount!=0))
				{
					printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TDpCcount, TDpFGcount, TDcount, FGcount, Safetycount);
				}
				TDpFGcount = 0;
				while (((2 * Safetycount) + (3 * FGcount) + (6 * TDcount) + (7 * TDpFGcount)) <= score)
				{
					if (((2 * Safetycount) + (3 * FGcount) + (6 * TDcount) + (7 * TDpFGcount)) == score && (TDpFGcount!=0))
					{
						printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 0, TDpFGcount, TDcount, FGcount, Safetycount);
					}
					TDpCcount = 0;
					while (((2 * Safetycount) + (3 * FGcount) + (6 * TDcount) + (7 * TDpFGcount) + (8 * TDpCcount)) <= score)
					{
						if (((2 * Safetycount) + (3 * FGcount) + (6 * TDcount) + (7 * TDpFGcount) + (8 * TDpCcount)) == score && (TDpCcount!=0))
						{
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TDpCcount, TDpFGcount, TDcount, FGcount, Safetycount);
						}
						TDpCcount +=1;
					}
					TDpFGcount +=1;
				}
				TDcount +=1;
			}
			FGcount +=1;
		}
		Safetycount +=1;
	}
}

int main()
{
	int inputNum = 0;
	do {
		printf("Enter 0 or 1 to STOP\n");
		printf("Enter the NFL Score: ");
		//get the score number here
		fflush(stdout);
		scanf("%d", &inputNum);
		//printf("Your score is: %d\n", inputNum);
		scorecount(inputNum);
	} while (inputNum > 1);
}
