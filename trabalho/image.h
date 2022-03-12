#ifndef IMAGE_H
#define IMAGE_H

#define ull unsigned long int
#define uc unsigned char

#include <stdio.h>

typedef struct _PGMImage {
    int type;
    int max_gray;
    ull row;
    ull col;
    uc **grid;

} _PGMImage;

/* Pega valores da grid do arquivo de input e armazena na grid da estrutura inputImage */
void getImageGrid(FILE *, uc **, ull, ull, int);

/* Função de filtro negativo */
void filtroNegativo(_PGMImage *, _PGMImage *);

/* Função de rotação simples */
void rotacaoSimples(_PGMImage *, _PGMImage *);

#endif