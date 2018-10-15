#include <stdio.h>
#include <string.h>

    FILE *file;

    int qtdVariaveis;
    float** matriz;

void main()
{
    char* nomeArquivo = (char*)malloc(sizeof(char)*255);


    printf("Quantas variaveis vai ter em cada equacao? ");
    scanf("%i", &qtdVariaveis);

    matriz = (float**)(malloc(sizeof(float*) * (qtdVariaveis + 1)));

    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? ");
    scanf("%s", nomeArquivo);


    lerArquivo(nomeArquivo);


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
                *(*(matriz+i)+j ) = (float)c[0] - '0';
                fscanf (file, "%s", c);
            }
            fscanf (file, "%s", c);
            matriz[i][qtdVariaveis] = (float)atoi(c);

        }
        fclose(file);
    }
//matriz [1][1]
//*(*(matriz+1)+1)
}

double determinante(double** matriz, int ordem) {
	int    a, i, j;
	double ret = 0;
	int    c1, c2;
	int    O = 1; /* representa se o cofator atual deve ser multiplicado por 1 ou -1 */

	if (ordem == 2) {
		ret = **(matriz) * *(*(matriz+1)+1) - *(*(matriz)+1) * *(*(matriz+1));
		return ret;
	}

	double** matriz_menor = (double**)malloc(sizeof(double*)*(ordem-1));
	for (i=0; i<ordem-1; i++)
		*(matriz_menor+i) = (double*)malloc(sizeof(double)*(ordem-1));

	for (a=0; a<ordem; a++) { /* ira percorrer a primeira linha da matriz */
		c1 = 0, c2 = 0;
		for (i=1; i<ordem; i++) { /* linha da matriz menor */
			for (j=0; j<ordem; j++) { /* coluna da matriz menor */
				if (j != a) {
					/* ira colocar na matriz menor somente aqueles que nao pertencem
					 * a linha e coluna do elemento cujo cofator esteja sendo calculado */
					*(*(matriz_menor+c1)+c2) = *(*(matriz+i)+j);
					c2++;
					if (c2>ordem-2) {
						c1++;
						c2=0;
					}
				}
			}
		}
		ret = ret + O*(*(*(matriz)+a) * determinante(matriz_menor, ordem-1));
		O = -1*O;
	}

	for (i=0; i<(ordem-1); i++)
		free(*(matriz_menor+i));
	free(matriz_menor);

	return ret;
}


// Usa os outros metodos para resolver o sistema
void resolverSistema()
{
	int i;

	for (i = 0; i < qtdVariaveis; i++)
	{
        exec();
	}

}

void exec()
{
    int i, j;

    for(i = 0; i < qtdVariaveis; i++)
    {
       for(j = 0; j < qtdVariaveis - 1; j++)
       {
            printf("%.2lf ", *(*(matriz+i)+j));
       }
       printf("%.2lf\n\n", *(*(matriz+i)+qtdVariaveis));
    }
}
