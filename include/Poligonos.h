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

void funcaoFill (Imagem *img, Cor primitiva);

void FillUp (Imagem *img, Cor primitiva, Ponto origem, Cor inicial);

void FillRight (Imagem *img, Cor primitiva, Ponto origem, Cor inicial);

void FillLeft (Imagem *img, Cor primitiva, Ponto origem, Cor inicial);

void FillDown (Imagem *img, Cor primitiva, Ponto origem, Cor inicial);

bool FillCor (Imagem *img, Cor inicial, Ponto origem);
#endif
