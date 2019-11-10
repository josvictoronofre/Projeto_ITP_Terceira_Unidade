#include "Desenho.h"


//cria o desenho usando como base a cor primitiva escolhida pelo usuario
void criaDesenho (Imagem *img, Cor primitiva) {
	
	unsigned short i, j;

	img->tipoImagem = (char *) malloc(3*sizeof(char));
	img->tipoImagem = "P3";
	img->Nlinhas = 640;
	img->Ncolunas = 480;
	img->Maximopixels = 255;

	FILE *desenho = fopen("Imagem.ppm", "w"); //Abre o arquivo no formato escrita

	fprintf(desenho, "%s\n", img->tipoImagem);

	fprintf(desenho, "%d %d\n", img->Nlinhas, img->Ncolunas);

	fprintf(desenho, "%d\n", img->Maximopixels);

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			fprintf(desenho, "%d %d %d\n", primitiva.R, primitiva.G, primitiva.B);
		}
	}



}

//Le as informacoes de pixel do arquivo e passa pra matriz
void leDesenho (Imagem *img) {
	unsigned short i, j; //Indices pra atribuicao da matriz

	FILE *desenho = fopen("Imagem.ppm", "r");

	if (desenho == NULL) {
		printf("Nao ta lendo o arquivo\n");
	}

	fgets(img->tipoImagem, 3, desenho); //Salva o tipo de imagem PPM, as dimensoes e o valor maximo para cada componente do pixel

	fscanf(desenho, "%d %d\n", &img->Nlinhas, &img->Ncolunas);

	fscanf(desenho, "%d\n", &img->Maximopixels);

	alocaMatriz(img);

	for (i = 0; i < img->Nlinhas; i++) {
		for (j = 0; j < img->Ncolunas; j++) {
			fscanf(desenho, "%d %d %d\n", &img->MatrizDesenho[i][j].R, &img->MatrizDesenho[i][j].G, &img->MatrizDesenho[i][j].B); //Atribui valores pra cada ponto da matriz
		}
	}

	fclose(desenho);

}


//Funcao que aloca dinamicamente a matriz na memoria
void alocaMatriz (Imagem *img) {
	unsigned short i; //Indice pra alocacao da matriz
	//Alocando dinamicamente a matriz do desenho
	img->MatrizDesenho = (Cor **) malloc(img->Nlinhas*sizeof(Cor *));
	for (i = 0; i < img->Nlinhas; i++) {
		img->MatrizDesenho[i] = (Cor *) malloc(img->Ncolunas*sizeof(Cor));
	}
}

//Salva as alteracoes da matriz no arquivo e libera a matriz da memoria
void salvaDesenho (Cor **MatrizDesenho, char tipoImagem[], unsigned short Mlinhas, unsigned short Mcolunas, unsigned short MaximoPixels) {
	unsigned short i, j; //Indices pra controle da matriz

	FILE *desenho = fopen("Imagem.ppm", "w"); //Abre o arquivo no formato escrita

	fprintf(desenho, "%s\n%hu %hu\n%hu\n", tipoImagem, Mcolunas, Mlinhas, MaximoPixels); //Printa o tipo de arquivo PPM, as dimensoes e o valor maximo pra cada componente do pixel

	for (i = 0; i < Mlinhas; i++) {
		for (j = 0; j < Mcolunas; j++) {
			fprintf(desenho, "%hu %hu %hu\n", MatrizDesenho[i][j].R, MatrizDesenho[i][j].G, MatrizDesenho[i][j].B); //Printa no arquivo as especificacoes de cada pixel
		}
	}
	free(MatrizDesenho); //Desaloca a matriz da memoria pra liberar espaco
	fclose(desenho); //Salva as alteracoes no arquivo
}