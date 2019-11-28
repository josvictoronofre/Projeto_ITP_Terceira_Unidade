#ifndef Poligonos_h
#define Poligonos_h

#include "Desenho.h"

void poligonoRetangulo (Imagem *img, Cor primitiva);

void desenhaReta (Imagem *img, Ponto origem, Ponto final, Cor primitiva);

void checaPonto (int *x, int *y, int xmax, int ymax);

void DesenhaCirculo (Imagem *img, Cor primitiva);

void desenhaPoligono (Imagem *img, Cor primitiva);

#endif