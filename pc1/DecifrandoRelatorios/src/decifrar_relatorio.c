#include "../include/decifrar_relatorio.h"
#include "../include/saida.h"
#include "../include/erros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determinarLetras(Transacao *transacao, char *letras) {
    size_t i, j;
    int letraPresente[26] = {0};

    for (i = 0; i < strlen(transacao->A); i++) {
        letraPresente[transacao->A[i] - 'A'] = 1;
    }
    for (i = 0; i < strlen(transacao->B); i++) {
        letraPresente[transacao->B[i] - 'A'] = 1;
    }
    for (i = 0; i < strlen(transacao->C); i++) {
        letraPresente[transacao->C[i] - 'A'] = 1;
    }

    j = 0;
    for (i = 0; i < 26; i++) {
        if (letraPresente[i]) {
            letras[j++] = 'A' + i;
        }
    }
    letras[j] = '\0';
}

int decifrarRelatorio(Transacao *transacao, char *letras, size_t letraAtualIdx, FILE *arquivoSaida, char *A, char *B, char *C) {
    static int maiorResultado = -1;  // Variável estática para rastrear o maior resultado

    if (letras[letraAtualIdx] == '\0') {
        int valorA = 0, valorB = 0, valorC = 0;

        for (size_t i = 0; i < strlen(transacao->A); i++) {
            valorA = valorA * 10 + transacao->correspondencia[transacao->A[i] - 'A'];
        }

        for (size_t i = 0; i < strlen(transacao->B); i++) {
            valorB = valorB * 10 + transacao->correspondencia[transacao->B[i] - 'A'];
        }

        for (size_t i = 0; i < strlen(transacao->C); i++) {
            valorC = valorC * 10 + transacao->correspondencia[transacao->C[i] - 'A'];
        }

        if (valorA + valorB == valorC && valorC > maiorResultado) {
            maiorResultado = valorC;  
            fseek(arquivoSaida, 0, SEEK_SET);
            fprintf(arquivoSaida, "%d\n", maiorResultado);
            imprimirResultado(arquivoSaida, transacao, letras);
        }

        return -1;  
    }

    int resposta = -1;

    for (int numero = 0; numero <= 9; numero++) {
        int atribuido = 0;

        for (size_t i = 0; i < 26; i++) {
            if (transacao->correspondencia[i] == numero) {
                atribuido = 1;
                break;
            }
        }

        if (atribuido) {
            continue;
        }

        transacao->correspondencia[letras[letraAtualIdx] - 'A'] = numero;

        if (transacao->correspondencia[A[0] - 'A'] == 0 || transacao->correspondencia[B[0] - 'A'] == 0 || transacao->correspondencia[C[0] - 'A'] == 0) {
            transacao->correspondencia[letras[letraAtualIdx] - 'A'] = -1;
            continue;
        }

        int retorno = decifrarRelatorio(transacao, letras, letraAtualIdx + 1, arquivoSaida, A, B, C);

        if (retorno > resposta) {
            resposta = retorno;
        }

        transacao->correspondencia[letras[letraAtualIdx] - 'A'] = -1;
    }

    return resposta;
}

int decifrarTransacao(Transacao *transacao, char *letras, FILE *arquivoSaida) {
    char *A = transacao->A;  // replace with the actual member names if necessary
    char *B = transacao->B;
    char *C = transacao->C;

    int resultado = decifrarRelatorio(transacao, letras, 0, arquivoSaida, A, B, C);

    escreverArquivoSaida(resultado, transacao, letras);

    return resultado;
}
