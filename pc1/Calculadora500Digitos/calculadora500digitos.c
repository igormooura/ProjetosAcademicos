#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void somar(char a[], char b[], char resultado[])
{
    int size_operador1 = strlen(a);
    int size_operador2 = strlen(b);
    int tamanho_maior = (size_operador1 > size_operador2) ? size_operador1 : size_operador2; // se sizeop1 for maior q sizeop2, sizeop1 vira tamanho_maior

    int resto = 0;
    int j = 0;

    for (j = 0; j < tamanho_maior; j++)
    {
        int valor1 = (j < size_operador1) ? (a[size_operador1 - 1 - j] - '0') : 0; // verifica se j é maior que size_operador, se for, ele pega o dígito da string a e subtrai '0' para converter o caractere numérico em um valor inteiro, se j for maior ou igual ao tamanho do operador, valor1 = 0, ASCII
        int valor2 = (j < size_operador2) ? (b[size_operador2 - 1 - j] - '0') : 0;

        int soma = valor1 + valor2 + resto;

        if (soma > 9)
        {
            resto = 1;
            soma -= 10;
        }
        else
        {
            resto = 0;
        }

        resultado[j] = soma + '0';
    }

    if (resto != 0)
    {
        resultado[j] = '1';
        j++;
    }

    resultado[j] = '\0';
}

void subtrair(char a[], char b[], char resultado[])
{
    int size_operador1 = strlen(a);
    int size_operador2 = strlen(b);
    int comparacao = strcmp(a, b);

    if (comparacao < 0) //pra ver se a<b 
    {
        char temp[1000]; // crei um array temporário
        strcpy(temp, a); // o valor de A é copiado pra temp, isso é pra conservar o valor de A
        strcpy(a, b); // aqui é pra a receber o valor de b
        strcpy(b, temp); // b recebe o valor de a q tava armazenado no temp
        int temp_size = size_operador1; // tempsize armazena o tamanho de a
        size_operador1 = size_operador2; // o tamanho de A fica do mesmo tamanho de B, os "00000" do lado do numero
        size_operador2 = temp_size; // aqui é pra B ficar do tamanho do valor original de A, pra voltar ao normal
    }
    else if (comparacao == 0) //se a for igual a b, comparação recebe o valor 0 (strcmp que faz isso)
    {
        strcpy(resultado, "0");
        return;
    }

    int emprestimo = 0;
    int j = 0;

    for (j = 0; j < size_operador1 || j < size_operador2; j++)
    {
        int valor1 = (j < size_operador1) ? (a[size_operador1 - 1 - j] - '0') : 0; // verifica se j < tamanho de A, se for, ele pega o digito, subtrai pelo '0' em ASCII, assim transformando pra int
        int valor2 = (j < size_operador2) ? (b[size_operador2 - 1 - j] - '0') : 0;

        int subtracao = valor1 - valor2 - emprestimo;

        if (subtracao < 0)
        {
            subtracao += 10;
            emprestimo = 1;
        }
        else
        {
            emprestimo = 0;
        }

        resultado[j] = subtracao + '0';
    }

    if (comparacao < 0) 
    {
        resultado[j] = '-';
        j++;
    }
    resultado[j] = '\0';
}

void multiplicar(char a[], char b[], char resultado[])
{
    int size_operador1 = strlen(a);
    int size_operador2 = strlen(b);
    int tamanho_resultado = size_operador1 + size_operador2 - 1; //vai ser a variavel q vai determinar o tamanho do resultado da multiplicação, no caso, 501 + 501 
    int i, j;

    for ( i = 0; i <= tamanho_resultado; i++)
    {
        resultado[i] = '0'; // começa recebendo 0 pra iniciar os digitos da multiplicação
    }
    resultado[i] = '\0';
    
    for (i = 0; i < size_operador1; i++)
    {
        int valor1 = a[size_operador1 - 1 - i] - '0'; //itera cada digito de A, indo da direita pra esquerda
        int carry = 0; //carry tem q começar com 0 pra receber o valor da multiplicacao
        
        for (j = 0; j < size_operador2; j++) 
        {
            int valor2 = b[size_operador2 - 1 - j] - '0'; //itera os digitos de B
            int multiplicacao = valor1 * valor2 + carry + (resultado[i + j] - '0'); // acrescenta o valor de A * B + o carry q já tem o valor de A, dai armazena o resultado em [i + j]
            carry = multiplicacao / 10;
            resultado[i + j] = (multiplicacao % 10) + '0';
        }
        
        resultado[i + size_operador2] = carry + '0';
    }
}

void inverterString(char resultado[])
{
    int k;
    int len = strlen(resultado);
    for (k = 0; k < len / 2; k++)
    {
        char temp = resultado[k];
        resultado[k] = resultado[len - 1 - k]; //resultado é atrelado ao valor "k"
        resultado[len - 1 - k] = temp; // e iss completa a inversão de valores
    }
}
void removerZerosEsquerda(char resultado[])
{
    int len = strlen(resultado);

    // pra caso a string so ter 1 "0"
    if (len == 1 && resultado[0] == '0')
    {
        return;
    }

   // numero negativo
    if (resultado[1] == '0' && resultado[0] == '-'){
        int i;
        for (i = 1; i < len; i++)
        {
            resultado[i] = resultado[i + 1];
        }
        resultado[i] = '\0';
    }
    // numero positivo
    if (resultado[0] == '0'){
        int i;
        for (i = 0; i < len; i++)
        {
        resultado[i] = resultado[i + 1];
        }
        resultado[i] = '\0';

    }
}

int main()
{
    char a[501], b[501], resultado[1002];
    int n, i, o;
    char resultados[100][1002];
    int operador_anterior = 1;
    
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s %s %d", a, b, &o);
        
        if (o == 1)
        {
            somar(a, b, resultado);
            inverterString(resultado);
        }
        else if (o == 2)
        {
            subtrair(a, b, resultado);
            inverterString(resultado);
            removerZerosEsquerda(resultado);
  
        }

        else if (o == 3)
        {
            multiplicar(a, b, resultado);
            inverterString(resultado);
            removerZerosEsquerda(resultado);
            
        } 
        else
        {
            printf("Opção inválida\n");
            continue;
        }
       
        strcpy(resultados[i], resultado); // Armazena o resultado atual em 'resultados'
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n", resultados[i]); // Imprime os resultados armazenados
    }

    return 0;
}
