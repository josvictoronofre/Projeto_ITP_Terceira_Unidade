#include "Utilidade.h"

void printaOpcoes () {
	printf("Lista de comandos:\n");

	printf("image - Cria o arquivo Imagem com largura e altura especificados\n");

	printf("color - Escolhe a cor primitiva para ser utilizada em outras funções\n");

	printf("clear - Reseta toda a imagem para a cor primitiva\n");

	printf("open - Lê o arquivo Imagem para o programa\n");

	printf("save - Salva as alteracoes do programa no arquivo Imagem\n");

	printf("exit - Para a execução do programa\n");

	printf("rect - Desenha o retângulo com ponto inicial, altura e largura especificados\n");

	printf("polygon - Desenha o polígono com a quantidade de pontos e os pontos especificados\n");
}

bool checaCondicoes (Imagem *img) {
	FILE *desenho = fopen("Imagem.ppm", "r");

	if (desenho == NULL) {
		printf("Não foi possível ler o arquivo!\n");
		return false;
	} else if (img->MatrizDesenho == NULL) {
		printf("Não existe nenhuma imagem carregada no programa\n");
		return false;
	} else {
		return true;
	}
}
