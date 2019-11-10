#ifndef Desenho_h
#define Desenho_h

#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>

void criaDesenho (Imagem *img, Cor primitiva);

void leDesenho (Imagem *img);

void alocaMatriz (Imagem *img);

void salvaDesenho (Cor ** MatrizDesenho, char tipoImagem[], unsigned short Mlinhas, unsigned short Mcolunas, unsigned short MaximoPixels);

#endif