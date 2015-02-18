#include <stdio.h>

#define ordem 16
#define grau 4

typedef struct
{
	int estado; // Estado da lâmpada | 0(Desligado) ou 1(Ligado)
	char visitado; // Vértice foi visitado ou não. s ou n
	int aresta[4];
	int nivel;
}GrafoCubo;

void criaCubo(GrafoCubo * cubo)
{
	int i;

	cubo[0].aresta[0] = 1;
	cubo[0].aresta[1] = 2;
	cubo[0].aresta[2] = 4;
	cubo[0].aresta[3] = 8;

	cubo[1].aresta[0] = 0;
	cubo[1].aresta[1] = 3;
	cubo[1].aresta[2] = 5;
	cubo[1].aresta[3] = 9;

	cubo[2].aresta[0] = 0;
	cubo[2].aresta[1] = 3;
	cubo[2].aresta[2] = 6;
	cubo[2].aresta[3] = 10;

	cubo[3].aresta[0] = 1;
	cubo[3].aresta[1] = 2;
	cubo[3].aresta[2] = 7;
	cubo[3].aresta[3] = 11;

	cubo[4].aresta[0] = 0;
	cubo[4].aresta[1] = 5;
	cubo[4].aresta[2] = 6;
	cubo[4].aresta[3] = 12;

	cubo[5].aresta[0] = 1;
	cubo[5].aresta[1] = 4;
	cubo[5].aresta[2] = 7;
	cubo[5].aresta[3] = 13;

	cubo[6].aresta[0] = 2;
	cubo[6].aresta[1] = 4;
	cubo[6].aresta[2] = 7;
	cubo[6].aresta[3] = 14;

	cubo[7].aresta[0] = 3;
	cubo[7].aresta[1] = 5;
  cubo[7].aresta[2] = 6;
	cubo[7].aresta[3] = 15;

	cubo[8].aresta[0] = 0;
	cubo[8].aresta[1] = 9;
	cubo[8].aresta[2] = 10;
	cubo[8].aresta[3] = 12;

	cubo[9].aresta[0] = 1;
	cubo[9].aresta[1] = 8;
	cubo[9].aresta[2] = 11;
	cubo[9].aresta[3] = 13;

	cubo[10].aresta[0] = 2;
	cubo[10].aresta[1] = 8;
	cubo[10].aresta[2] = 11;
	cubo[10].aresta[3] = 14;

	cubo[11].aresta[0] = 3;
	cubo[11].aresta[1] = 9;
	cubo[11].aresta[2] = 10;
	cubo[11].aresta[3] = 15;

	cubo[12].aresta[0] = 4;
	cubo[12].aresta[1] = 8;
	cubo[12].aresta[2] = 13;
	cubo[12].aresta[3] = 14;

	cubo[13].aresta[0] = 5;
	cubo[13].aresta[1] = 9;
	cubo[13].aresta[2] = 12;
	cubo[13].aresta[3] = 15;

	cubo[14].aresta[0] = 6;
	cubo[14].aresta[1] = 10;
	cubo[14].aresta[2] = 12;
	cubo[14].aresta[3] = 15;

	cubo[15].aresta[0] = 7;
	cubo[15].aresta[1] = 11;
	cubo[15].aresta[2] = 13;
	cubo[15].aresta[3] = 14;
}

int trocaEstado(GrafoCubo * cubo, int atual)
{
	int busca[ordem], ind = 0, j, i;

	for(j = 0; j < ordem; j++)
				cubo[j].visitado = 'n';

	busca[ind] = atual;
	cubo[atual].visitado = 's';
	cubo[atual].nivel = 0;
	ind++;
	//int k, w;

	for(i = 0; i < ordem; i++)
	{


		for(j = 0; j < grau; j++)
		{
			if( cubo[ cubo[ busca[i] ].aresta[j] ].visitado == 'n' )
			{
				busca[ind] = cubo[ busca[i] ].aresta[j];
				cubo[ busca[ind] ].visitado = 's';
				cubo[ busca[ind] ].nivel = cubo[ busca[i] ].nivel + 1;
				if( busca[ind] < 8 && cubo[ busca[ind] ].estado == 1 )
				{
					//printf("\n\nVai trocar com %d\n", busca[ind]);
					cubo[atual].estado = 1;
					cubo[ busca[ind] ].estado = 0;
					return cubo[ busca[ind] ].nivel;
				}
				ind++;
			}
		}
	}
}

int buscaLargura(GrafoCubo * cubo)
{
	int i, flag = 0, move = 0;
	
	for(i = 0; i < 8; i++)
		flag = (cubo[i].estado == 1) ? flag + 1: flag;
	if(flag > 3)
		return 4;
	if(flag == 0)
		return 0;

	for(i = 0; i < 8; i++)
	{
		if(cubo[i].estado == 1 && cubo[i+8].estado == 0)
		{
			cubo[i].estado = 0;
			cubo[i+8].estado = 1;		
			move++;	
		}
	}

	for(i = 8; i < 16; i++)
	{
		if( move > 3 )
				return 4;
		if(cubo[i].estado == 0)
			move += trocaEstado(cubo, i);
	}

	return move;
}

int main()
{
	GrafoCubo cubo[ordem]; // Índice será usada para identificar o vértice
	criaCubo(cubo);
	//exibirVizinho(cubo);
	int n, i, j, ret = 0;
	
	//buscaMenorCaminho(cubo);
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{

		for(j = 0; j < ordem; j++)
			scanf("%d", &cubo[j].estado);

		ret = buscaLargura(cubo);
		if( ret < 4 )
			printf("Case #%d: %d\n", i+1, ret);
		else
			printf("Case #%d: more\n", i+1);

	}
	

  return 0;
}