#ifndef DECIFRAR_RELATORIO_H
#define DECIFRAR_RELATORIO_H

#include <stdio.h>

typedef struct {
    char A[9];
    char B[9];
    char C[9];
    int correspondencia[26];
} Transacao;

void determinarLetras(Transacao *transacao, char *letras);
int decifrarRelatorio(Transacao *transacao, char *letras, size_t letraAtualIdx, FILE *arquivoSaida, char *A, char *B, char *C);
int decifrarTransacao(Transacao *transacao, char *letras, FILE *arquivoSaida);

#endif