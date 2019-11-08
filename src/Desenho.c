#include "Desenho.h"

void criaDesenho (Cor primitiva) {
	FILE *desenho = fopen("Imagem.ppm", "w"); //Abre o arquivo no formato escrita
	
	fprintf(desenho, "P3\n640 480\n255\n"); //Printa no arquivo o formato, tipo e valor maximo pra cada pixel

	fpritnf(desenho, "%hu %hu %hu\n", primitiva.R, primitiva.G, primitiva.B); //Printa as informacoes dos pixels baseado na cor primitiva

	fclose(desenho); //Salva as alteracoes

}

Cor leDesenho (char *tipoImagem, unsigned short *Mlinhas, unsigned short *Mcolunas) {
	unsigned short i; //Indice pra alocacao da matriz

	FILE *desenho = fopen("Imagem.ppm", "r"); //Abre o arquivo no formato leitura

	fscanf(desenho, "%s\n%hu%hu\n", tipoImagem, Mlinhas, Mcolunas); //Salva o tipo de imagem PPM e as dimensoes

	Cor **MatrizDesenho;

	//Alocando dinamicamente a matriz do desenho
	MatrizDesenho = (Cor **) calloc(*Mlinhas, sizeof(Cor*));
	for (i = 0; i < *Mcolunas; i++) {
		MatrizDesenho[i] = (Cor *) calloc(*Mcolunas, sizeof(Cor));
	}

}