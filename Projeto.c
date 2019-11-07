#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct cor {
	unsigned int R = 0;
	unsigned int B = 0;
	unsigned int G = 0;
	//O defalut eh a cor ser branco
} Cor;

void criaImagem (Cor ** matriz) {
	FILE *desenho = fopen("Imagem.ppm", "w");
	fputs("P3\n640 480\n255\n", desenho);
	unsigned short i, j;

	for (i = 0; i < 480; i++) {
		for (j = 0; j < 640; j++) {
			fprintf(desenho, "%hu %hu %hu", *matriz[i][j]->R, *matriz[i][j]->B, *matriz[i][j]->G);
		}
	}

}

int main (void) {
	Cor ** matriz;
	unsigned short i;
	Cor primitiva;
	
	//Alocando uma matriz pra imagem dinamicamente
	matriz = (Cor **) calloc(480, sizeof(Cor *));
	for (i = 0; i < 480; i++) {
		matriz[i] = (Cor *) calloc(640, sizeof(Cor));
	}

	criaImagem(matriz);
}