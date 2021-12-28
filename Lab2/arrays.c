#include <stdio.h>
#include <stdlib.h>


double mean(int length, int *arr){
	double average = 0;
	for (int i = 0; i < length; ++i){
		average = average + arr[i];
	}
	average = (average / length);
	return average;
}
