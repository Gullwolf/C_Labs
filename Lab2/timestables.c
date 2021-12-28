#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

#define MAX_TABLE_SIZE 13
#define MAX_TIME_TABLE 12

double mean(int length, int *arr);

void generate_table(int num, int *table){
	int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		table[i] = i * num;
	}
}

void print_table(int num, int *table){
	printf("%-2d times table\n--------------\n", num);
	int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		printf("%-2d * %-2d = %d\n", num, i, *(table+i));
	}
	double mean_value = mean(MAX_TABLE_SIZE, table);
	printf("The mean for this table is %f\n\n", mean_value);
	printf("\n");
}

void print_tables(int **tables) {
	int i;
	for (i = 0; i <= MAX_TIME_TABLE; i++) {
		print_table(i, tables[i]);
	}
}

