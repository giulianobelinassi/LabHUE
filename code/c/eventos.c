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
	#ifdef DEBUG
	static char funcname[] = "Em: dispara_tiros(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	for (k = 0; k < NUMERO_DE_TIROS; ++k)
	{
		coordenadas_tiro(mapa, &i, &j);
		identifica_alvo_atingido(mapa, i, j);
		afunda_embarcacao(mapa, i, j);
	}
		
	/*
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
	*/
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

void coordenadas_tiro(const Mapa* mapa, int* i, int* j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: coordenadas_tiro(%p, %p)\n";
	debug_message(funcname, i, j);
	#endif
	
	*i = sorteia(mapa -> altura);
	*j = sorteia(mapa -> largura);
	
	#ifdef DEBUG
	debug_message("Prestes a retornar\n");
	#endif
}

void identifica_alvo_atingido(Mapa* mapa, int i, int j)
{
	char c = mapa -> matriz[i][j];
	#ifdef DEBUG
	static char funcname[] = "Em: identifica_alvo_atingido(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	c = mapa -> matriz[i][j];
	fprintf(stdout, "(%d, %d): O tiro atingiu ", i, j);
		
	/*
	if     (c == 'S') fprintf(stdout, "Submarino destruído!\n");
	else if(c == 'D') fprintf(stdout, "Destroyer destruído!\n");
	else if(c == 'C') fprintf(stdout, "Cruzador destruído!\n");
	else if(c == 'P') fprintf(stdout, "Porta-Avião destruído!\n");
	else if(c == 'H') fprintf(stdout, "Hidro-Avião destruído!\n");
	*/
	
	switch (c)
	{
		case '.':
			fprintf(stdout, "a água\n");		
			mapa->matriz[i][j] = '=';
		break;
		
		case '*':
			fprintf(stdout, "uma embarcação destruída\n");
		break;
			
		
		
		case 'B':
			mapa->matriz[i][j] = '!';
			fprintf(stdout, "o barco\n");
		break;
		
		case '+':
		case 'T':
			mapa->matriz[i][j] = '+';
		break;
		
			
		case default:
			fprintf(stdout, "uma embarcação\n");
		break;
	}
	
	#ifdef DEBUG
	debug_message("Prestes a retornar\n");
	#endif
}


/** Afunda um destroyer e insere '*' nas posições ocupadas pelo mesmo.
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


/** Afunda um cruzador e insere '*' nas posições ocupadas pelo mesmo.
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


/** Afunda um porta-avião e insere '*' nas posições ocupadas pelo mesmo.
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


/** Afunda um hidro-avião e insere '*' nas posições ocupadas pelo mesmo.
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


void afunda_embarcacao(Mapa* mapa, int i, int j)
{
	char c = mapa -> matriz[i][j];
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_embarcacao(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	swtich (c)
	{
		case 'S':
			mapa -> matriz[i][j] = '*';
		break;
		
		case 'D':
			afunda_destroier(mapa, i, j);
		break;
		
		case 'C':
			afunda_cruzador(mapa, i, j);
		break;
		
		case 'P':
			afunda_porta_aviao(mapa, i, j);
		break;
		
		case 'H':
			afunda_hidro_aviao(mapa, i, j);
		break;
	}
	
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
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
