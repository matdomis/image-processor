#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <stdio.h>
#include <ctype.h>

#define FILE_P2 1
#define FILE_P5 2
#define FILE_INVALID -1

#define MAX_LINE_SIZE 1024

#define ull unsigned long int
#define uc unsigned char


/* Seta o ponteiro para o arquivo */
int openFile(FILE **, char *);

/* Lê tipo do arquivo  */
void getFileType(FILE *, int *);

/* Pega as dimensões do da imagem */
void getFileDimensions(FILE *, int, ull *, ull *);

void getFileMaxGray(FILE *, int *);

#endif