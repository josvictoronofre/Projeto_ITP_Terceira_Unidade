#include "Desenho.h"

int main (void) {
Cor primitiva = {255,255,255}; //O default da cor branco
Imagem Resposta;
unsigned short i, j;
scanf("%hu %hu %hu", &primitiva.R, &primitiva.G, &primitiva.B); //Scanea os valores RGB pra cor primitiva

criaDesenho(primitiva);

leDesenho(Resposta.MatrizDesenho, Resposta.tipoImagem, &Resposta.Nlinhas, &Resposta.Ncolunas, &Resposta.Maximopixels);

for (i = 0; i < Resposta.Nlinhas; i++) {
	for (j = 0; j < Resposta.Ncolunas; j++) {
		printf("%hu %hu %hu\n", Resposta.MatrizDesenho[i][j].R, Resposta.MatrizDesenho[i][j].G, Resposta.MatrizDesenho[i][j].B);
	}
}

return 0;
}