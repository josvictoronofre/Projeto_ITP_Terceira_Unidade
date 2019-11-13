#include "Poligonos.h"


void desenhaReta (Imagem *img, Cor primitiva) {
	int x1, x2, y1, y2, x3, y3, i;

	scanf("%d %d", &x1, &y1);

	scanf("%d %d", &x2, &y2);

	leDesenho(img);

	x3 = x1;
	y3 = y1;

	if (x2 - x1 >  y2 - y1) {
		for (i = x1; i < x2; i ++) {
			img->MatrizDesenho[x1][y1].R = primitiva.R;
			img->MatrizDesenho[x1][y1].G = primitiva.G;
			img->MatrizDesenho[x1][y1].B = primitiva.B;
			x3++;
			y3 += (y2 - y1) / (x2 - x1);
		}
	}

	salvaDesenho(img);
}