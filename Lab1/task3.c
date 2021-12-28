//
// Created by George Cook on 27/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main(int argc, char* argv[]) {

    if(argc <= 1){
        printf("No argument given, exiting program.\n");
        return 0;
    }
    else{
        int num = atoi(argv[1]);
        int result = fibonacci(num);
        printf("Fibonacci of %d = %d\n", atoi(argv[1]), result);
        return 0;
    }
}
