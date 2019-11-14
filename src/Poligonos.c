#include "Poligonos.h"


void desenhaReta (Imagem *img, Cor primitiva) {
	int x1, x2, y1, y2, x3, y3, i, angulo;

	scanf("%d %d", &x1, &y1);

	scanf("%d %d", &x2, &y2);

	leDesenho(img);

	x3 = x1;
	y3 = y1;

	angulo = (float) (y2 - y1) / (x2 - x1);

	if (y2 = y1) {
		while (x3 != x2) {
			img->MatrizDesenho[x3][y3].R = primitiva.R;
			img->MatrizDesenho[x3][y3].G = primitiva.G;
			img->MatrizDesenho[x3][y3].B = primitiva.B;
			x3++;
		}
	}

	salvaDesenho(img);
}