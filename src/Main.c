#include "Poligonos.h"

int main (void) {
	char controle[50];
	unsigned short ativador = 0;
	Imagem desenho;
	Cor primitiva = {255,255,255};
	
	while (ativador == 0) {

		printf("O que deseja fazer?\n");

		scanf("%s", controle);

		if (strcmp(controle, "image") == 0) {
			criaDesenho(&desenho, primitiva);
		} 
		else if (strcmp(controle, "color") == 0) {
			escolheCor(&primitiva);
		} 
		else if (strcmp(controle, "clear") == 0) {
			limpaDesenho(&desenho, primitiva);
		}
		else if (strcmp(controle, "open") == 0) {
			leDesenho(&desenho);
		}
		else if (strcmp(controle, "save") == 0) {
			salvaDesenho(&desenho);
		}
		else if (strcmp(controle, "exit") == 0) {
			ativador++;
		}
		else if (strcmp(controle, "rect") == 0) {
			desenhaRetangulo(&desenho, primitiva);
		}
	}

return 0;
}
