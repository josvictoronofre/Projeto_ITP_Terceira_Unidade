#include "Poligonos.h"

int main (void) {
Cor primitiva; //O default da cor branco
Imagem Resposta;

escolheCor(&primitiva);

criaDesenho(&Resposta, primitiva);

escolheCor(&primitiva);

desenhaReta(&Resposta, primitiva);

return 0;
}
