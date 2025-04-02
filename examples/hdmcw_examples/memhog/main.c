//
//  main.c
//  memhog
//
//  Created by Mike Mull on 3/31/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    long total_alloc = 0;
    long nalloc = 10;
    char *parray[100];
    
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            parray[i*10 + j] = malloc(nalloc);
            total_alloc += nalloc;
            printf("Malloc %d %ld\n", i*10 + j, nalloc);
        }
        nalloc *= 10;
    }
    printf("Malloc %ld\n", total_alloc);
    sleep(30);
    return 0;
}
