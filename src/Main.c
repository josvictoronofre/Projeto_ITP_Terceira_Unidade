#include "Desenho.h"

int main (void) {
Cor primitiva = {255,255,255}; //O default da cor branco

scanf("%hu %hu %hu", &primitiva.R, &primitiva.G, &primitiva.B); //Scanea os valores RGB pra cor primitiva

criaDesenho(primitiva);

return 0;
}