#ifndef UTIL_H
#define UTIL_H

#include "image.h"

/* Aloca estruturas das imagens */
void allocateImages(_PGMImage **, _PGMImage **);

/* Aloca matriz de unsigned char (grid da imagem) */
uc **allocateGrid(uc **, ull, ull);

/* Printa a grid da imagem (usado nos testes do programa, não é necessário) */
void printGrid(uc **, ull, ull);

/* Libera espaço na memória alocada para Grid */
void freeGrid(uc **, ull);

#endif
