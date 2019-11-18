#ifndef Struct_h
#define Struct_h

//Os componentes Red, Green e Blue de cada pixel
typedef struct cor {
	int R, G, B; 
} Cor;

//A struct que vai representar a imagem em si
typedef struct imagem {
	char tipoImagem[3];
	int Nlinhas, Ncolunas, Maximopixels;
	Cor **MatrizDesenho;
} Imagem;

typedef struct ponto {
	int x, y;
} Ponto;

#endif