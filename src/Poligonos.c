#include "Poligonos.h"


void poligonoRetangulo (Imagem *img, Cor primitiva) {
	int i, j, altura, largura, pivoaltura, pivolargura;
	Ponto pivo;

	printf("Insira os valores x e y do retangulo:\n");

	checaPonto(&pivo.x, &pivo.y, img->Ncolunas, img->Nlinhas);

	printf("Insira a altura e largura do retangulo:\n");

	scanf("%d %d", &pivoaltura, &pivolargura);

	while (1) {
		if ((pivo.x + pivolargura) >= img->Ncolunas || (pivo.y + pivoaltura) >= img->Nlinhas) {
			printf("Valores de altura e/ou largura invalidos. Insira novos valores:\n");

			scanf("%d %d", &pivoaltura, &pivolargura);
		} else {
			altura = pivoaltura;
			largura = pivolargura;
			break;
		}
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

void desenhaReta (Imagem *img, Ponto origem, Ponto final, Cor primitiva, Ponto *vetor, int *contador, int *controle) {
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

				salvaPonto(vetor, i, j, contador, controle);


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

				salvaPonto(vetor, j, i, contador, controle);

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
			for (i = origem.x; i >= final.x; i--) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				salvaPonto(vetor, i, j, contador, controle);

				deslocacao += anguloy;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j--;
				}
			}
		} else {
			j = origem.x;
			for (i = origem.y; i >= final.y; i--) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				salvaPonto(vetor, j, i, contador, controle);

				deslocacao += angulox;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j--;
				}
			}
		}
	} else if (final.x >= origem.x && final.y <= origem.y) {
		if (anguloy > -1) {
			j = origem.y;
			for (i = origem.x; i <= final.x; i++) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				salvaPonto(vetor, i, j, contador, controle);

				deslocacao += anguloy;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j--;
				}
			}
		} else {
			j = origem.x;
			for (i = final.y; i <= origem.y; i++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				salvaPonto(vetor, j, i, contador, controle);

				deslocacao += angulox;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j--;
				}
			}
		}
	} else if (final.x <= origem.x && final.y >= origem.y) {
		if (anguloy > -1) {
			j = origem.y;
			for (i = origem.x; i >= final.x; i--) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				salvaPonto(vetor, i, j, contador, controle);

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

				salvaPonto(vetor, j, i, contador, controle);

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
	int Npontos, i, contador, controle = 0;
	Ponto *poligono;
	Ponto *vetor;
	Imagem pivo;

	pivo.Nlinhas = img->Nlinhas;
	pivo.Ncolunas = img->Ncolunas;
	pivo.tipoImagem[0] = 'P';
	pivo.tipoImagem[1] = '3';
	pivo.Maximopixels = img->Maximopixels;

	vetor = (Ponto *) malloc(1*sizeof(Ponto));

	printf("Quantos pontos tera o poligono?\n");

	scanf("%d", &Npontos);

	Npontos++;

	poligono = (Ponto *) malloc(Npontos*sizeof(Ponto));

	for (i = 0; i < (Npontos - 1); i++) {
		printf("Insira as coordenadas do ponto %d:\n", (i+1));

		scanf("%d %d", &poligono[i].x, &poligono[i].y);
	}

	poligono[Npontos - 1] = poligono[0];

	alocaMemoria(&pivo);

	for (i = 0; i < (Npontos - 1); i++) {
		desenhaReta(&pivo, poligono[i], poligono[i+1], primitiva, vetor, &contador, &controle);
	}

	if (controle > 0) {
		printf("Valores das coordenadas do Poligono invalidos!\n");
	} else {
		passaDesenho(img, pivo);
	}
}

void salvaPonto(Ponto *vetor, const int coordenadax, const int coordenaday, int *contador, int *controle) {
	unsigned short int i;

	vetor = (Ponto *) realloc(vetor, *contador*sizeof(Ponto));
	vetor[*contador].x = coordenadax;
	vetor[*contador].y = coordenaday;

	for (i = 0; i< *contador; i++) {
		if(vetor[i].x == coordenadax && vetor[i].y == coordenaday) {
			controle++;
		}
	}

	*contador++;
}