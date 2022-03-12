#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "util.h"

#define MAX_LINE_SIZE 1024

int openFile(FILE **input, char *fileName, char mode) {
    if (mode == READ) { 

        // Checa se filename foi setado na linha de comando
        if (fileName == NULL) 
            *input = stdin;
        else 
            *input = fopen(fileName, "r");

        if (!(*input)) {
            perror("Error opening the file!");
            exit(1);
        }
    }
    else if (mode == WRITE) {
        
        // Checa se filename foi setado na linha de comando
        if (fileName == NULL) 
            *input = stdout;
        else 
            *input = fopen(fileName, "w");

        if (!(*input)) {
            perror("Error opening the file!");
            exit(1);
        }
    }

    return 1;
}

void getFileType(FILE *input, int *type) {
    char buffer[3];

    // Pula possiveis comentários no ínicio
    fgets(buffer, 3, input);
    while(buffer[0] == '#')
        fgets(buffer, 3, input);

    if (strcmp(buffer, "P2") == 0) 
        *type = FILE_P2;
    else if (strcmp(buffer, "P5") == 0) 
        *type = FILE_P5;
    else {
        perror("Error: type of file is invalid (only P2 or P5 allowed)");
        exit(1);
    }
}

void getFileDimensions(FILE *input, int type, ull *row, ull *col) {
    char buffer[MAX_LINE_SIZE+1];

    // Pula tipo do arquivo e possiveis comentários até as dimensões da imagem
    fgets(buffer, MAX_LINE_SIZE, input);
    while(!isalnum(buffer[0])) 
        fgets(buffer, MAX_LINE_SIZE, input);


    // Buffer contém as dimensões da imagem, agora bastar separar cada valor e armazenar em row e col
    sscanf(buffer, "%lu %lu", row, col);
}

void getFileMaxGray(FILE *input, int *max_gray) {
    char buffer[MAX_LINE_SIZE+1];
    
    // Pula possiveis comentários até max_gray
    fgets(buffer, MAX_LINE_SIZE, input);
    while(!isalnum(buffer[0])) 
        fgets(buffer, MAX_LINE_SIZE, input);
    
    *max_gray = atoi(buffer);
}   

void createOutputFile(FILE *output, _PGMImage *outputImage) {
    // Escreve tipo
    if (outputImage->type == FILE_P2) 
        fprintf(output, "%s\n", "P2");
    else if (outputImage->type == FILE_P5)
        fprintf(output, "%s\n", "P5");

    // Escreve dimensões
    fprintf(output, "%lu %lu\n", outputImage->row, outputImage->col);

    // Escreve valor máximo de cinza
    fprintf(output, "%d\n", outputImage->max_gray);

    // Escreve valores da matriz
    if (outputImage->type == FILE_P2) {
        for(ull i = 0 ; i < outputImage->row ; i++) {
            for(ull j = 0 ; j < outputImage->col ; j++)
                fprintf(output, "%d ", outputImage->grid[i][j]);
        }
    }
    else if (outputImage->type == FILE_P5) {
        for(ull i = 0 ; i < outputImage->row ; i++) {
            for(ull j = 0 ; j < outputImage->col ; j++)
                fputc(outputImage->grid[i][j], output);
        }
    }
}