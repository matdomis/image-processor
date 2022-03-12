#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

#include "file.h"
#include "util.h"
#include "image.h"

int main(int argc, char *argv[]) {
    _PGMImage *inputImage, *outputImage;
    FILE *input;
    FILE *output;

    char *inputFile;
    char *outputFile; 

    /* linha de comando */
    if (argc > 1) {
        int i = 0;
        while(++i < argc) {
            if (strcmp(argv[i], "-i") == 0)
                inputFile = argv[i+1];
            else if (strcmp(argv[i], "-o") == 0)
                outputFile = argv[i+1];
            else if ()
        }
    }

    allocateImages(&inputImage, &outputImage);

    openFile(&input, inputFile, READ);

    getFileType(input, &inputImage->type);

    getFileDimensions(input, inputImage->type, &inputImage->row, &inputImage->col);
   
    getFileMaxGray(input, &inputImage->max_gray);

    inputImage->grid = allocateGrid(inputImage->grid, inputImage->row, inputImage->col);
    
    getImageGrid(input, inputImage->grid, inputImage->row, inputImage->col, inputImage->type);
 
    openFile(&output, outputFile, WRITE);
    
    /*  ~~~~ Redução de Ruído ~~~~ */
    limiar(inputImage, outputImage);
    /*  ~~~~~~~~~~~~~~~~~~~~~~~~~ */

    createOutputFile(output, outputImage);

    freeGrid(inputImage->grid, inputImage->row);
    fclose(input);
    fclose(output);
    return 0;
}
