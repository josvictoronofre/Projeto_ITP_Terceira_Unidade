#include "Desenho.h"

int main (void) {
Cor primitiva = {255,255,255}; //O default da cor branco
Imagem Resposta;
unsigned i, j;

scanf("%d %d %d", &primitiva.R, &primitiva.G, &primitiva.B); //Scanea os valores RGB pra cor primitiva

criaDesenho(&Resposta, primitiva);

leDesenho(&Resposta);

printf("%s\n", Resposta.tipoImagem);

printf("%d %d\n", Resposta.Nlinhas, Resposta.Ncolunas);

printf("%d\n", Resposta.Maximopixels);



return 0;
}