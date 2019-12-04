# Projeto ITP Terceira Unidade - Desenho Gráfico

Projeto de ITP da Terceira Unidade do Semestre 2019.2 do curso de Tecnologia da Informacão

## Desenvolvedor

* [José Victor Onofre](https://github.com/josvictoronofre)

### Primitivas Implementadas
Primitiva | Descrição
----------|----------
image | Cria uma nova “imagem”, com a largura e altura especificadas na primitiva
color | muda a cor atual para uma cor especificada
clear | limpa a imagem, setando todos os pixels para a cor especificada
rect | Desenha um retângulo nas posições x, y, e com tamanho especificados
polygon | Desenha um poligono delimitado por uma lista de pontos
save | Salva a imagem atual em um arquivo usando o formato ppm
open | Carrega uma imagem ppm no programa para futuras operações de desenho

### Compilação e execução
#### Para baixar o código na sua maquina:
```bash
git clone https://github.com/josvictoronofre/Projeto_ITP_Terceira_Unidade.git
```
#### Após baixar o repositorio, vá até a pasta raiz e:
```bash
# Digite o comando no terminal:
$ make all

# O terminal deve exibir:
gcc ./src/*.c -Wall  -I ./include -o ./bin/desenho
'desenho' -> './bin/desenho'
Compilado com sucesso, para executar digite ./desenho

# Quando terminar a execução digite o seguinte comando para limpar os arquivos binários:
$ make clean

# O terminal deve exibir:
executavel deletado com sucesso!
```
#### Para executar:
```bash
$ ./desenho
```
