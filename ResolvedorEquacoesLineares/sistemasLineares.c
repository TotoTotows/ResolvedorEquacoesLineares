#include <stdio.h>
#include <string.h>

    FILE *file;

    int qtdVariaveis;
    double** matriz;
    double** matrizAux;
    Lista lis;

void main()
{
    int i;

    char* nomeArquivo = (char*)malloc(sizeof(char)*255);

    printf("Quantas variaveis vai ter em cada equacao? ");
    scanf("%i", &qtdVariaveis);

    matriz = (double**)(malloc(sizeof(double*) * (qtdVariaveis)));
    for (i = 0; i < qtdVariaveis; i++)
        *(matriz+i) = (double*)malloc(sizeof(double)*qtdVariaveis + 1);

    matrizAux = (double**)(malloc(sizeof(double*) * (qtdVariaveis)));
    for (i = 0; i < qtdVariaveis; i++)
        *(matrizAux+i) = (double*)malloc(sizeof(double)*qtdVariaveis);


    // Pega o nome do arquivo a ser lido
    printf("Qual o nome do arquivo a ser lido ? ");
    scanf("%s", nomeArquivo);

    lerArquivo(nomeArquivo);
    exec(matriz);

    resolverSistema();

}

double processarNumero(char* c)
{
    int i;
    double ret;
    char gambi[255];
    *(gambi) = '\0';
    char caracter_a_inserir[2];
    *(caracter_a_inserir + 1) = '\0';
    int tamanho = strlen(c);
     for (i = 0; i < tamanho-1; i++)
    {
        *caracter_a_inserir = c[i];
        strcat(gambi, caracter_a_inserir);
    }
     sscanf(gambi, "%lf", &ret);
     return ret;
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
            sinal = 1;

            for (j = 0; j < qtdVariaveis; j++)
            {
                fscanf (file, "%s", c);
                *(*(matriz+i)+j) = sinal*(processarNumero(c));

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
            sscanf(c, "%lf", &matriz[i][qtdVariaveis]);
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

void resolverSistema() // Resolve o sistema utilizando o metodo de cramer
{
    int i,j,k;

    double det = determinante(matriz, qtdVariaveis);

    for(i = 0; i < qtdVariaveis ; i++)
    {
        for(j = 0; j < qtdVariaveis; j++)
        {
             for(k = 0; k < qtdVariaveis; k++)
             {
                 *(*(matrizAux+j)+k) = *(*(matriz+j)+k);
             }
        }

        for(k = 0; k < qtdVariaveis; k++)
        {
            *(*(matrizAux+k)+i) = *(*(matriz+k)+(qtdVariaveis));
        }
        double cofator = determinante(matrizAux, qtdVariaveis);
        double result  = cofator/det;
        printf("%.2lf, ", result);

    }
}

double ehSinal(char* c)//Identifica se o número é negativo ou positivo
{
    if (c == "-")
        return -1;

    if (c == "+")
        return 1;

    return 1;
}

void exec(double** matrizExex)//Printa a matriz
{
    int i,j;

    for(i = 0; i < qtdVariaveis; i++)
    {
       for(j = 0; j <= qtdVariaveis; j++)
       {
            printf("%.2f ", *(*(matrizExex+i)+j));
       }
       printf("\n\n");
    }
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

// LISTA

typedef
    struct No
    {
        void* info;
        struct No* prox;
        void* valor;
    }
    No;


typedef
    struct Lista
    {
        No* inicio;
        int (*compareTo)(void*, void*);
        void (*print)(void*);
    }
    Lista;

typedef
    enum boolean
    {
        false,
        true
    }
    boolean;

void insira(Lista* lis, void* info)
{
    if(lis==NULL)
        return;

    if(lis->inicio==NULL)
    {
        lis->inicio = (No*)malloc(sizeof(No));
        lis->inicio->info = info;
        lis->inicio->valor = NULL;
        lis->inicio->prox = NULL;

        return true;
    }

    No* atual =  lis->inicio;

    while(atual->prox!=NULL)
    {
        atual = atual->prox;
    }

    atual->prox = (No*)(malloc(sizeof(No)));
    atual->prox->info = info;
    atual->prox->valor = NULL;
    atual->prox->prox = NULL;
}

void insiraValor(Lista* lis, void* info, int pos)
{
    int i =0;

    No* atual =  (No*)(malloc(sizeof(No)));
    atual = lis->inicio;

    for(; i<pos; i++)
        if(atual->prox==NULL)
            break;
        else
            atual = atual->prox;

    atual->valor = info;
}

void printeLista(Lista lis)
{
    No* atual =  (No*)(malloc(sizeof(No*)));
    atual = lis.inicio;

    while(atual!=NULL)
    {
        printf(atual->info);
        printf(atual->valor);
        atual = atual->prox;
    }
}
