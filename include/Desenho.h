#ifndef Desenho_h
#define Desenho_h

#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void criaDesenho (Imagem *img, Cor primitiva);

void leDesenho (Imagem *img);

void alocaMemoria (Imagem *img);

void liberaMemoria (Imagem *img);

void salvaDesenho (Imagem *img);

void escolheCor (Cor *primitiva);

void limpaDesenho (Imagem *img, Cor primitiva);

void passaDesenho(Imagem *img, Imagem *pivo);

void printaOpcoes ();

#endif