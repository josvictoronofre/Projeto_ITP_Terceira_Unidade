#include "Poligonos.h"


void desenhaRetangulo (Imagem *img, Cor primitiva) {
	int x, y, i, j, altura, largura;

	printf("Insira os valores x e y do retangulo:\n");

	scanf("%d %d", &x, &y);

	printf("Insira a altura e largura do retangulo:\n");

	scanf("%d %d", &altura, &largura);

	for (i = 0; i < largura; i++) {
		img->MatrizDesenho[y][x+i].R = primitiva.R;
		img->MatrizDesenho[y][x+i].G = primitiva.G;
		img->MatrizDesenho[y][x+i].B = primitiva.B;

		img->MatrizDesenho[y+altura][x+i].R = primitiva.R;
		img->MatrizDesenho[y+altura][x+i].G = primitiva.G;
		img->MatrizDesenho[y+altura][x+i].B = primitiva.B;

	}

	for (j = 0; j < altura; j++) {
		img->MatrizDesenho[y+j][x].R = primitiva.R;
		img->MatrizDesenho[y+j][x].G = primitiva.G;
		img->MatrizDesenho[y+j][x].B = primitiva.B;

		img->MatrizDesenho[y+j][x+largura].R = primitiva.R;
		img->MatrizDesenho[y+j][x+largura].G = primitiva.G;
		img->MatrizDesenho[y+j][x+largura].B = primitiva.B;
	}
}