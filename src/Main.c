#include "Poligonos.h"

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

desenhaReta(&Resposta, primitiva);

return 0;
}
