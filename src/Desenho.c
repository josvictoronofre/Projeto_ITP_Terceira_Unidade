#include "Desenho.h"


//cria o desenho usando como base a cor primitiva escolhida pelo usuario
void criaDesenho (Imagem *img, Cor primitiva) {
	
	FILE *desenho = fopen("Imagem", "w"); //Abre o arquivo no formato escrita

	unsigned short i, j;

	img->Nlinhas = 640;
	img->Ncolunas = 480;
	img->Maximopixels = 255;

	alocaMemoria(img);

	img->tipoImagem[0] = 'P';
	img->tipoImagem[1] = '3';
	img->tipoImagem[2] = '\0';
	

	fprintf(desenho, "%s\n", img->tipoImagem);

	fprintf(desenho, "%d %d\n", img->Nlinhas, img->Ncolunas);

	fprintf(desenho, "%d\n", img->Maximopixels);

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			img->MatrizDesenho[i][j].R = primitiva.R;
			img->MatrizDesenho[i][j].G = primitiva.G;
			img->MatrizDesenho[i][j].B = primitiva.B;
		}
	}

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			fprintf(desenho, "%d %d %d\n", img->MatrizDesenho[i][j].R, img->MatrizDesenho[i][j].G, img->MatrizDesenho[i][j].B);
		}
	}

	fclose(desenho);

	liberaMemoria(img);

}

//Le as informacoes de pixel do arquivo e passa pra matriz
void leDesenho (Imagem *img) {
	unsigned short i, j; //Indices pra atribuicao da matriz

	FILE *desenho = fopen("Imagem", "r");

	if (desenho == NULL) {
		printf("Nao foi possivel ler o arquivo!\n");
	}

	fgets(img->tipoImagem, 3, desenho); //Salva o tipo de imagem PPM, as dimensoes e o valor maximo para cada componente do pixel

	fscanf(desenho, "%d %d\n", &img->Nlinhas, &img->Ncolunas);

	fscanf(desenho, "%d\n", &img->Maximopixels);

	alocaMemoria(img);

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			fscanf(desenho, "%d", &img->MatrizDesenho[i][j].R);
			fscanf(desenho, "%d", &img->MatrizDesenho[i][j].G);
			fscanf(desenho, "%d", &img->MatrizDesenho[i][j].B);
		}
	}

	fclose(desenho);
}


//Funcao que aloca dinamicamente a matriz na memoria
void alocaMemoria (Imagem *img) {
	unsigned short i; //Indice pra alocacao da matriz
	//Alocando dinamicamente a matriz do desenho
	img->MatrizDesenho = (Cor **) malloc(img->Nlinhas*sizeof(Cor *));
	for (i = 0; i < img->Nlinhas; i++) {
		img->MatrizDesenho[i] = (Cor *) malloc(img->Ncolunas*sizeof(Cor));
	}
}


void liberaMemoria (Imagem *img) {
	unsigned short i;

	for (i = 0; i < img->Nlinhas; i++) {
		free(img->MatrizDesenho[i]);
	}
	free(img->MatrizDesenho);
}