#include <stdio.h>
#include <string.h>

    int i;
    int j;
    FILE *file;

    int qtdVariaveis;
    char* equacao;
    int matriz[254][255];

void main()
{
    char* nomeArquivo = (char*)malloc(sizeof(char)*255);

////////////////////////////////////////////////////////////////

    printf("Quantas variaveis vai ter em cada equacao? ");
    scanf("%i", &qtdVariaveis);

    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? ");
    scanf("%s", nomeArquivo);


    lerArquivo(nomeArquivo);

}

////////////////////////////////////////////////////////////////

// Le o arquivo e pega os valores das equacoes
void lerArquivo(char* a)
{
    char* c = (char*)malloc(sizeof(char)*255);

    file = fopen(a, "r");

    if (file)
    {
        for (i = 0; i < qtdVariaveis; i = i + 1)
        {
            for (j = 0; j < qtdVariaveis*2; j = j + 1)
            {
                fscanf (file, "%s", c);
                matriz[i][j] = (int)c[1];
            }

        }
        fclose(file);
    }

}
