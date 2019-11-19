#include "Poligonos.h"


void poligonoRetangulo (Imagem *img, Cor primitiva) {
	int x, y, i, j, altura, largura;

	printf("Insira os valores x e y do retangulo:\n");

	scanf("%d %d", &x, &y);

	printf("Insira a altura e largura do retangulo:\n");

	scanf("%d %d", &altura, &largura);

	posicaoXY(&x, &y, img->Nlinhas, img->Ncolunas);

	altura = y - altura;
	largura += x;

	for (i = x; i < largura; i++) {
		img->MatrizDesenho[y][i].R = primitiva.R;
		img->MatrizDesenho[y][i].G = primitiva.G;
		img->MatrizDesenho[y][i].B = primitiva.B;

		img->MatrizDesenho[altura][i].R = primitiva.R;
		img->MatrizDesenho[altura][i].G = primitiva.G;
		img->MatrizDesenho[altura][i].B = primitiva.B;

	}

	for (j = altura; j < y; j++) {
		img->MatrizDesenho[j][x].R = primitiva.R;
		img->MatrizDesenho[j][x].G = primitiva.G;
		img->MatrizDesenho[j][x].B = primitiva.B;

		img->MatrizDesenho[j][largura].R = primitiva.R;
		img->MatrizDesenho[j][largura].G = primitiva.G;
		img->MatrizDesenho[j][largura].B = primitiva.B;
	}
}

/*void desenhaReta (Imagem *img) {
	int x1, y1, x2, y2, i;
	float angulo;

	printf("Insira os valores x e y do ponto inicial:\n");

	scanf("%d %d", &x1, &y1);

	printf("Insira os valores x e y do ponto final:\n");

	scanf("%d %d", &x2, &y2);

	if (x2 >= x1 && y2 >= y1); {
		if ((x2 - x1) > (y2 - y1)) {
			for (i = x1; i <= x2; i++) {
				angulo += ()
			}
		}
	} 
}*/

void posicaoXY (int *x, int *y, int linhas, int colunas) {
	*x = *x + (colunas / 2);
	*y = (linhas / 2) - *y;
}