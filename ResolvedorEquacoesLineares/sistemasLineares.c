#include <stdio.h>
#include <string.h>

    int aux;
    FILE *file;
    char* equacao;

void main()
{
    char* nomeArquivo = (char*)malloc(sizeof(char)*255);
    equacao = (char*)malloc(sizeof(char)*255);
////////////////////////////////////////////////////////////////

    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? \n");
    scanf("%s", nomeArquivo);


    lerArquivo(nomeArquivo);
    printf("%s", equacao);

}

////////////////////////////////////////////////////////////////

// Le o arquivo e pega os valores das equacoes
void lerArquivo(char* a)
{
    char* c = (char*)malloc(sizeof(char)*255);
    file = fopen(a, "r");

    if (file)
    {
        while (fscanf (file, "%s", c) != EOF)
        {
            strcat(equacao, c);
            strcat(equacao, " ");
        }
        fclose(file);
    }
}
