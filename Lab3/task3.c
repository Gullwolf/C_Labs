#include <stdio.h>

#include "constituency.h"

int main(int argc, char *argv []) {
	unsigned int num_constituencies;
	struct Constituency *constituencies;


	if(!load_Constituencies("wales.graph", &constituencies, &num_constituencies)){
		return -1;
	}

	int i = 0;
	int most_neighbours = 0;
	int least_neighbours = 0;
	for(i = 0; i < num_constituencies; ++i){
		print_Constituency(&constituencies[i]);
		printf("\n");

		if(constituencies[i].num_neighbours > constituencies[most_neighbours].num_neighbours){
			most_neighbours = i;
		}

		if(constituencies[i].num_neighbours < constituencies[least_neighbours].num_neighbours){
			least_neighbours = i;
		}
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
