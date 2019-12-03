#include "Utilidade.h"

int main (void) {
	char controle[30];
	unsigned short ativador = 0;
	Imagem desenho;
	Cor primitiva = {255,255,255};
	
	system("clear");

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
			if (checaCondicoes(&desenho)) {
				limpaDesenho(&desenho, primitiva);
			}
			
		}
		else if (strcmp(controle, "open") == 0) {
			if (checaCondicoes(&desenho)) {
				leDesenho(&desenho);
			}
		}
		else if (strcmp(controle, "save") == 0) {
			salvaDesenho(&desenho);
		}
		else if (strcmp(controle, "exit") == 0) {
			ativador++;
		}
		else if (strcmp(controle, "rect") == 0) {
			if (checaCondicoes(&desenho)) {
				poligonoRetangulo(&desenho, primitiva);
			}
		}
		else if (strcmp(controle, "polygon") == 0) {
			if (checaCondicoes(&desenho)) {
				desenhaPoligono(&desenho, primitiva);
			}
		}
		else if (strcmp(controle, "fill") == 0) {
			funcaoPintar(&desenho, primitiva);
		}
		else if (controle[0] == '?') {
			printaOpcoes();
		}
		else {
			printf("Comando nao existente, para ver a lista de comandos aperte '?'\n");
		}
	}

return 0;
}
