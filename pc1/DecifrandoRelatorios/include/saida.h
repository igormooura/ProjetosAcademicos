#ifndef SAIDA_H
#define SAIDA_H

#include "decifrar_relatorio.h"

void escreverArquivoSaida(int resultado, Transacao *transacao, char *letras);
void imprimirResultado(FILE *saida, Transacao *transacao, char *letras);

#endif  // SAIDA_H
