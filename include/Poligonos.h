#ifndef Poligonos_h
#define Poligonos_h

#include "Desenho.h"

void poligonoRetangulo (Imagem *img, Cor primitiva);

void desenhaReta (Imagem *img, Ponto origem, Ponto final, Cor primitiva, Ponto *vetor, int *contador);

void checaPonto (int *x, int *y, int xmax, int ymax);

void DesenhaCirculo (Imagem *img, Cor primitiva);

void desenhaPoligono (Imagem *img, Cor primitiva);

void salvaPonto(Ponto *vetor, const int coordenadax, const int coordenaday, int *contador);

bool checaVetor (Ponto *vetor, int contador);

void pintaDesenho (Imagem *img, Cor primitiva, Ponto posicao, int *cima, int *baixo, int *direita, int *esquerda);

void funcaoPintar (Imagem *img, Cor primitiva);

#endif