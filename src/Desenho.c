#include "Desenho.h"
#include <stdlib.h>
#include <stdio.h>


//cria o desenho usando como base a cor primitiva escolhida pelo usuario
void criaDesenho (Cor primitiva) {
	FILE *desenho = fopen("Imagem.ppm", "w"); //Abre o arquivo no formato escrita
	
	fprintf(desenho, "P3\n640 480\n255\n"); //Printa no arquivo o formato, tipo e valor maximo pra cada pixel

	for (i = 0; i < 307200;i++) {
		fpritnf(desenho, "%hu %hu %hu\n", primitiva.R, primitiva.G, primitiva.B); //Printa as informacoes dos pixels baseado na cor primitiva
	}
	fclose(desenho); //Salva as alteracoes

}

//Le as informacoes de pixel do arquivo e passa pra matriz
Cor leDesenho (char *tipoImagem, unsigned short *Mlinhas, unsigned short *Mcolunas, unsigned short MaximoPixels) {
	unsigned short i, j; //Indices pra atribuicao da matriz

	FILE *desenho = fopen("Imagem.ppm", "r"); //Abre o arquivo no formato leitura

	fscanf(desenho, "%s\n%hu%hu\n%hu\n", tipoImagem, Mlinhas, Mcolunas, MaximoPixels); //Salva o tipo de imagem PPM, as dimensoes e o valor maximo para cada componente do pixel

	Cor **MatrizDesenho;

	**MatrizDesenho =(Cor **) alocaMatriz(MatrizDesenho, *Mlinhas, *Mcolunas); //Aloca a matriz usando a funcao

	for (i = 0; i < *Mlinhas; i++) {
		for (j = 0; j < *Mcolunas; j++) {
			fscanf(desenho, "%hu %hu %hu\n", MatrizDesenho[i][j].R, MatrizDesenho[i][j].G, MatrizDesenho[i][j].B); //Atribui valores pra cada ponto da matriz
		}
	}

	fclose(desenho);

	return MatrizDesenho;

}


//Funcao que aloca dinamicamente a matriz na memoria
Cor alocaMatriz (Cor **MatrizDesenho, const unsigned short Nlinhas, const unsigned short Ncolunas) {
	unsigned short i; //Indice pra alocacao da matriz
	//Alocando dinamicamente a matriz do desenho
	MatrizDesenho = (Cor **) calloc(Nlinhas, sizeof(Cor*));
	for (i = 0; i < Ncolunas; i++) {
		MatrizDesenho[i] = (Cor *) calloc(Ncolunas, sizeof(Cor));
	}
	return **MatrizDesenho;
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