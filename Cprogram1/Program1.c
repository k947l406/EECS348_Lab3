/*
============================================================================
Author: Ky Le
KUID: 3050474
Date: 2/19/2023
EECS 368 Lab 3
Last modified: 2/19/2023
Purpose: Eclipse IDE, compiled programs (C programming), Git: Program 1
============================================================================
 */
#include <stdio.h>

int main()
{
    //set up month names and samples
    int figures = 12;
    char months[12][10] = {"January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    double sample1[12] = {23458.01,
        40112.00,
        56011.85,
        37820.88,
        37904.67,
        60200.22,
        72400.31,
        56210.89,
        67230.84,
        68233.12,
        80950.34,
        95225.22};

    //function to get the minimum value
    int n;
    void getMin(double *array)
    {
        double sales = array[0];
        int month = 0;
        //go through the array
        for (n = 0; n < figures; n++)
        {
            //set sales value to the new value if it's smaller
            if (sales > array[n])
            {
                sales = array[n];
                month = n;
            }
        }
        printf("Minimum sales: $%.2f (%s)\n", sales, months[month]);
    }

    //function to get maximum value
    void getMax(double *array)
    {
        double sales = array[0];
        int month = 0;
        for (n = 0; n < figures; n++)
        {
            //set sales value to the new value if it's larger
            if (sales < array[n])
            {
                sales = array[n];
                month = n;
            }
        }
        printf("Maximum sales: $%.2f (%s)\n", sales, months[month]);
    }

    //function to get average
    void getAverage(double *array)
    {
    	float sum = 0;
    	for (n = 0; n < figures; n++)
    	{
    		sum += array[n];
    	}
    	float average = sum/figures;
    	printf("Average sales: $%.2f \n", average);
    }

    void getReport(double *array)
    {
    	printf("Sales Report (Highest to Lowest)\n");
    	//set up temporary arrays to keep track of the values we want to print out in order
    	double reportArray[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    	double monthOrder[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    	//find the maximum value
    	for (int i = 0; i < figures; i++)
    	{
    		double sales = array[0];
			int month = 0;
			int n;
			for (n = 0; n < figures; n++)
			{
				//set sales value to the new value if it's larger
				if (sales < array[n])
				{
					sales = array[n];
					month = n;
				}
			}
			array[month] = 0; //"remove" the sale value of the highest month for the next highest loop
			reportArray[i] = sales;
			monthOrder[i] = month;
    	}
    	for (int i = 0; i < figures; i++)
		{
			double sales = reportArray[i];
			int month = monthOrder[i];
			printf("%s $%.2f \n", months[month], sales);
		}
    }

    void getMonthly(double *array)
    {
    	printf("Monthly Sales Report for 2022:\nMonth Sales\n");
    	for (int i = 0; i < figures; i++)
    	{
    		double sales = array[i];
    		printf("%s $%.2f \n", months[i], sales);
    	}
    }

    void getSixMonths(double *array)
    {
    	printf("Six-Month Moving Average Report: \n");
    	for (int i = 0; i <= 6; i++) //go through this seven times for each set of six months
    	{
    		//loop through six months starting from month i
    		float sum = 0;
    		for (int j =i; j <= (i+5); j++)
    		{
    			//get average
    			sum += array[j];
    		}
    		float average = sum/6;
    		printf("%s - %s $%.2f \n", months[i], months[i+5], average);
    	}
    }

    //call functions
    getMonthly(sample1);
    puts("");
    printf("Sales summary: \n");
    getMin(sample1);
    getMax(sample1);
    getAverage(sample1);
    puts("");
    getSixMonths(sample1);
    puts("");
    getReport(sample1);
}
