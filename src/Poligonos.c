#include "Poligonos.h"


void poligonoRetangulo (Imagem *img, Cor primitiva) {
	int i, j, altura, largura, pivoaltura, pivolargura;
	Ponto pivo;

	printf("Insira os valores x e y do retangulo:\n");

	scanf("%d %d", &pivo.x, &pivo.y);

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

void desenhaReta (Imagem *img, Ponto origem, Ponto final, Cor primitiva, Ponto *vetor, int *contador) {
	int i = 0, j = 0;
	float anguloy, angulox, deslocacao = 0;

	anguloy =(float) (final.y - origem.y) / (final.x - origem.x);
	angulox =(float) (final.x - origem.x) / (final.y - origem.y);

	if (final.x >= origem.x && final.y >= origem.y) {
		if (anguloy < 1) {
			j = origem.y;
			for (i = origem.x; i < final.x; i++) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				salvaPonto(vetor, i, j, contador);


				deslocacao += anguloy;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j++;
				}
			}
		} else {
			j = origem.x;
			for (i = origem.y; i < final.y; i++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				salvaPonto(vetor, j, i, contador);

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
			for (i = origem.x; i > final.x; i--) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				salvaPonto(vetor, i, j, contador);

				deslocacao += anguloy;

				while (deslocacao >= 1) {
					deslocacao = deslocacao - 1;
					j--;
				}
			}
		} else {
			j = origem.x;
			for (i = origem.y; i > final.y; i--) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				salvaPonto(vetor, j, i, contador);

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
			for (i = origem.x; i < final.x; i++) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				salvaPonto(vetor, i, j, contador);

				deslocacao += anguloy;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j--;
				}
			}
		} else {
			j = origem.x;
			for (i = origem.y; i > final.y; i--) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				salvaPonto(vetor, j, i, contador);

				deslocacao += angulox;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j++;
				}
			}
		}
	} else if (final.x <= origem.x && final.y >= origem.y) {
		if (anguloy > -1) {
			j = origem.y;
			for (i = origem.x; i > final.x; i--) {
				img->MatrizDesenho[j][i].R = primitiva.R;
				img->MatrizDesenho[j][i].G = primitiva.G;
				img->MatrizDesenho[j][i].B = primitiva.B;

				salvaPonto(vetor, i, j, contador);

				deslocacao += anguloy;

				while (deslocacao <= -1) {
					deslocacao = deslocacao + 1;
					j++;
				}
			}
		} else {
			j = origem.x;
			for (i = origem.y; i < final.y; i++) {
				img->MatrizDesenho[i][j].R = primitiva.R;
				img->MatrizDesenho[i][j].G = primitiva.G;
				img->MatrizDesenho[i][j].B = primitiva.B;

				salvaPonto(vetor, j, i, contador);

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
			scanf("%d %d", x, y);
		} else
			return;

	}
}
/*
void DesenhaCirculo (Imagem *img, Cor primitiva) {
	unsigned short int x, y, i, j, raio;
	Imagem pivo;
	pivo.Nlinhas = img->Nlinhas;
	pivo.Ncolunas = img->Ncolunas;

	alocaMemoria(&pivo);

	passaDesenho(&pivo, img);

	printf("Insira as coordenadas do centro do circulo:\n");

	scanf("%hu %hu", &x, &y);

	checaPonto(&x, &y, img->Ncolunas, img->Nlinhas);

	printf("Insira o raio do circulo:\n");

	scanf("%hu", &raio);

	for (i = 0; i < raio; i++) {
		if ((i % 2) == 0) {
			pivo.MatrizDesenho[y+raio][x+(i/2)].R = primitiva.R;
		}
	}
}
*/
void desenhaPoligono (Imagem *img, Cor primitiva) {
	int Npontos, i, contador = 0;
	Ponto *poligono;
	Ponto *vetor;
	Imagem pivo;

	vetor = (Ponto *) calloc(2240, sizeof(Ponto));

	pivo.Nlinhas = img->Nlinhas;
	pivo.Ncolunas = img->Ncolunas;
	pivo.tipoImagem[0] = 'P';
	pivo.tipoImagem[1] = '3';
	pivo.tipoImagem[2] = '\0';
	pivo.Maximopixels = img->Maximopixels;

	printf("Quantos pontos tera o poligono?\n");

	scanf("%d", &Npontos);

	if (Npontos <= 2) {
		printf("Poligono precisa ter mais de 2 pontos\n");
		return;
	} else {

		poligono = (Ponto *) malloc(Npontos*sizeof(Ponto));

		for (i = 0; i < Npontos; i++) {
			printf("Insira as coordenadas do ponto %d:\n", (i+1));

			scanf("%d %d", &poligono[i].x, &poligono[i].y);
		}

		alocaMemoria(&pivo);

		passaDesenho(&pivo, img);

		contador = 1;

		for (i = 0; i < Npontos; i++) {
			if (i == (Npontos - 1)) {
				desenhaReta(&pivo, poligono[i], poligono[0], primitiva, vetor, &contador);
			} else {
				desenhaReta(&pivo, poligono[i], poligono[i+1], primitiva, vetor, &contador);
			}
		}

		if (checaVetor(vetor, contador)) {
			printf("Valores de poligono invalidos!\n");
			return;
		} else {
			passaDesenho(img, &pivo);
		}
		liberaMemoria(&pivo);
		free(vetor);
	}
	
}
	

void salvaPonto(Ponto *vetor, const int coordenadax, const int coordenaday, int *contador) {
	*contador = (*contador) + 1;

	vetor[(*contador) - 1].x = coordenadax;
	vetor[(*contador) - 1].y = coordenaday;
}

bool checaVetor (Ponto *vetor, int contador) {
	unsigned long int i, j;
	for (i = 0; i < (contador - 1); i++) {
		for (j = 0; j< (contador - 1); j++) {
			if (i == j) {
				continue;
			} else {
				if (vetor[i].x == vetor[j].x && vetor[i].y == vetor[j].y) {
					return true;
				}
			}
		}
	}
	return false;
}

void pintaDesenho (Imagem *img, Cor primitiva, int x, int y) {

	short int cima, direita, esquerda, baixo;

	cima = y;
	baixo = y;

	direita = x;
	esquerda = x;
		
		baixo++;
		if (baixo < img->Nlinhas) {

			img->MatrizDesenho[cima][x].R = primitiva.R;
			img->MatrizDesenho[cima][x].G = primitiva.G;
			img->MatrizDesenho[cima][x].B = primitiva.B;
		
			pintaDesenho(img, primitiva, x, cima);
		}

		direita++;

		if (direita < img->Ncolunas) {

			img->MatrizDesenho[y][direita].R = primitiva.R;
			img->MatrizDesenho[y][direita].G = primitiva.G;
			img->MatrizDesenho[y][direita].B = primitiva.B;

			pintaDesenho(img, primitiva, direita, y);
		}

		esquerda--;

		if (esquerda >= 0) {

			img->MatrizDesenho[y][esquerda].R = primitiva.R;
			img->MatrizDesenho[y][esquerda].G = primitiva.G;
			img->MatrizDesenho[y][esquerda].B = primitiva.B;

			pintaDesenho(img, primitiva, esquerda, y);
		}

		cima--;

		if (cima >= 0) {

			img->MatrizDesenho[baixo][x].R = primitiva.R;
			img->MatrizDesenho[baixo][x].G = primitiva.G;
			img->MatrizDesenho[baixo][x].B = primitiva.B;
	
			pintaDesenho(img, primitiva, x, baixo);
		}

}

void funcaoPintar (Imagem *img, Cor primitiva) {
	Ponto posicao;
	//Cor inicial;

	printf("Insira os valores x e y do ponto inicial:\n");

	scanf("%d %d", &posicao.x, &posicao.y);

	checaPonto(&posicao.x, &posicao.y, img->Ncolunas, img->Nlinhas);
	/*
	inicial.R = img->MatrizDesenho[posicao.y][posicao.x].R;
	inicial.G = img->MatrizDesenho[posicao.y][posicao.x].G;
	inicial.B = img->MatrizDesenho[posicao.y][posicao.x].B;
	*/
	img->MatrizDesenho[posicao.y][posicao.x].R = primitiva.R;
	img->MatrizDesenho[posicao.y][posicao.x].G = primitiva.G;
	img->MatrizDesenho[posicao.y][posicao.x].B = primitiva.B;

	pintaDesenho(img, primitiva, posicao.x, posicao.y);



}