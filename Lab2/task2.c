#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"


int main(int argc , char *argv[]) {

	int num;
	int *tables[MAX_TABLE_SIZE];

	for (num = 0; num <= 12; ++num){
		int *values = (int*) malloc(MAX_TABLE_SIZE * sizeof(int));
		tables[num] = values;
		generate_table(num, values);
	}
	print_tables(tables);
	for ( int i = 0; i <= 12; ++i){
		free(tables[i]);
	}
	return 0;
}

