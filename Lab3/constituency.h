#ifndef CONSTITUENCY_H_
#define CONSTITUENCY_H_

struct Constituency {
	char* name;
	unsigned int* neighbours;
	unsigned int num_neighbours;
};

void construct_Constituency(struct Constituency* const obj, char const* name, unsigned int* const neighbours, unsigned int const num_neighbours);
void destruct_Constituency(struct Constituency* const obj);
void print_Constituency(struct Constituency* const obj);
int load_Constituencies(char* const file_path, struct Constituency ** const constituencies, unsigned int* const constituencies_loaded);

#endif // CONSTITUENCY_H_
