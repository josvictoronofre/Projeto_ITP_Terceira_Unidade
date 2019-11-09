#ifndef Desenho_h
#define Desenho_h

#include "Struct.h"

void criaDesenho (Cor primitiva);

void leDesenho (Cor **MatrizDesenho, char *tipoImagem, unsigned short *Mlinhas, unsigned short *Mcolunas, unsigned short MaximoPixels);

void alocaMatriz (Cor **MatrizDesenho, const unsigned short Nlinhas, const unsigned short Ncolunas);

void salvaDesenho (Cor ** MatrizDesenho, char tipoImagem[], unsigned short Mlinhas, unsigned short Mcolunas, unsigned short MaximoPixels);

#endif