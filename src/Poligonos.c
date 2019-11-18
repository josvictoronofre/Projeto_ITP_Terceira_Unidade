#include "Poligonos.h"


void desenhaRetangulo (Imagem *img, Cor primitiva) {
	unsigned short int x1, y1, altura, largura, i , j;
	float angulo;

	printf("Especifique os valores x e y do ponto inicial:\n");

	scanf("%hu %hu", &x1, &y1);

	printf("Especifique a altura e a largura do retangulo:\n");

	scanf("%hu %hu", &altura, &largura);

	for (i = y1; i < altura; i++) {
		for (j = x1; j < largura; j++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;
		}
	}
}