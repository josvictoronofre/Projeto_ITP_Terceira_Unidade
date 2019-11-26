#include "Poligonos.h"


void poligonoRetangulo (Imagem *img, Cor primitiva) {
	int i, j, altura, largura, pivoaltura, pivolargura;
	Ponto pivo;

	printf("Insira os valores x e y do retangulo:\n");

	checaPonto(&pivo.x, &pivo.y, img->Ncolunas, img->Nlinhas);

	printf("Insira a altura e largura do retangulo:\n");

	scanf("%d %d", &pivoaltura, &pivolargura);

	if(pivo.x + pivolargura > img->Ncolunas || pivo.y + pivoaltura > img->Nlinhas) {
		printf("Altura e/ou largura invalidas. Tente novamente:\n");
	} else {
		altura = pivoaltura;
		largura = pivolargura;
	}

	altura += pivo.y;
	largura += pivo.x;

	for (i = pivo.x; i < largura; i++) {
		img->MatrizDesenho[pivo.y][i].R = primitiva.R;
		img->MatrizDesenho[pivo.y][i].G = primitiva.G;
		img->MatrizDesenho[pivo.y][i].B = primitiva.B;

		img->MatrizDesenho[altura][i].R = primitiva.R;
		img->MatrizDesenho[altura][i].G = primitiva.G;
		img->MatrizDesenho[altura][i].B = primitiva.B;

	}

	for (j = pivo.y; j < altura; j++) {
		img->MatrizDesenho[j][pivo.x].R = primitiva.R;
		img->MatrizDesenho[j][pivo.x].G = primitiva.G;
		img->MatrizDesenho[j][pivo.x].B = primitiva.B;

		img->MatrizDesenho[j][largura].R = primitiva.R;
		img->MatrizDesenho[j][largura].G = primitiva.G;
		img->MatrizDesenho[j][largura].B = primitiva.B;
	}
}

void desenhaReta (Imagem *img, Ponto origem, Ponto final, Cor primitiva) {
	int i = 0, j = 0;
	float anguloy, angulox, deslocacao = 0;

	anguloy =(float) (final.y - origem.y) / (final.x - origem.x);
	angulox =(float) (final.x - origem.x) / (final.y - origem.y);

	if (final.x >= origem.x && final.y >= origem.y) {
		if (anguloy < 1) {
			j = origem.y;
			for (i = origem.x; i <= final.x; i++) {
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
			j = origem.x;
			for (i = origem.y; i <= final.y; i++) {
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
	} else if (origem.x > final.x && origem.y > final.y) {
		if (anguloy < 1) {
			j = origem.y;
			for (i = final.x; i <= origem.x; i++) {
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
			j = origem.x;
			for (i = final.y; i <= origem.y; i++) {
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
	} else if (final.x >= origem.x && final.y <= origem.y) {
		if (anguloy > -1) {
			j = origem.y;
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
			j = origem.x;
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
	} else if (final.x < origem.x && final.y > origem.y) {
		if (anguloy > -1) {
			j = origem.y;
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
			j = origem.x;
			for (i = origem.y; i <= final.y; i++) {
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

void checaPonto (int *x, int *y, int xmax, int ymax) {
	xmax--;
	ymax--;
	while (1) {
		if (*x > xmax || *x < 0 || *y > ymax || y < 0) {
			printf("valores das cordenadas do ponto invalidos!\n");
			printf("Insira os valores novamente:\n");
		} else
			return;

	}
}

void DesenhaCirculo (Imagem *img, Cor primitiva) {
	unsigned short int x, y, i, raio;

	printf("Insira as coordenadas do centro do circulo:\n");

	scanf("%hu %hu", &x, &y);

	printf("Insira o raio do circulo:\n");

	scanf("%hu", &raio);

	for (i = x; i < (x+raio); i++) {}
}

void desenhaPoligono (Imagem *img, Cor primitiva) {
	int Npontos, i;
	Ponto *Poligono;

	printf("Quantos pontos tera o poligono?\n");

	scanf("%d", &Npontos);

	Poligono = (Ponto *) malloc(Npontos*sizeof(Pontos));

	for (i = 0; i < Npontos; i++) {
		desenhaReta(Poligono[i].x)
	}
}