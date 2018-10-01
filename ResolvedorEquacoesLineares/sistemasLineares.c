#include <stdio.h>
#include <stdlib.h>

void main()
{
    int aux;
    char* nomeArquivo;
    FILE *file;

////////////////////////////////////////////////////////////////

    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? ");
    scanf("%s", &nomeArquivo);

    lerArquivo(nomeArquivo);

}

////////////////////////////////////////////////////////////////

void lerArquivo(char* a)
{
    file = fopen(nomeArquivo, "r");
}
