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

int dispara_tiros(Mapa* mapa)
{
	int i, j;
	char c;
	#ifdef DEBUG
	static char funcname[] = "Em: dispara_tiros(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	coordenadas_tiro(mapa, &i, &j);
	c = mapa -> matriz[i][j];
	fprintf(stdout, "(%d, %d): O tiro atingiu ", i, j);
	if(c == '-' || c == '=')
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
		fprintf(stdout, "uma embarcação\n");
		afunda_embarcacao(mapa, i, j);
	}

	coordenadas_tiro(mapa, &i, &j);
	c = mapa -> matriz[i][j];
	fprintf(stdout, "(%d, %d): O tiro atingiu ", i, j);
	if(c == '-' || c == '=')
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
		fprintf(stdout, "uma embarcação\n");
		afunda_embarcacao(mapa, i, j);
	}

	coordenadas_tiro(mapa, &i, &j);
	c = mapa -> matriz[i][j];
	fprintf(stdout, "(%d, %d): O tiro atingiu ", i, j);
	if(c == '-' || c == '=')
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
		fprintf(stdout, "uma embarcação\n");
		afunda_embarcacao(mapa, i, j);
	}
	return 0;
}

int coordenadas_tiro(Mapa* mapa, int* i, int* j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: coordenadas_tiro(%p, %p)\n";
	debug_message(funcname, i, j);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	*i = sorteia(mapa -> altura);
	*j = sorteia(mapa -> largura);
	return 0;
}

int identifica_alvo_atingido(Mapa* mapa, int i, int j)
{
	char c = mapa -> matriz[i][j];
	#ifdef DEBUG
	static char funcname[] = "Em: identifica_alvo_atingido(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	
	if(c == 'S') fprintf(stdout, "Submarino destruído!\n");
	else if(c == 'D') fprintf(stdout, "Destroyer destruído!\n");
	else if(c == 'C') fprintf(stdout, "Cruzador destruído!\n");
	else if(c == 'P') fprintf(stdout, "Porta-Avião destruído!\n");
	else if(c == 'H') fprintf(stdout, "Hidro-Avião destruído!\n");
	return 0;
}


/** Afunda um destroyer 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_destroier(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_destroyer(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}


/** Afunda um cruzador 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_cruzador(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_cruzador(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}


/** Afunda um porta-avião 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_porta_aviao(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_porta_aviao(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}


/** Afunda um hidro-avião 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_hidro_aviao(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_hidro_aviao(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}


int afunda_embarcacao(Mapa* mapa, int i, int j)
{
	char c = mapa -> matriz[i][j];
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_embarcacao(%p)\n";
	debug_message(funcname, mapa);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	
	identifica_alvo_atingido(mapa, i, j);
	if(c == 'S') mapa -> matriz[i][j] = '*';
	else if(c == 'D') afunda_destroier(mapa, i, j);
	else if(c == 'C') afunda_cruzador(mapa, i, j);
	else if(c == 'P') afunda_porta_aviao(mapa, i, j);
	else if(c == 'H') afunda_hidro_aviao(mapa, i, j);
	return 0;
}


int ganhou_jogo(const Mapa* mapa, const Barco* barco)
{
	#ifdef DEBUG
	static char funcname[] = "Em: ganhou_jogo(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
