/*
  * @file 
  * @brief Arquivo implementando funções que lidam com operações eventuais
  */

#include "eventos.h"
#include "mapa.h"
#include "barco.h"
#include <stdlib.h>

#define NUMERO_DE_TIROS 3 /** Número de tiros por rodada.*/

int dispara_tiros(Mapa_t* mapa, FILE* file)
{
	int i, j, k;
	char resp;
	
	for (k = 0; k < NUMERO_DE_TIROS && resp != 'B'; ++k)
	{
		coordenadas_tiro(mapa, &i, &j);
		resp = identifica_alvo_atingido(mapa, i, j, file);
	}

	if (resp == 'B')
		return 0; /* O barco não foi atingido*/
	
	return 1; /* O barco foi atingido.*/
}

void coordenadas_tiro(const Mapa_t* mapa, int* i, int* j)
{
	
	*i = SORTEIA(mapa -> altura);
	*j = SORTEIA(mapa -> largura);

}

char identifica_alvo_atingido(Mapa_t* mapa, int i, int j, FILE* arquivo)
{
	static const char TIRO_ATINGIU[]		= "(%d, %d): O tiro atingiu "; 
	static const char AGUA[]			= "a água\n";
	static const char EMBARCACAO_DESTRUIDA[]	= "uma embarcação destruída\n";
	static const char POSICAO_ANTERIOR[]		= "uma posição anterior do barco\n";
	static const char O_BARCO[]			= "o barco\n";
	static const char UMA_EMBARCACAO[]		= "uma embarcação - ";
	static const char SUBMARINO_DESTRUIDO[]		= "Submarino destruído!\n";
	static const char DESTROYER_DESTRUIDO[]		= "Destroyer destruído!\n";
	static const char CRUZADOR_DESTRUIDO[] 		= "Cruzador destruído!\n";
	static const char PORTA_AVIAO_DESTRUIDO[]	= "Porta-Avião destruído!\n";
	static const char HIDRO_AVIAO_DESTRUIDO[]	= "Hidro-Avião destruído!\n";
	
	char c = mapa -> matriz[i][j];
	const char* str = NULL;
	
	c = mapa -> matriz[i][j];

	fprintf(stdout , TIRO_ATINGIU, i, j);
	fprintf(arquivo, TIRO_ATINGIU, i, j);

	if(c == '.' || c == '=')
	{
		str = AGUA;
		mapa -> matriz[i][j] = '=';
	}
	else if(c == '*')
	{
		str = EMBARCACAO_DESTRUIDA;
	}
	else if(c == '+' || c == 'T')
	{
		str = POSICAO_ANTERIOR;
		mapa -> matriz[i][j] = '+';
	}
	else if(c == 'B')
	{
		str = O_BARCO;
		mapa -> matriz[i][j] = '!';
	}
	else
	{
		fprintf(stdout , UMA_EMBARCACAO);
		fprintf(arquivo, UMA_EMBARCACAO);
		
		if(c == 'S')
			str = SUBMARINO_DESTRUIDO;
		
		else if(c == 'D')
		{
			str = DESTROYER_DESTRUIDO;
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
		else if(c == 'C')
		{
			str = CRUZADOR_DESTRUIDO;
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
		else if(c == 'P')
		{
			str = PORTA_AVIAO_DESTRUIDO;
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
		else if(c == 'H')
		{
			str = HIDRO_AVIAO_DESTRUIDO;
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
	}
	
	fputs(str, stdout);
	fputs(str, arquivo);
	
	return c;
}


void afunda_embarcacao(Mapa_t* mapa, char tipo, int linha, int coluna)
{
	int i, j;
	
	mapa->matriz[linha][coluna] = '*';
	for(i = linha - 1; i< mapa->altura; i++)
		for(j = coluna - 1; i >= 0 && j < mapa->largura; j++)
			if(j >= 0 && mapa->matriz[i][j] == tipo)
				afunda_embarcacao(mapa, tipo, i, j);
}


int ganhou_jogo(const Mapa_t* mapa, const Barco_t* barco)
{	
	if (barco->linha >= mapa->altura-1)	
		return 1;
	return 0;
}
