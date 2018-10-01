void main()
{
    int aux;
    int qtdVariaveis;
    char* equacao;
    int matriz[][];

////////////////////////////////////////////////////////////////

    // Pega a quantidade de variaveis do sistema
    printf("Quantas variaveis seu sistema vai ter? ");
    scanf("%i", &qtdVariaveis);

    // Faz a matirz com as linhas e colunas certas
    criarMatriz(qtdVariaveis);

    // Pede as equacoes
    for (aux = 1; aux <= qtdVariaveis; aux = aux + 1)
    {
        printf("Digite a %ia equacao", aux);
        scanf("%s", &equacao);
    }

////////////////////////////////////////////////////////////////

    void criarMatriz(int a)
    {

    }

}
