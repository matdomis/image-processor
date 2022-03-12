#include <stdlib.h>
#include <string.h>


#include "util.h"
#include "file.h"
#include "image.h"


void allocateImages(_PGMImage **inputImage, _PGMImage **outputImage) {
    *inputImage = malloc(sizeof(_PGMImage));
    *outputImage = malloc(sizeof(_PGMImage));
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
            printf("[%d] ", m[i][j]);
        printf("\n");
    }
}

void freeGrid(uc **m, ull row) {
    for(ull i = 0 ; i < row ; i++)
        free(m[i]);
    free(m);
}

int pixel_is_valid(ull row, ull col, ull k, ull l) {
    if (k >= row || l >= col || k < 0 || l < 0)
        return 0;
    return 1;
}