#include "Desenho.h"


//cria o desenho usando como base a cor primitiva escolhida pelo usuario
void criaDesenho (Imagem *img, Cor primitiva) {
	
	FILE *desenho = fopen("Imagem", "w"); //Abre o arquivo no formato escrita

	unsigned short i, j; //Indices pra matriz

	
	//atribui os valores corretos
	img->Nlinhas = 640;
	img->Ncolunas = 480;
	img->Maximopixels = 255;

	alocaMemoria(img);

	img->tipoImagem[0] = 'P';
	img->tipoImagem[1] = '3';
	img->tipoImagem[2] = '\0';
	

	//Imprime os valores no arquivo
	fprintf(desenho, "%s\n", img->tipoImagem);

	fprintf(desenho, "%d %d\n", img->Nlinhas, img->Ncolunas);

	fprintf(desenho, "%d\n", img->Maximopixels);

	//Monta a matriz a partir da cor escolhida pelo usuario
	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			img->MatrizDesenho[i][j].R = primitiva.R;
			img->MatrizDesenho[i][j].G = primitiva.G;
			img->MatrizDesenho[i][j].B = primitiva.B;
		}
	}

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			//Imprime a informacao da matriz no arquivo
			fprintf(desenho, "%d %d %d\n", img->MatrizDesenho[i][j].R, img->MatrizDesenho[i][j].G, img->MatrizDesenho[i][j].B);
		}
	}

	fclose(desenho); //Salva as alteracoes

	liberaMemoria(img); //Libera a memoria

}

//Le as informacoes de pixel do arquivo e passa pra matriz
void leDesenho (Imagem *img) {
	unsigned short i, j; //Indices pra atribuicao da matriz

	FILE *desenho = fopen("Imagem", "r");

	if (desenho == NULL) {
		printf("Nao foi possivel ler o arquivo!\n");
	}

	//Salva o tipo de imagem PPM, as dimensoes e o valor maximo para cada componente do pixel
	fgets(img->tipoImagem, 3, desenho); 

	fscanf(desenho, "%d %d\n", &img->Nlinhas, &img->Ncolunas);

	fscanf(desenho, "%d\n", &img->Maximopixels);

	alocaMemoria(img);

	//Pega as informacoes de cada pixel do arquivo e passa pra matriz
	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			fscanf(desenho, "%d", &img->MatrizDesenho[i][j].R);
			fscanf(desenho, "%d", &img->MatrizDesenho[i][j].G);
			fscanf(desenho, "%d", &img->MatrizDesenho[i][j].B);
		}
	}

	fclose(desenho); //Fecha o arquivo
}


//Aloca dinamicamente a matriz na memoria
void alocaMemoria (Imagem *img) {
	unsigned short i; //Indice pra alocacao da matriz
	
	//Alocando dinamicamente a matriz do desenho
	img->MatrizDesenho = (Cor **) malloc(img->Nlinhas*sizeof(Cor *));
	for (i = 0; i < img->Nlinhas; i++) {
		img->MatrizDesenho[i] = (Cor *) malloc(img->Ncolunas*sizeof(Cor));
	}
}

//Libera o espaco de memoria da matriz
void liberaMemoria (Imagem *img) {
	unsigned short i; //Indice pra percorrer as linhas

	//Libera as colunas
	for (i = 0; i < img->Nlinhas; i++) {
		free(img->MatrizDesenho[i]); 
	}
	//Libera as linhas
	free(img->MatrizDesenho);
}