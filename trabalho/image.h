#ifndef IMAGE_H
#define IMAGE_H

#include "file.h"

typedef struct _PGMImage {
    int type;
    ull row;
    ull col;
    
    int max_gray;
    uc **grid;
} _PGMImage;

void getImageGrid(FILE *, uc **, ull, ull);


#endif