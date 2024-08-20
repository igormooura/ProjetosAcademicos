# Decifrando Relatórios

Inúmeros relatórios envolvendo transações ilegais foram encontradas pela polícia federal na sua mais recente operação: “Gizé". Cada transação é composta por uma somade dois números, resultando em um terceiro. Contudo, os relatórios estão cifrados. Cada dígito foi substituído por uma letra maiúscula, isto é, os números se tornaram palavras.Para resolver este problema, os coordenadores da operação resolveram utilizar a seguinte estratégia. Para cada transação, foi assumido que o valor resultante da soma é amaior possível, já que o objetivo é identificar a ilegalidade. Além disso, cada letra maiúscula corresponde a um algarismo, podendo letras diferentes apontarem para o mesmoalgarismo. Obviamente, os números gerados a partir da correspondência, não podem conter zeros à esquerda, mas podem ser iguais a 0. Como a pilha de relatórios só cresce, os coordenadores procuraram a sua ajuda para resolver o problema.
O trabalho é inspirado em cryptarithmetic
## Arquivo de Entrada
O arquivo de entrada entrada possui três linhas com as palavras A, B e C, as quais descrevem uma transação, isto é, C equivale à soma de A e B. É garantido que as palavras não ultrapassam 8 caracteres e que o número de caracteres distintos nas três palavras é no máximo 7.

## Arquivo de saída
A primeira linha do arquivo de saída deve possuir o maior valor possível de C. Caso
não seja possível decifrar a transação, o valor a ser impresso é “-1”, senão, as próximas
linhas devem descrever a correspondência utilizada para obter os números da transação.
Cada uma destas linhas está no formato“c : d” em que c corresponde a uma letra e d
corresponde a um algarismo.
No caso em que seja possível decifrar o relatório, as correspondências podem ser dadas
em qualquer ordem.

## Modularização 

O sistema é dividido em módulos, cada qual com uma tarefa. Estes módulos
são organizados internamente através de várias funções e eles correspondem aos
seguintes:

• Entrada: lê os relatórios de um arquivo texto.

• Saída: imprime o resultado da decifração em um arquivo texto.

• Processamento: decifra os relatórios, caso possível.

• Tratamento de erros: captura erros e reporta ao usuário, caso necessário.

## Execução
```
make
./decifrar_relatorio ./text/codigos.txt ./text/resultados.txt
```
## Considerações finais

O trabalho foi feito inteiramente por Igor de Oliveira Moura, estudante de Ciências da computação pelo Instituto Federal de Brasília
