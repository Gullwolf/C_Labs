#include <stdio.h>

#include "constituency.h"

int main(int argc, char *argv []) {
	const int num_constituencies = 5;
	struct Constituency constituencies[num_constituencies];
	
	construct_Constituency(&constituencies[0], "Swansea East", (unsigned int[]){1, 2, 3, 4}, 4);
	construct_Constituency(&constituencies[1], "Swansea West", (unsigned int[]){0, 2}, 2);
	construct_Constituency(&constituencies[2], "Gower", (unsigned int[]){0, 1, 3}, 3);
	construct_Constituency(&constituencies[3], "Neath", (unsigned int[]){0, 2, 4}, 3);
	construct_Constituency(&constituencies[4], "Aberavon", (unsigned int[]){0, 3}, 2);
	
	int i = 0;
	int most_neighbours = 0;
	int least_neighbours = 0;
	for(i = 0; i < num_constituencies; ++i){
		print_Constituency(&constituencies[i]);
		if(constituencies[i].num_neighbours > constituencies[most_neighbours].num_neighbours){
			most_neighbours = i;
		}
		if(constituencies[i].num_neighbours < constituencies[least_neighbours].num_neighbours){
			least_neighbours = i;
		}
		printf("\n");
	}
	
	printf("\n");
	
	printf("%s has the most bordering constituencies:\n", constituencies[most_neighbours].name);
	for(i = 0; i < constituencies[most_neighbours].num_neighbours; ++i){
		unsigned int j = constituencies[most_neighbours].neighbours[i];
		printf("	%s\n", constituencies[j].name);
	}
	
	printf("\n");

	printf("%s has the fewest bordering constituencies:\n", constituencies[least_neighbours].name);
	for(i = 0; i < constituencies[least_neighbours].num_neighbours; ++i){
		unsigned int j = constituencies[least_neighbours].neighbours[i];
		printf("	%s\n", constituencies[j].name);
	}
	
	for(i = 0; i < num_constituencies; ++i){
		destruct_Constituency(&constituencies[i]);
	}
	
	return 0;
}
