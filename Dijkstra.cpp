#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

#define FLSH gets(l)

int destino, origem, vertices = 0;
int custo, *custos = NULL;
int cont;
int nameC;


// Função usada para imprimir na tela as cidades
void legendaA(int destino)
{
	int contro = destino;
		
		if(contro == 1){
		printf("Frankfurt");

	}
		if(contro == 2){
		printf("Mannheim");
	}
		if(contro == 3){
		printf("WutzBurg");
	}
		if(contro == 4){
		printf("Kassel");
	}
		if(contro == 5){
		printf("Stuttgart");
	}
		if(contro == 6){
		printf("Karlsruhe");
	}
		if(contro == 7){
		printf("Erfurt");
	}
		if(contro == 8){
		printf("Numberg");
	}
		if(contro == 9){
		printf("Augsburg");
	}
		if(contro == 10){
		printf("Munchen");
	}
	
	
	

	
}

// Função usada para imprimir na tela as Letras do labirinto
void legendaL(int destino)
{
	int controL = destino;
	
	if(controL == 1){
		printf("A");
	}
	if(controL == 2){
		printf("B");
	}
	if(controL == 3){
		printf("C");
	}
	if(controL == 4){
		printf("D");
	}
	if(controL == 5){
		printf("E");
	}
	if(controL == 6){
		printf("F");
	}
	if(controL == 7){
		printf("G");
	}
	if(controL == 8){
		printf("H");
	}
	if(controL == 9){
		printf("I");
	}
	if(controL == 10){
		printf("J");
	}
	if(controL == 11){
		printf("K");
	}
	if(controL == 12){
		printf("L");
	}
	if(controL == 13){
		printf("M");
	}
	if(controL == 14){
		printf("N");
	}
	if(controL == 15){
		printf("O");
	}
	if(controL == 16){
		printf("P");
	}
	if(controL == 17){
		printf("Q");
	}
	if(controL == 18){
		printf("R");
	}
	if(controL == 19){
		printf("S");
	}
	if(controL == 20){
		printf("T");
	}
	if(controL == 21){
		printf("U");
	}
	if(controL == 22){
		printf("V");
	}
	if(controL == 23){
		printf("W");
	}
	if(controL == 24){
		printf("X");
	}
	
}

//algoritimo dijkstra
void dijkstra(int vertices,int origem,int destino,int *custos)
{
    int i,v, cont = 0;
    int *ant, *tmp;
    int *z;     /* vertices para os quais se conhece o caminho minimo */
    double min;
    double dist[vertices]; /* vetor com os custos dos caminhos */


    /* aloca as linhas da matriz */
    ant = (int *)calloc (vertices, sizeof(int));
    tmp = (int *)calloc (vertices, sizeof(int));
    if (ant == NULL)
    {
        printf ("** Erro: Memoria Insuficiente **");
        exit(-1);
    }

    z = (int *)calloc (vertices, sizeof(int));
    if (z == NULL)
    {
        printf ("** Erro: Memoria Insuficiente **");
        exit(-1);
    }

    for (i = 0; i < vertices; i++)
    {
        if (custos[(origem - 1) * vertices + i] !=- 1)
        {
            ant[i] = origem - 1;
            dist[i] = custos[(origem-1)*vertices+i];
        }
        else
        {
            ant[i]= -1;
            dist[i] = HUGE_VAL;
        }
        z[i]=0;
    }
    z[origem-1] = 1;
    dist[origem-1] = 0;

    /* Laco principal */
    do
    {

        /* Encontrando o vertice que deve entrar em z */
        min = HUGE_VAL;
        for (i=0; i<vertices; i++)
            if (!z[i])
                if (dist[i]>=0 && dist[i]<min)
                {
                    min=dist[i];
                    v=i;
                }

        /* Calculando as distancias dos novos vizinhos de z */
        if (min != HUGE_VAL && v != destino - 1)
        {
            z[v] = 1;
            for (i = 0; i < vertices; i++)
                if (!z[i])
                {
                    if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i])
                    {
                        dist[i] = dist[v] + custos[v*vertices+i];
                        ant[i] =v;
                    }
                }
        }
    }
    while (v != destino - 1 && min != HUGE_VAL);
	
	
	
    /* Mostra o Resultado da busca */
    
    
    
    if(nameC>11){
    			printf("\tDe ");
        		legendaL(origem);
            	printf(" para ");
            	legendaL(destino);
            	printf(":\t");
			}else
			{
				printf("\tDe ");
        		legendaA(origem);
            	printf(" para ");
            	legendaA(destino);
            	printf(":\t");
			}
    if (min == HUGE_VAL)
    {
        printf("Nao Existe\n");
        printf("\tCusto: \t- \n");
    }
    else
    {
    
        i = destino;
		i = ant[i-1];
		
        while (i != -1)
        {
            //   printf("<-%d",i+1);
            tmp[cont] = i+1;
            cont++;
            i = ant[i];
        }

        for (i = cont; i > 0 ; i--)
        {	
        	if(nameC>11){
        		legendaL(tmp[i-1]);
            	printf(" -> ");
			}else
			{
				legendaA(tmp[i-1]);
            	printf(" -> ");
			}
        	
        }
        
        if(nameC >10){
        	legendaL(destino);
		}else{
			legendaA(destino);
		}
		
        printf("\n\tCusto:  %d\n",(int) dist[destino-1]);
        
        
    }
}
//função para limpar a tela
void limpar(void)
{
	system("cls");
	printf("...");
}
// função para escrever menu
void cabecalho(void)
{
    
	limpar();
    printf("Implementacao do Algoritmo de Dijasktra\n");
    printf("Comandos:\n");
    printf("\t a - Carregar Mapa Alemanha\n"
    	   "\t l - Carregar Mapa Labirinto\n"	
           "\t r - Mostra o Menor Caminho\n"
           "\t CTRL+c - Sair do programa\n");
    printf(">>> ");
}

// mapa da alemanha
void CriaMapaAlemanha(void)
{
	origem = 1;
	destino = 2;
	custo = 85;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 2;
	destino = 1;
	custo = 85;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 1;
	destino = 3;
	custo = 217;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 3;
	destino = 1;
	custo = 217;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 1;
	destino = 4;
	custo = 173;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 4;
	destino = 1;
	custo = 173;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 2;
	destino = 6;
	custo = 80;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 6;
	destino = 2;
	custo = 80;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 6;
	destino = 9;
	custo = 250;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 9;
	destino = 6;
	custo = 250;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 9;
	destino = 10;
	custo = 84;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 10;
	destino = 9;
	custo = 84;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 3;
	destino = 7;
	custo = 186;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 7;
	destino = 3;
	custo = 186;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 3;
	destino = 8;
	custo = 103;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 8;
	destino = 3;
	custo = 103;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 8;
	destino = 5;
	custo = 183;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 5;
	destino = 8;
	custo = 183;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	
	origem = 8;
	destino = 10;
	custo = 167;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 10;
	destino = 8;
	custo = 167;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	
	origem = 4;
	destino = 10;
	custo = 502;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	
	origem = 10;
	destino = 4;
	custo = 502;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
}
// mapa do labirinto
void CriarMapaLabirinto(void)
{
	origem = 1;
	destino = 2;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 2;
	destino = 1;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 1;
	destino = 7;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 7;
	destino = 1;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 13;
	destino = 19;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 19;
	destino = 13;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 19;
	destino = 20;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 20;
	destino = 19;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 2;
	destino = 8;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 8;
	destino = 2;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 8;
	destino = 9;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 9;
	destino = 8;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 8;
	destino = 14;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 14;
	destino = 8;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 14;
	destino = 20;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 20;
	destino = 14;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 20;
	destino = 21;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 21;
	destino = 20;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 21;
	destino = 15;
	custo = 9;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 15;
	destino = 21;
	custo = 9;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 15;
	destino = 9;
	custo = 9;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 9;
	destino = 15;
	custo = 9;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 9;
	destino = 3;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 3;
	destino = 9;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 3;
	destino = 4;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 4;
	destino = 3;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 4;
	destino = 5;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 5;
	destino = 4;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 4;
	destino = 10;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 10;
	destino = 4;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 10;
	destino = 16;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 16;
	destino = 10;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 16;
	destino = 22;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 22;
	destino = 16;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 10;
	destino = 11;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 11;
	destino = 10;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 5;
	destino = 11;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 11;
	destino = 5;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 11;
	destino = 17;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 17;
	destino = 11;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 23;
	destino = 17;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 17;
	destino = 23;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 23;
	destino = 24;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 24;
	destino = 18;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 18;
	destino = 24;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;	
	
	origem = 12;
	destino = 18;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 18;
	destino = 12;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
	origem = 5;
	destino = 6;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 6;
	destino = 5;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 6;
	destino = 12;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;

	origem = 12;
	destino = 6;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
		origem = 15;
	destino = 16;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
	
		origem = 16;
	destino = 15;
	custo = 1;
	custos[(origem-1) * vertices + destino - 1] = custo;
}

//função adicionar o mapa da alemanha
void addAlemanha(void)
{
    int i, j;
	
    do
    {
        printf("\nCria Mapa com 10 arestas ");
        vertices = 10;
    }
    while (vertices < 2 );

    if (!custos)
        free(custos);
    custos = (int *) malloc(sizeof(int)*vertices*vertices);
    for (i = 0; i <= vertices * vertices; i++)
        custos[i] = -1;

    printf("Gerando Mapa...:\n"); 
    	 
    	 CriaMapaAlemanha();
         printf("Mapa Alemanha Gerado\n");
         system("PAUSE");
         
    }
//função adicionar o mapa do labrinto
void addLabirinto(void)
{
    int i, j;
	
    do
    {
        printf("\nCria Mapa com 24 arestas ");
        vertices = 24;
    }
    while (vertices < 2 );

    if (!custos)
        free(custos);
    custos = (int *) malloc(sizeof(int)*vertices*vertices);
    for (i = 0; i <= vertices * vertices; i++)
        custos[i] = -1;

    printf("Gerando Mapa...:\n"); 
    	 
    	 CriarMapaLabirinto();
        	printf("Mapa Labirinto Gerado\n");
        	system("PAUSE");
        	
        	
    }
    
// chamada da função para procurar o menor caminho
void procurar(void)
{
    int i, j;
    
    if(vertices>10){
    	printf("\nLegenda do Labirinto\n");
    	printf("\n1 - A\n2 - B\n3 - C\n4 - D\n5 - E\n6 - F\n7 - G\n8 - H\n9 - I\n10 - J\n11 - K\n12 - L\n13 - M\n14 - N\n15 - o\n16 - P\n17 - Q\n18 - R\n19 - S\n20 - T\n21 - U\n22 - V\n23 - W\n24 - X");
		nameC = 24;
	}else
	{
		printf("\n Legenda de Cidades");
		printf("\n 1 - Frankfurt\n 2 - Mannheim\n 3 - Wuitzburg\n 4 - Kessel\n 5 - Stuttgart\n 6 - Karlsruhe\n 7 - Erfurt\n 8 - Numberg\n 9 - Augsburg\n 10 - Munchen\n");
		nameC = 10;
	}
	
    printf("\nDigite a origem\n");
    scanf("%d",&i);
    printf("Digite o destino\n");
    scanf("%d",&j);
    
    printf("Lista dos Menores Caminhos no Grafo Dado: \n");
	
	dijkstra(vertices, i,j, custos);
   /* PARA LISTAR TODOS 
    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
            dijkstra(vertices, i,j, custos);
        printf("\n");
    }
	*/
	
    system("PAUSE");

}
// int main
int main(int argc, char **argv)
{
    int i, j;
    char opcao[3], l[50];

    do
    {

        cabecalho();
        scanf("%s", &opcao);

        if ((strcmp(opcao, "a")) == 0)
        {
            addAlemanha();
            FLSH;
        }
       
         if ((strcmp(opcao, "l")) == 0)
        {
            addLabirinto();
            FLSH;
        }
        


        if ((strcmp(opcao, "r") == 0) && (vertices > 0) )
        {
            procurar();
            FLSH;
        }
	
    }
    while (opcao != "x");

    printf("\nAte a proxima...\n\n");

    return 0;
}
