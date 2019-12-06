#include "Poligonos.h"

//Desenha o retangulo a partir do ponto inicial, altura e largura
void poligonoRetangulo (Imagem *img, Cor primitiva) {
	int i, j, altura, largura, pivoaltura, pivolargura;
	Ponto pivo;

	printf("Insira os valores x e y do retângulo:\n");

	scanf("%d %d", &pivo.x, &pivo.y);

	checaPonto(&pivo.x, &pivo.y, img->Ncolunas, img->Nlinhas);

	printf("Insira a altura e largura do retângulo:\n");

	scanf("%d %d", &pivoaltura, &pivolargura);

	pivoaltura += pivo.y;
	pivolargura += pivo.x;

	checaPonto(&pivolargura, &pivoaltura, img->Ncolunas, img->Nlinhas);
	
	altura = pivoaltura;
	largura = pivolargura;

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
//Desenha a reta com qualquer inclinacao possivel
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
//checa se os parametros dos pontos sao aceitaveis
void checaPonto (int *x, int *y, int xmax, int ymax) {
	xmax--;
	ymax--;
	while (1) {
		if (*x > xmax || *x < 0 || *y > ymax || y < 0) {
			printf("valores das cordenadas do ponto inválidos!\n");
			printf("Insira os valores novamente:\n");
			scanf("%d %d", x, y);
		} else
			return;

	}
}
//Desenha o poligono a partir de um vetor de pontos utilizando a funcao desenhaReta
void desenhaPoligono (Imagem *img, Cor primitiva) {
	int Npontos, i, contador = 0;
	Ponto *poligono;
	Ponto *vetor;
	Imagem pivo;

	//vetor que vai armazenar todos os pontos modificados pela funcao desenhaReta
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
	
//Salva o ponto modificado pela reta no vetor dos pontos
void salvaPonto(Ponto *vetor, const int coordenadax, const int coordenaday, int *contador) {
	*contador = (*contador) + 1;

	vetor[(*contador) - 1].x = coordenadax;
	vetor[(*contador) - 1].y = coordenaday;
}
//verifica se o vetor de todos os pontos do poligono se repete
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

void funcaoFill (Imagem *img, Cor primitiva) {
	Cor inicial;
	Ponto escolha;
	
	printf("Insira as coordenadas do ponto inicial:\n");

	scanf("%d %d", &escolha.x, &escolha.y);

	checaPonto(&escolha.x, &escolha.y, img->Ncolunas, img->Nlinhas);

	inicial.R = img->MatrizDesenho[escolha.y][escolha.x].R;
	inicial.G = img->MatrizDesenho[escolha.y][escolha.x].G;
	inicial.B = img->MatrizDesenho[escolha.y][escolha.x].B;

	img->MatrizDesenho[escolha.y][escolha.x].R = primitiva.R;
	img->MatrizDesenho[escolha.y][escolha.x].G = primitiva.G;
	img->MatrizDesenho[escolha.y][escolha.x].B = primitiva.B;

	FillUp(img, primitiva, escolha, inicial);
}

void FillUp (Imagem *img, Cor primitiva, Ponto origem, Cor inicial) {
	unsigned short int resto, i;

	if (origem.y > 0 && FillCor(img, inicial, origem)) {
		resto = origem.y;

			for (i = 0; i < resto; i++) {	

			img->MatrizDesenho[origem.y-resto][origem.x].R = primitiva.R;
			img->MatrizDesenho[origem.y-resto][origem.x].G = primitiva.G;
			img->MatrizDesenho[origem.y-resto][origem.x].B = primitiva.B;
			
			FillRight(img, primitiva, origem, inicial);
			FillLeft(img, primitiva, origem, inicial);
			FillDown(img, primitiva, origem, inicial);
		}
	}
}

void FillRight (Imagem *img, Cor primitiva, Ponto origem, Cor inicial) {
	unsigned short int resto, i;

	if (origem.x < 639 && FillCor(img, inicial, origem)) {
		resto = 640 - origem.x;

		for (i = 0; i < resto; i++) {

			img->MatrizDesenho[origem.y][origem.x+resto].R = primitiva.R;
			img->MatrizDesenho[origem.y][origem.x+resto].G = primitiva.G;
			img->MatrizDesenho[origem.y][origem.x+resto].B = primitiva.B;
			
			FillUp(img, primitiva, origem, inicial);
			FillLeft(img, primitiva, origem, inicial);
			FillDown(img, primitiva, origem, inicial);
		}

	}
}

void FillLeft (Imagem *img, Cor primitiva, Ponto origem, Cor inicial) {
	unsigned short int resto, i;

	if (origem.x > 0 && FillCor(img, inicial, origem)) {
		resto = origem.x;

		for (i = 0; i < resto; i++) {

			img->MatrizDesenho[origem.y][origem.x-resto].R = primitiva.R;
			img->MatrizDesenho[origem.y][origem.x-resto].G = primitiva.G;
			img->MatrizDesenho[origem.y][origem.x-resto].B = primitiva.B;

			FillUp(img, primitiva, origem, inicial);
			FillRight(img, primitiva, origem, inicial);
			FillDown(img, primitiva, origem, inicial);

		}	

	}
}

void FillDown (Imagem *img, Cor primitiva, Ponto origem, Cor inicial) {
	unsigned short int resto, i;

	if (origem.y < 479 && FillCor(img, inicial, origem)) {
		resto = 480 - origem.y;

		for (i = 0; i < resto; i++) {

			img->MatrizDesenho[origem.y+resto][origem.x].R = primitiva.R;
			img->MatrizDesenho[origem.y+resto][origem.x].G = primitiva.G;
			img->MatrizDesenho[origem.y+resto][origem.x].B = primitiva.B;
			
			FillRight(img, primitiva, origem, inicial);
			FillLeft(img, primitiva, origem, inicial);
			FillUp(img, primitiva, origem, inicial);
		}

	}
}

bool FillCor (Imagem *img, Cor inicial, Ponto origem) {

	if (img->MatrizDesenho[origem.y][origem.x].R == inicial.R) {
		if (img->MatrizDesenho[origem.y][origem.x].G == inicial.G) {
			if (img->MatrizDesenho[origem.y][origem.x].B == inicial.B) {
				return false;
			}
			return true;
		}
	}
	return true;
}
