//
//  main.c
//  threads
//
//  Created by Mike Mull on 3/27/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *copy1(void *);
void *copy2(void *);
void *copy_ints(int *, int);


const int NUMINTS=10;

int main(int argc, const char * argv[]) {
    pthread_t thread1, thread2;
    int  iret1, iret2;

    srand((unsigned int) time(NULL));
    int* myints = (int*) malloc(NUMINTS * sizeof(int));

    iret1 = pthread_create( &thread1, NULL, copy1, (void *) myints);
    iret2 = pthread_create( &thread2, NULL, copy2, (void *) myints);

    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);

    for (int i=0; i < 10; i++) {
        printf("[%d]", myints[i]);
    }
    printf("\n");

    exit(0);
}

void *copy_ints(int *x, int val)
{
    for (int i=0; i<NUMINTS; i++) {
        int r = rand() % 100000;
        for (int j=0; j < r; j++) // Delay loop
            ;
        x[i] = val;
    }
    return NULL;
}

void * copy1(void *intarray) {
    return copy_ints((int *) intarray, 1);
}

void * copy2(void *intarray) {
    return copy_ints((int *) intarray, 2);
}

