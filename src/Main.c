#include "Desenho.h"

int main (void) {
Cor primitiva; //O default da cor branco
Imagem Resposta;
unsigned short i, j;

scanf("%d %d %d", &primitiva.R, &primitiva.G, &primitiva.B); //Scanea os valores RGB pra cor primitiva

if (primitiva.R > 255 || primitiva.R < 0 || primitiva.G > 255|| primitiva.G <0 || primitiva.B > 255 || primitiva.B < 0) {
	printf("Valor invalido!");
	return 1;
}

criaDesenho(&Resposta, primitiva);

leDesenho(&Resposta);

printf("%s\n", Resposta.tipoImagem);

printf("%d %d\n", Resposta.Nlinhas, Resposta.Ncolunas);

printf("%d\n", Resposta.Maximopixels);

for (i = 0; i < Resposta.Nlinhas; i++) {
	for (j = 0; j < Resposta.Ncolunas; j++) {
		printf("%d %d %d\n", Resposta.MatrizDesenho[i][j].R, Resposta.MatrizDesenho[i][j].G, Resposta.MatrizDesenho[i][j].B);
	}
}

return 0;
}
