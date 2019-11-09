#ifndef Desenho_h
#define Desenho_h

#include "Struct.h"

void criaDesenho (Cor primitiva);

Cor leDesenho (char *tipoImagem, unsigned short *Mlinhas, unsigned short *Mcolunas, unsigned short MaximoPixels);

Cor alocaMatriz (Cor **MatrizDesenho, const unsigned short Nlinhas, const unsigned short Ncolunas);

void salvaDesenho (Cor ** MatrizDesenho, char tipoImagem[], unsigned short Mlinhas, unsigned short Mcolunas, unsigned short MaximoPixels);

#endif