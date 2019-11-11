#ifndef Desenho_h
#define Desenho_h

#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaDesenho (Imagem *img, Cor primitiva);

void leDesenho (Imagem *img);

void alocaMemoria (Imagem *img);

void liberaMemoria (Imagem *img);

#endif