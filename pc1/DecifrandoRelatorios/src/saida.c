#include "../include/decifrar_relatorio.h"
#include "../include/saida.h"
#include "../include/erros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escreverArquivoSaida(int resultado, Transacao *transacao, char *letras) {
    FILE *arquivoSaida = fopen("./text/resultados.txt", "w");
    if (!arquivoSaida) {
        reportError("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    if (resultado == -1) {
        fprintf(arquivoSaida, "-1\n");
    } else {
        fprintf(arquivoSaida, "%d\n", resultado);
        imprimirResultado(arquivoSaida, transacao, letras);
    }

    fclose(arquivoSaida);
}

void imprimirResultado(FILE *saida, Transacao *transacao, char *letras) {
    for (size_t i = 0; i < strlen(letras); i++) {
        char letra = letras[i];
        fprintf(saida, "%c:%d\n", letra, transacao->correspondencia[letra - 'A']);
    }
}