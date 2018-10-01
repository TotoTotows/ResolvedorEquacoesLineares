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

// Le o arquivo e pega os valores das equacoes
void lerArquivo(char* a)
{
    // Apenas para que o EOF funcione
    char c[999];

////////////////////////////////////////////////////////////////

    file = fopen("teste.txt", "r");

    if (file)
    {
        while (fscanf (file, "%s", c) != EOF)
            printf("%s",equacao);

        fclose(file);
    }
}
