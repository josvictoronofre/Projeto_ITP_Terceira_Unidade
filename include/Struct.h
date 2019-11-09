#ifndef Struct_h
#define Struct_h

typedef struct cor {
	unsigned short R, G, B;
} Cor;

typedef struct imagem {
	char tipoImagem[3];
	unsigned short Nlinhas, Ncolunas, Maximopixels;
	Cor **MatrizDesenho;
} Imagem;

#endif