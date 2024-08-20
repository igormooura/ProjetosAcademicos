#include <stdio.h>
#include <stdlib.h>
#include "../include/erros.h"

// Função para relatar erros
void reportError(const char *errorMessage) {
    fprintf(stderr, "Erro: %s\n", errorMessage);
    exit(EXIT_FAILURE);
}
