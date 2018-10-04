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

    printf("%i ", matriz[0][0]);
    printf("%i ", matriz[0][1]);
    printf("%i ", matriz[0][2]);
    printf("%i\n", matriz[0][3]);

    printf("%i ", matriz[1][0]);
    printf("%i ", matriz[1][1]);
    printf("%i ", matriz[1][2]);
    printf("%i\n", matriz[1][3]);

    printf("%i ", matriz[2][0]);
    printf("%i ", matriz[2][1]);
    printf("%i ", matriz[2][2]);
    printf("%i\n", matriz[2][3]);
}
