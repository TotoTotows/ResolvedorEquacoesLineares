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
    inverterEquacoes();

}

////////////////////////////////////////////////////////////////

// Le o arquivo e coloca os valores na matriz
void lerArquivo(char* a)
{
    char* c = (char*)malloc(sizeof(char)*255);

    file = fopen(a, "r");
    if (file)
    {
		// Coloca os valores das equacoes na matriz
        for (i = 0; i < qtdVariaveis; i = i + 1)
        {
            for (j = 0; j < qtdVariaveis; j = j + 1)
            {
                fscanf (file, "%s", c);
                matriz[i][j] = c[0] - '0';
                fscanf (file, "%s", c);
            }
            fscanf (file, "%s", c);
            matriz[i][qtdVariaveis] = atoi(c);

        }
        fclose(file);
    }

}

// Faz com que nao tenha nenhum 0 na diagonal principal
void inverterEquacoes()
{
    if (matriz[0][0])
    {
        inverterEssa(1);
        inverterEquacoes();
    }

    if (matriz[1][1])
    {
        inverterEssa(2);
        inverterEquacoes();
    }

    if (matriz[2][2])
    {
        inverterEssa(3);
        inverterEquacoes();
    }

}

void inverterEssa(int e);
{

}
