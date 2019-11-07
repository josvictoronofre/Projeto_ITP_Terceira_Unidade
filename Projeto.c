#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct essaporranaoehumalista {
	unsigned int R;
	unsigned int G;
	unsigned int B;
	//O defalut eh a cor ser branco
} Cor;

void criaImagem (Cor ** matriz) {
	FILE *desenho = fopen("Imagem.ppm", "w");
	fputs("P3\n640 480\n255\n", desenho);
	unsigned short i, j;

	for (i = 0; i < 480; i++) {
		for (j = 0; j < 640; j++) {
			fprintf(desenho, "%u %u %u", matriz[i][j].R, matriz[i][j].G, matriz[i][j].B);
		}
	}
	fclose(desenho);

}

void escolheCor (Cor ** matriz) {
	Cor pivo;
	unsigned short i, j;
	scanf("%u %u %u", &pivo.R, &pivo.G, &pivo.B);

	if (pivo.R > 0 && pivo.R < 256 && pivo.G > 0 && pivo.G < 256 && pivo.B > 0 && pivo.B < 256) {
		for (i = 0; i < 480; i ++) {
			for (j = 0; j < 640; j ++) {
				matriz[i][j].R = pivo.R;
				matriz[i][j].G = pivo.G;
				matriz[i][j].B = pivo.B;
			}
		}
	} else {
		printf("Cor invalida\n");
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
	escolheCor(matriz);
	criaImagem(matriz);
}