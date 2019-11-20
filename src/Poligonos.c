#include "Poligonos.h"


void poligonoRetangulo (Imagem *img, Cor primitiva) {
	int x, y, i, j, altura, largura;

	printf("Insira os valores x e y do retangulo:\n");

	checaPonto(&x, &y, img->Ncolunas, img->Nlinhas);

	printf("Insira a altura e largura do retangulo:\n");

	scanf("%d %d", &altura, &largura);

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

void desenhaReta (Imagem *img, Cor primitiva) {
	int x1, y1, x2, y2, i = 0, j = 0;
	float anguloy, angulox, deslocacao = 0;

	printf("Insira os valores x e y do ponto inicial:\n");

	checaPonto(&x1, &y1, img->Ncolunas, img->Nlinhas);

	printf("Insira os valores x e y do ponto final:\n");

	checaPonto(&x2, &y2, img->Ncolunas, img->Nlinhas);

	anguloy =(float) (y2 - y1) / (x2 - x1);
	angulox =(float) (x2 - x1) / (y2 - y1);

	if (x2 >= x1 && y2 >= y1) {
		if (anguloy < 1) {
			j = y1;
			for (i = x1; i <= x2; i++) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				deslocacao += anguloy;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j++;
				}
			}
		} else {
			j = x1;
			for (i = y1; i <= y2; i++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				deslocacao += angulox;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j++;
				}
			}
		}
	} else if (x1 > x2 && y1 > y2) {
		if (anguloy < 1) {
			j = y1;
			for (i = x2; i <= x1; i++) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				deslocacao += anguloy;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j++;
				}
			}
		} else {
			j = x1;
			for (i = y2; i <= y1; i++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				deslocacao += angulox;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j++;
				}
			}
		}
	} else if (x2 >= x1 && y2 <= y1) {
		if (anguloy > -1) {
			j = y1;
			for (i = x1; i <= x2; i++) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				deslocacao += anguloy;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j--;
				}
			}
		} else {
			j = x1;
			for (i = y2; i <= y1; i++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				deslocacao += angulox;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j--;
				}
			}
		}
	} else if (x2 < x1 && y2 > y1) {
		if (anguloy > -1) {
			j = y1;
			for (i = x1; i >= x2; i--) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				deslocacao += anguloy;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j++;
				}
			}
		} else {
			j = x1;
			for (i = y1; i <= y2; i++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				deslocacao += angulox;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j--;
				}
			}
		}
	}
}

void checaPonto (int *x, int *y, const int xmax, const int ymax) {
	while (1 == 1) {
		scanf("%d %d", x, y);
		if (*x > xmax || *x < 0 || *y > ymax || y < 0) {
			printf("valores das cordenadas do ponto invalidos!\n");
			printf("Insira os valores novamente:\n");
		} else
			return;

	}
}