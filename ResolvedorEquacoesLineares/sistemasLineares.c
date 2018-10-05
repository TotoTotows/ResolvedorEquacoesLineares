#include <stdio.h>
#include <string.h>

    FILE *file;

    int qtdVariaveis;
    float matriz[254][255];

void main()
{
    char* nomeArquivo = (char*)malloc(sizeof(char)*255);


    printf("Quantas variaveis vai ter em cada equacao? ");
    scanf("%i", &qtdVariaveis);

    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? ");
    scanf("%s", nomeArquivo);


    lerArquivo(nomeArquivo);
    desanularEquacoes();
    resolverSistema();

    exec();

}

////////////////////////////////////////////////////////////////

// Le o arquivo e coloca os valores na matriz
void lerArquivo(char* a)
{
    int i;
    int j;
    char* c = (char*)malloc(sizeof(char)*255);

    file = fopen(a, "r");
    if (file)
    {
		// Coloca os valores das equacoes na matriz
        for (i = 0; i < qtdVariaveis; i++)
        {
            for (j = 0; j < qtdVariaveis; j++)
            {
                fscanf (file, "%s", c);
                matriz[i][j] = (float)c[0] - '0';
                fscanf (file, "%s", c);
            }
            fscanf (file, "%s", c);
            matriz[i][qtdVariaveis] = (float)atoi(c);

        }
        fclose(file);
    }

}

// Desanula todas as equacoes do sistema
void desanularEquacoes()
{
    int i;

    for (i = 0; i < qtdVariaveis; i++)
    {
        if (matriz[i][i] == 0)
            desanularEssa(i + 1);

    }

}

// Desanula a uma equacao em especifico
void desanularEssa(int e)
{
    int i;

    for (i = 0; i < qtdVariaveis; i++)
    {
        if (matriz[i][e - 1] != 0)
            somarEquacoes(e, i+1);

    }

}

// Soma duas equacoes
void somarEquacoes(int a, int b)
{
    int i;

    for (i = 0; i <= qtdVariaveis; i++)
    {
        matriz[a-1][i] += matriz[b-1][i];
    }

}

// Divide uma equacao especifica
void dividirEssa(int e, int n)
{
    int i;
    int divisor = n;

    if (divisor == NULL)
        divisor = matriz[e-1][e-1];

    for (i = 0; i <= qtdVariaveis; i++)
    {
        matriz[e-1][i] = matriz[e-1][i]/divisor;
    }
}

void anularOutras(int c)
{
    int i;
    int divisor;

    for (i = c - 1; i > 0; i--)
    {
        dividirEssa(c, 1/matriz[i-1][c]);
        somarEquacoes(i, i+1);
        dividirEssa(c, matriz[i-1][c]);
    }

    for (i = c; i < qtdVariaveis; i++)
    {
        dividirEssa(c, 1/matriz[i][c]);
        somarEquacoes(i, i-1);
        dividirEssa(c, matriz[i][c]);
    }

}

// Usa os outros metodos para resolver o sistema
void resolverSistema()
{
	int i;

	for (i = 0; i < qtdVariaveis; i++)
    {
        dividirEssa(i + 1, NULL);
        anularOutras(i + 1);

    }

}

void exec()
{
    printf("%.2f ", matriz[0][0]);
    printf("%.2f ", matriz[0][1]);
    printf("%.2f ", matriz[0][2]);
    printf("%.2f\n", matriz[0][3]);

    printf("%.2f ", matriz[1][0]);
    printf("%.2f ", matriz[1][1]);
    printf("%.2f ", matriz[1][2]);
    printf("%.2f\n", matriz[1][3]);

    printf("%.2f ", matriz[2][0]);
    printf("%.2f ", matriz[2][1]);
    printf("%.2f ", matriz[2][2]);
    printf("%.2f\n\n", matriz[2][3]);
}
