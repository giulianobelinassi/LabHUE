/**
  * @file 
  * @brief Arquivo implementando funções que lidam com operações eventuais
  */

#include "eventos.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#include "debug.h"
#endif

#define NUMERO_DE_TIROS 3

int dispara_tiros(Mapa* mapa)
{
	int i, j, k;
	char resp;
	#ifdef DEBUG
	static char funcname[] = "Em: dispara_tiros(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	for (k = 0; k < NUMERO_DE_TIROS && resp != 'B'; ++k)
	{
		coordenadas_tiro(mapa, &i, &j);
		resp = identifica_alvo_atingido(mapa, i, j);
	}

	if (resp == 'B')
	{	
		#ifdef DEBUG
		debug_message("Prestes a retornar 0\n");
		#endif
		
		return 0; /* O barco não foi atingido*/
	}
	#ifdef DEBUG
	debug_message("Prestes a retornar 1\n");
	#endif
	
	return 1; /* O barco foi atingido.*/
}

void coordenadas_tiro(const Mapa* mapa, int* i, int* j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: coordenadas_tiro(%p, %p)\n";
	debug_message(funcname, i, j);
	#endif
	
/*	*i = sorteia(mapa -> altura);
	*j = sorteia(mapa -> largura);
*/

	*i = rand()%mapa->altura;
	*j = rand()%mapa->largura;
	
	#ifdef DEBUG
	debug_message("Prestes a retornar\n");
	#endif
}

char identifica_alvo_atingido(Mapa* mapa, int i, int j)
{
	char c = mapa -> matriz[i][j];
	#ifdef DEBUG
	static char funcname[] = "Em: identifica_alvo_atingido(%p)\n";
	debug_message(funcname, mapa);
	#endif

	c = mapa -> matriz[i][j];
	fprintf(stdout, "(%d, %d): O tiro atingiu ", i, j);
	if(c == '.' || c == '=')
	{
		fprintf(stdout, "a água\n");
		mapa -> matriz[i][j] = '=';
	}
	else if(c == '*')
	{
		fprintf(stdout, "uma embarcação destruída\n");
	}
	else if(c == '+' || c == 'T')
	{
		fprintf(stdout, "uma posição anterior do barco\n");
		mapa -> matriz[i][j] = '+';
	}
	else if(c == 'B')
	{
		fprintf(stdout, "o barco\n");
		mapa -> matriz[i][j] = '!';
	}
	else
	{
		fprintf(stdout, "uma embarcação - ");
		if     (c == 'S')
			fprintf(stdout, "Submarino destruído!\n");
		
		else if(c == 'D')
		{
			fprintf(stdout, "Destroyer destruído!\n");
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
		else if(c == 'C')
		{
			fprintf(stdout, "Cruzador destruído!\n");
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
		else if(c == 'P')
		{
			fprintf(stdout, "Porta-Avião destruído!\n");
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
		else if(c == 'H')
		{
			fprintf(stdout, "Hidro-Avião destruído!\n");
			afunda_embarcacao(mapa, mapa->matriz[i][j], i, j);
		}
	}
	
	#ifdef DEBUG
	debug_message("Prestes a retornar '%c'\n", c);
	#endif
	return c;
}


void afunda_embarcacao(Mapa* mapa, char tipo, int linha, int coluna)
{
	int i, j;
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_embarcacao(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	mapa->matriz[linha][coluna] = '*';
	for(i = linha - 1; i< mapa->altura; i++)
		for(j = coluna - 1; i >= 0 && j < mapa->largura; j++)
			if(j >= 0 && mapa->matriz[i][j] == tipo)
				afunda_embarcacao(mapa, tipo, i, j);
	
	#ifdef DEBUG
	debug_message("Prestes a retornar\n");
	#endif
}


int ganhou_jogo(const Mapa* mapa, const Barco* barco)
{
	#ifdef DEBUG
	static char funcname[] = "Em: ganhou_jogo(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	if (barco->linha >= mapa->altura-1)
	{	
		#ifdef DEBUG
		debug_message("Prestes a retornar 1\n");
		#endif
		return 1;
	}
		
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
