#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct cor {
	unsigned int R, G, B;
} Cor;

int main (void) {
	Cor momentanea;
	Cor *pon_moment = &momentanea;
}

void escolheCor (Cor *pon_moment) {
	scanf("%d", &pon_moment->R);
}