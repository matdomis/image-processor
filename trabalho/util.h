#ifndef UTIL_H
#define UTIL_H

#include "image.h"

// Aloca estruturas das imagens
void allocateImages(_PGMImage **, _PGMImage **);

// Converte uma string em unsigned long int
ull atoul(char *);

// Aloca matriz de uc na heap
uc **allocateGrid(uc **, ull, ull);

// Printa uma matriz
void printGrid(uc **, ull, ull);

// Libera espaço na memórioa após uso da grid
void freeGrid(uc **, ull);

#endif
