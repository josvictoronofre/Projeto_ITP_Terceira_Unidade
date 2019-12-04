# makefile do Projeto de ITP Terceira Unidade 2019.2

# pastas do Projeto
SRCDIR = ./src
INCDIR = ./include
BINDIR = ./bin

# Compilador e FLags
CC = gcc
CFLAGS = -Wall 

# Nome do projeto
PROJ = desenho

all: desenho

desenho: bin_folder
		$(CC) $(SRCDIR)/*.c $(CFLAGS) -I $(INCDIR) -o $(BINDIR)/$(PROJ)
		@ln -sfv $(BINDIR)/$(PROJ) $(PROJ)
		@echo "Compilado com sucesso, para executar digite ./$(PROJ)"


bin_folder:
		@mkdir -p $(BINDIR)


clean:
		@rm -f $(PROJ)
		@rm -rf $(BINDIR)
		@echo "executavel deletado com sucesso!"
