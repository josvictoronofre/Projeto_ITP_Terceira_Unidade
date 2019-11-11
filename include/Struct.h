#ifndef Struct_h
#define Struct_h

typedef struct cor {
	int R, G, B;
} Cor;

typedef struct imagem {
	char tipoImagem[3];
	int Nlinhas, Ncolunas, Maximopixels;
	Cor **MatrizDesenho;
} Imagem;

#endif