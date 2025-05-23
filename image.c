#include <stdio.h>
#include <math.h>

#include "image.h"
#include "util.h"
#include "file.h"

void getImageGrid(FILE *input, uc **m, ull row, ull col, int type) {
    int value;
   
    // Imagem P2
    if (type == 1) {
        for(ull i = 0 ; i < row ; i++) {
            for(ull j = 0 ; j < col ; j++) {
                fscanf(input, " %d", &value); 
                m[i][j] = (uc)value;
            }
        }
    }

    // Imagem P5
    else if (type == 2) {
        for(ull i = 0 ; i < row ; i++) {
            for(ull j = 0 ; j < col ; j++) {
                value = fgetc(input);
                m[i][j] = (uc)value;
            }
        }
    }
}

void filtroNegativo(_PGMImage *inputImage, _PGMImage *outputImage) {
    outputImage->type = inputImage->type;
    outputImage->row = inputImage->row;
    outputImage->col = inputImage->col;
    outputImage->max_gray = inputImage->max_gray;

    outputImage->grid = allocateGrid(outputImage->grid, outputImage->row, outputImage->col); // ??

    for(ull i = 0 ; i < inputImage->row ; i++)
        for(ull j = 0 ; j < inputImage->col ; j++)
            outputImage->grid[i][j] = (uc)(inputImage->max_gray - inputImage->grid[i][j]);
}

void rotacaoSimples(_PGMImage *inputImage, _PGMImage *outputImage) {
    outputImage->type = inputImage->type;
    outputImage->row = inputImage->row;
    outputImage->col = inputImage->col;
    outputImage->max_gray = inputImage->max_gray;

    outputImage->grid = allocateGrid(outputImage->grid, outputImage->row, outputImage->col); // ??    

    for(ull i = 0 ; i < inputImage->row ; i++)
        for(ull j = 0 ; j < inputImage->col ; j++)
            outputImage->grid[j][i] = inputImage->grid[inputImage->row - 1 - i][j];
}

void reduzRuido(_PGMImage *inputImage, _PGMImage *outputImage) {
    outputImage->type = inputImage->type;
    outputImage->row = inputImage->row;
    outputImage->col = inputImage->col;
    outputImage->max_gray = inputImage->max_gray;

    outputImage->grid = allocateGrid(outputImage->grid, outputImage->row, outputImage->col); // ??  


    int count;
    float sum;
    for(ull i = 0 ; i < inputImage->row ; i++) {
        for(ull j = 0 ; j < inputImage->col ; j++) {
            sum = 0;
            count = 0;

            for(int k = 0 ; k < 3 ; k++) {
                for(int l = 0 ; l < 3 ; l++) {
                    if(pixel_is_valid(inputImage->row, inputImage->col, i-1+k, j-1+l)) {
                        sum += inputImage->grid[i-1+k][j-1+l];
                        count++;
                    }
                }
            }

            outputImage->grid[i][j] = (uc)(sum/count);
        }
    }
}

void filtroLimiar(_PGMImage *inputImage, _PGMImage *outputImage, int limiar) {
    outputImage->type = inputImage->type;
    outputImage->row = inputImage->row;
    outputImage->col = inputImage->col;
    outputImage->max_gray = inputImage->max_gray;

    outputImage->grid = allocateGrid(outputImage->grid, outputImage->row, outputImage->col); // ??  

    for(ull i = 0 ; i < inputImage->row ; i++) {
        for(ull j = 0 ; j < inputImage->col ; j++) {
            if (inputImage->grid[i][j] >= limiar) 
                outputImage->grid[i][j] = inputImage->max_gray;
            
            else 
                outputImage->grid[i][j] = 0;
        }
    }            

}