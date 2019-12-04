Introdução às Tecnicas de Programação - 2019.2
Professor: Carlos Eduardo
Aluno: José Victor Onofre

Funcionalidades Implementadas:
 - image
 - color
 - clear
 - rect
 - polygon
 - save
 - open

Funcionalidades não-implementadas:
 - fill
 - circle

O que poderia ter sido feito diferente:
 - A utilização de strings para nomear a imagem criada e escolher a imagem que se deseja utilizar, afim de possibilitar a o uso de múltiplos arquivos
 - Uma melhor alocação e liberação de memória, otimizando o funcionamento do programa

Para compilar:
 - Não foram utilizadas bibliotecas externas

 - Estando na pasta raiz do projeto, basta digitar no terminal:
$ make all

 - O terminal deve exibir:
gcc ./src/*.c -Wall  -I ./include -o ./bin/desenho
'desenho' -> './bin/desenho'
Compilado com sucesso, para executar digite ./desenho

Após terminar a execução, basta digitar:
$ make clean

- O terminal deve exibir:
executavel deletado com sucesso!
