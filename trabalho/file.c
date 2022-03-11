#include "file.h"
#include "util.h"


#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int openFile(FILE **input, char *fileName) {
    *input = fopen(fileName, "r");

    if (!(*input)) {
        perror("Error opening the file!");
        exit(1);
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
    else
        *type = FILE_INVALID;

}

void getFileDimensions(FILE *input, int type, ull *row, ull *col) {
    char buffer[MAX_LINE_SIZE+1];

    // Pula tipo do arquivo e possiveis comentários até as dimensões da imagem
    fgets(buffer, MAX_LINE_SIZE, input);
    while(!isalnum(buffer[0])) 
        fgets(buffer, MAX_LINE_SIZE, input);


    // Buffer contém as dimensões da imagem, agora bastar separar cada valor e armazenar em row e col
    char *token = strtok(buffer, " ");
    *row = atoul(token);

    token = strtok(NULL, "\n");
    *col = atoul(token);
}

void getFileMaxGray(FILE *input, int *max_gray) {
    char buffer[MAX_LINE_SIZE+1];
    
    // Pula possiveis comentários até max_gray
    fgets(buffer, MAX_LINE_SIZE, input);
    while(!isalnum(buffer[0])) 
        fgets(buffer, MAX_LINE_SIZE, input);
    
    *max_gray = atoi(buffer);
}