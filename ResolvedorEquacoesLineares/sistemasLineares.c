#include <stdio.h>
#include <string.h>

    int i;
    FILE *file;
    char* equacao;
    int** matriz;

void main()
{
    char* nomeArquivo = (char*)malloc(sizeof(char)*255);
    equacao = (char*)malloc(sizeof(char)*255);
////////////////////////////////////////////////////////////////

    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? \n");
    scanf("%s", nomeArquivo);


    lerArquivo(nomeArquivo);

    //matriz = (int**)malloc(size(int*) * 255);
    //for (i=0; 255; i++)
    {
        //matriz[i] = malloc(size(int) * 255);
    }

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
            printf("%s ", c);

        }

        printf("%s", equacao);
        fclose(file);
    }
}
