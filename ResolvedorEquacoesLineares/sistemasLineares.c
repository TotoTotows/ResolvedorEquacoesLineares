#include <stdio.h>
#include <string.h>

    int i;
    FILE *file;

    int qtdVariaveis;
    char* equacao;
    int equacoes[254];
    int** matriz;

void main()
{
    char* nomeArquivo = (char*)malloc(sizeof(char)*255);
    equacao = (char*)malloc(sizeof(char)*255);

////////////////////////////////////////////////////////////////

    printf("Quantas variaveis vai ter em cada equacao? ");
    scanf("%i", &qtdVariaveis);

    // Cria a matriz do tamanho certo
    //matriz = (int**)malloc(size(int*) * qtdVariaveis);
    //for (i=0; i > qtdVariaveis; i = i + 1)
    {
        //matriz[i] = malloc(size(int) * 255);
    }

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
        while (fscanf (file, "%s", c) != EOF)
        {
            printf("%s ", c);

        }
        fclose(file);
    }
}
