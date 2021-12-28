//
// Created by George Cook on 27/01/2021.
//

#include "fibonacci.h"

int fibonacci(int fibonacciNumber) {

    int result;

    if(fibonacciNumber <= 0){
      result = 0;
        return result;
    }
    if(fibonacciNumber == 1){
        result = 1;
        return result;
    }
    else{
        result = fibonacci(fibonacciNumber - 1) + fibonacci(fibonacciNumber - 2);
        return result;
    }

}
