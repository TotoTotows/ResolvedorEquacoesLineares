#include <stdio.h>

    int aux;
    char* nomeArquivo;
    FILE *file;
    char* equacao;

void main()
{
    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? ");
    scanf("%s", &nomeArquivo);

    lerArquivo(nomeArquivo);

}

////////////////////////////////////////////////////////////////

void lerArquivo(char* a)
{
    file = fopen(nomeArquivo, "r");

    if (file)
    {
        while (fscanf (file, "%s", equacao) != EOF)
            printf("%s",equacao);

        fclose(file);
    }
}
