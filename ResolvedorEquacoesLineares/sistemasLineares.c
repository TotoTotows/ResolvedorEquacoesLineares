#include <stdio.h>

    int aux;
    FILE *file;

void main()
{
    char* nomeArquivo = (char*)malloc(sizeof(char)*255);

////////////////////////////////////////////////////////////////

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
    char* c = (char*)malloc(sizeof(char)*255);

////////////////////////////////////////////////////////////////

    printf("%s\n", *a);

    file = fopen("teste.txt", "r");

    if (file)
    {
        while (fscanf (file, "%s", c) != EOF)
            printf("%s\n", c);

        fclose(file);
    }
}
