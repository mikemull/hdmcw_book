//
//  main.c
//  csubs
//
//  Created by Mike Mull on 3/20/26.
//

#include <stdlib.h>
#include <stdio.h>


int multadd(int a, int b) {
    
    return a * b + 3;
}


// Recursive fibonacci function
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main(int argc, const char * argv[]) {
    
    // Test fibonacci function
    int n = 10;
    int fib_result = fibonacci(n);
    printf("fibonacci(%d) = %d\n", n, fib_result);
    
    return EXIT_SUCCESS;
}

