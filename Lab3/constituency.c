#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constituency.h"

void construct_Constituency(struct Constituency* const obj, char const* name, unsigned int* const neighbours, unsigned int const num_neighbours){
	
	obj->name = NULL;
	obj->neighbours = NULL;
	obj->num_neighbours = 0;

	obj->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
	obj->neighbours = (unsigned int*) malloc(num_neighbours * sizeof(unsigned int));

	memcpy(obj->name, name, (strlen(name) + 1) * sizeof(char));
	memcpy(obj->neighbours, neighbours, num_neighbours * sizeof(unsigned int));
	obj->num_neighbours = num_neighbours;

}

void print_Constituency(struct Constituency* const obj){
	printf("%s | %u neighbours | [",obj->name, obj->num_neighbours);
	int i = 0;
	for(i = 0; i < obj->num_neighbours; ++i){
		printf(" %u ", obj->neighbours[i]);
	}
	printf("]");
}

void destruct_Constituency(struct Constituency* const obj){
	if(obj->name != NULL) {
		free(obj->name);
		obj->name = NULL;
	}
	if(obj->neighbours != NULL) {
		free(obj->neighbours);
		obj->neighbours = NULL;
	}
	obj->num_neighbours = 0;
}

int load_Constituencies(char* const file_path, struct Constituency ** const constituencies, unsigned int* const constituencies_loaded){
	FILE * fp;
	int line = 1;

	fp = fopen(file_path, "r");
	if(fp == NULL){
		*constituencies = NULL;
		*constituencies_loaded = 0;
		printf("Could not open file \"%s\"\n", file_path);
		return 0;
	}else{
		unsigned int num_constituencies;
		fscanf(fp, "%u", &num_constituencies);


		if(num_constituencies == 0){
			return 0;
		}

		*constituencies = malloc(num_constituencies * sizeof(struct Constituency));
		int i = 0;
		for(i = 0; i < num_constituencies; ++i){
			unsigned int num_neighbours = 0;
			fscanf(fp, "%u,", &num_neighbours);

			unsigned int neighbours[num_neighbours];
			int j = 0;
			for(j = 0; j < num_neighbours; ++j){
				fscanf(fp, "%u,", &neighbours[j]);
			}

			int current_position = 0;
			current_position = ftell(fp);
			int new_position = 0;
			char* temp;
			fscanf(fp,"%*s", &temp);
			new_position = ftell(fp);
			fseek(fp, current_position, SEEK_SET);
			unsigned int len = 0;
			len = (new_position - current_position);

			char name[len+1];
			fscanf(fp, "%s", &name);

			construct_Constituency(&(*constituencies)[i], name, neighbours, num_neighbours);
		}
		*constituencies_loaded = num_constituencies;
		return 1;
	}

}
