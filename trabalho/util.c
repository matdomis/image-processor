#include "util.h"
#include "file.h"
#include "image.h"

#include <stdlib.h>
#include <string.h>

void allocateImages(_PGMImage **inputImage, _PGMImage **outputImage) {
    *inputImage = malloc(sizeof(_PGMImage));
    *outputImage = malloc(sizeof(_PGMImage));
}

ull atoul(char *num) {
    ull temp = 0;
    for(int i = 0 ; i < strlen(num) ; i++) 
        temp = temp * 10 + (num[i] - '0');

    return temp;
}

uc **allocateGrid(uc **m1, ull row, ull col) {
    m1 = (uc **) malloc(sizeof(uc *) * row);
    if(m1 == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }

    for(ull i = 0 ; i < row ; i++) {
        m1[i] = calloc(col, sizeof(uc));    
        if(m1[i] == NULL) {
            printf("Memory not allocated\n");
            exit(1);
        }
    }
    return m1;
}

void printGrid(uc **m, ull row, ull col) {
    for(ull i = 0 ; i < row ; i++) {
        for(ull j = 0 ; j < col ; j++)
            printf("[%u] ", m[i][j]);
        printf("\n");
    }
}

void freeGrid(uc **m, ull row) {
    for (ull i = 0 ; i < row ; i++)
        free(m[i]);
    free(m);
}