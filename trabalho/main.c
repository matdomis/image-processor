#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "util.h"
#include "image.h"



int main() {
    _PGMImage *inputImage, *outputImage;
    FILE *input;

    
    char fileName[] = "moon.pgm";
    char buffer[200];

    allocateImages(&inputImage, &outputImage);

    openFile(&input, fileName);

    getFileType(input, &inputImage->type);

    getFileDimensions(input, inputImage->type, &inputImage->row, &inputImage->col);
   
    getFileMaxGray(input, &inputImage->max_gray);

    fgets(buffer, 200, input);
    printf("%s", buffer);

    inputImage->grid = allocateGrid(inputImage->grid, inputImage->row, inputImage->col);

    

    printGrid(inputImage->grid, inputImage->row, inputImage->col);






    freeGrid(inputImage->grid, inputImage->row);
    
    // printf("Image Ty%d\n", inputImage->type);
    
    // printf("\nCoordenadas:%lu %lu\n", inputImage->row, inputImage->col);




    fclose(input);
    return 0;
}