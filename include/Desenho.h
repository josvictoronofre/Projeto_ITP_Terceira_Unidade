#ifndef Desenho_h
#define Desenho_h

#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>

void criaDesenho (Cor **MatrizDesenho, Cor primitiva, char *tipoImagem, unsigned short *Nlinhas, unsigned short *Ncolunas, unsigned short *MaximoPixels);

void leDesenho (Cor **MatrizDesenho, char *tipoImagem, unsigned short *Mlinhas, unsigned short *Mcolunas, unsigned short *MaximoPixels);

void alocaMatriz (Cor **MatrizDesenho, const unsigned short Nlinhas, const unsigned short Ncolunas);

void salvaDesenho (Cor ** MatrizDesenho, char tipoImagem[], unsigned short Mlinhas, unsigned short Mcolunas, unsigned short MaximoPixels);

#endif