#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <stdio.h>
#include <ctype.h>

#include "image.h"

#define FILE_P2 1
#define FILE_P5 2

#define WRITE 'W'
#define READ 'R'

#define MAX_LINE_SIZE 1024

#ifndef ull
#define ull unsigned long int
#endif

#ifndef uc
#define uc unsigned char
#endif

/* Cria arquivo de input/output */
int openFile(FILE **, char *, char);

/* Lê tipo do arquivo  */
void getFileType(FILE *, int *);

/* Pega as dimensões do da imagem */
void getFileDimensions(FILE *, int, ull *, ull *);

/* Pega valor máximo de cinza */
void getFileMaxGray(FILE *, int *);

/* Cria o arquivo de saída com toda a formatação necessária */
void createOutputFile(FILE *, _PGMImage *);

#endif