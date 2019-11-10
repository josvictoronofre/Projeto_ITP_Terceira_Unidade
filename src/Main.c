#include "Desenho.h"

int main (void) {
Cor primitiva = {255,255,255}; //O default da cor branco
Imagem Resposta;
unsigned short i, j;
scanf("%hu %hu %hu", &primitiva.R, &primitiva.G, &primitiva.B); //Scanea os valores RGB pra cor primitiva

criaDesenho(Resposta.MatrizDesenho, primitiva, Resposta.tipoImagem, &Resposta.Nlinhas, &Resposta.Ncolunas, &Resposta.Maximopixels);

return 0;
}