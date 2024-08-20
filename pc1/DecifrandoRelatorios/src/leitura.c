#include "../include/leitura.h"
#include "../include/erros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerArquivoEntrada(const char *caminho, Transacao *transacao) {
    FILE *arquivoEntrada = fopen(caminho, "r");
    if (!arquivoEntrada) {
        reportError("Erro ao abrir o arquivo de entrada.\n");
        return 0;  
    }

    fscanf(arquivoEntrada, "%s", transacao->A);
    fscanf(arquivoEntrada, "%s", transacao->B);
    fscanf(arquivoEntrada, "%s", transacao->C);

    fclose(arquivoEntrada);
    return 1; 
}