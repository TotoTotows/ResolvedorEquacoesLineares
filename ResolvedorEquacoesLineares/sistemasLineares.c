#include <stdio.h>
#include <string.h>

    FILE *file;

    int qtdVariaveis;
    double** matriz;
    double** matrizAux;

void main()
{
    int i;

    char* nomeArquivo = (char*)malloc(sizeof(char)*255);

    printf("Quantas variaveis vai ter em cada equacao? ");
    scanf("%i", &qtdVariaveis);

    matriz = (double**)(malloc(sizeof(double*) * (qtdVariaveis + 1)));
    for (i = 0; i < qtdVariaveis; i++)
        *(matriz+i) = (double*)malloc(sizeof(double)*qtdVariaveis);

    matrizAux = (double**)(malloc(sizeof(double*) * (qtdVariaveis)));
    for (i = 0; i < qtdVariaveis; i++)
        *(matrizAux+i) = (double*)malloc(sizeof(double)*qtdVariaveis);


    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? ");
    scanf("%s", nomeArquivo);

    lerArquivo(nomeArquivo);

    resolverSistema();

}

////////////////////////////////////////////////////////////////

// Le o arquivo e coloca os valores na matriz
void lerArquivo(char* a)
{
    int i;
    int j;
    char* c = (char*)malloc(sizeof(char)*255);
    double sinal = 1;

    file = fopen(a, "r");
    if (file)
    {
		//Coloca os valores das equacoes na matriz
        for (i = 0; i < qtdVariaveis; i++)
        {
            for (j = 0; j < qtdVariaveis; j++)
            {
                fscanf (file, "%s", c);
                *(*(matriz+i)+j ) = sinal*((double)c[0] - '0');

                fscanf (file, "%s", c);
                    if (strcmp(c,"-") == 0)
                    {
                        sinal = -1;
                    }

                    if (strcmp(c,"+") == 0)
                    {
                        sinal = 1;
                    }

            }
            fscanf (file, "%s", c);
            matriz[i][qtdVariaveis] = (double)atoi(c);

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

	double** matriz_menor = (double**)malloc(sizeof(double*)*(ordem-2));
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
    int i,j,k,l;

    double det = determinante(matriz, qtdVariaveis);

    //printf("%lf", det);

    double detPrin = determinante(matriz, qtdVariaveis);
    for(i = 0; i < qtdVariaveis ; i++)
    {
        for(j = 0; j < qtdVariaveis; j++)
        {
             for(l = 0; l < qtdVariaveis; l++)
             {
                 *(*(matrizAux+j)+l) = *(*(matriz+j)+l);
             }
        }

        for(k = 0; k < qtdVariaveis; k++)
        {
            *(*(matrizAux+k)+i) = *(*(matriz+k)+(qtdVariaveis));
        }
        double detMatrizAux = determinante(matrizAux, qtdVariaveis);
        double result       = detMatrizAux/det;
        printf("%.2lf, ", result);


    }

}

char* processarNumero(char* c)
{

}

double ehSinal(char* c)
{
    if (c == "-")
        return -1;

    if (c == "+")
        return 1;

    return 1;
}

void exec(double** matrizExex)
{
    int i;
    int j;
    int k;

    for(i = 0; i < qtdVariaveis; i++)
    {
       for(j = 0; j < qtdVariaveis; j++)
       {
            printf("%.2f ", *(*(matrizExex+i)+j));
       }
       printf("\n\n");
    }


}
