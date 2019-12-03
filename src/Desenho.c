#include "Desenho.h"


//cria o desenho usando como base a cor primitiva escolhida pelo usuario
void criaDesenho (Imagem *img, Cor primitiva) {

	int i, j; //Indices pra matriz

	
	//atribui os valores corretos
	printf("Especifique a largura e a altura, respectivamente, da imagem:\n");

	scanf("%d %d", &img->Ncolunas, &img->Nlinhas);

	img->tipoImagem[0] = 'P';
	img->tipoImagem[1] = '3';
	img->tipoImagem[2] = '\0';

	img->Maximopixels = 255;

	alocaMemoria(img);

	
	//Monta a matriz a partir da cor escolhida pelo usuario
	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			img->MatrizDesenho[i][j].R = primitiva.R;
			img->MatrizDesenho[i][j].G = primitiva.G;
			img->MatrizDesenho[i][j].B = primitiva.B;
		}
	}

	salvaDesenho(img);

	liberaMemoria(img); //Libera a memoria

	printf("Imagem gerada com sucesso!\n");

}

//Le as informacoes de pixel do arquivo e passa pra matriz
void leDesenho (Imagem *img) {
	int i, j; //Indices pra atribuicao da matriz

	FILE *desenho = fopen("Imagem.ppm", "r");

	//Salva o tipo de imagem PPM, as dimensoes e o valor maximo para cada componente do pixel
	fgets(img->tipoImagem, 3, desenho); 

	fscanf(desenho, "%d %d\n", &img->Ncolunas, &img->Nlinhas);

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

	printf("Imagem carregada com sucesso!\n");

	fclose(desenho); //Fecha o arquivo
}


//Aloca dinamicamente a matriz na memoria
void alocaMemoria (Imagem *img) {
	int i; //Indice pra alocacao da matriz
	
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

//Salva as alteracoes no arquivo
void salvaDesenho (Imagem *img) {
	int i, j;

	if (img->MatrizDesenho == NULL) {
		printf("Nao existe uma informacao valida para ser salva no arquivo!\n");
		return;
	}

	FILE *desenho = fopen("Imagem.ppm", "w");

	fprintf(desenho, "%s\n", img->tipoImagem);

	fprintf(desenho, "%d %d\n", img->Ncolunas, img->Nlinhas);

	fprintf(desenho, "%d\n", img->Maximopixels);

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			fprintf(desenho, "%d %d %d\n", img->MatrizDesenho[i][j].R, img->MatrizDesenho[i][j].G, img->MatrizDesenho[i][j].B);
		}
	}
	fclose(desenho);
}


//Escolhe a cor primitiva
void escolheCor (Cor *primitiva) {
		int pivoR, pivoG, pivoB;

		printf("Especifique o valor dos componentes R, G e B respectivamente:\n");

		scanf("%d %d %d", &pivoR, &pivoG, &pivoB);

		//Se as cores escolhidas nao forem aceitaveis ele nao salva as alteracoes
		if (pivoR < 0 || pivoR > 255 || pivoG < 0 || pivoG > 255 || pivoB < 0 || pivoB > 255)
			printf("Valores de componentes invalidos!\n");
		else {
			primitiva->R = pivoR;
			primitiva->G = pivoG;
			primitiva->B = pivoB;
		}

}

//Reinicia a imagem com a cor escolhida
void limpaDesenho (Imagem *img, Cor primitiva) {
	int i, j;

	if (img->MatrizDesenho == NULL) {
		printf("Nao existe uma informacao valida para ser salva no arquivo!\n");
		return;
	}

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			img->MatrizDesenho[i][j].R = primitiva.R;
			img->MatrizDesenho[i][j].G = primitiva.G;
			img->MatrizDesenho[i][j].B = primitiva.B;
		}
	}

	printf("Imagem resetada com sucesso!\n");
}

void passaDesenho(Imagem *img, Imagem *pivo) {
	unsigned short int i, j;

	for (i = 0; i < pivo->Nlinhas; i++) {
		for (j = 0; j < pivo->Ncolunas; j++) {
			img->MatrizDesenho[i][j].R = pivo->MatrizDesenho[i][j].R;
			img->MatrizDesenho[i][j].G = pivo->MatrizDesenho[i][j].G;
			img->MatrizDesenho[i][j].B = pivo->MatrizDesenho[i][j].B;
		}
		
	}
}