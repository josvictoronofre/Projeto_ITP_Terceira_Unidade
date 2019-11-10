#include "Desenho.h"

int main (void) {
Cor primitiva = {255,255,255}; //O default da cor branco
Imagem Resposta;
unsigned short i, j;
scanf("%d %d %d", &primitiva.R, &primitiva.G, &primitiva.B); //Scanea os valores RGB pra cor primitiva

criaDesenho(&Resposta, primitiva);

leDesenho(&Resposta);

return 0;
}