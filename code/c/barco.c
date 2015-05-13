/**
  * @file 
  * @brief Arquivo implementando as funções que lidam com operações navais
  */

#include "barco.h"
#include <stdio.h>

#ifdef DEBUG
#include "debug.h"
#endif

int rema_barco(pMapa mapa, pBarco barco)
{
	char mov;
	int naoRemou = 1;
	#ifdef DEBUG
	static char funcname[] = "Chamado: rema_barco(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	printf("Mova o barco\n");
	printf("(b)baixo  (e)esquerda  (d)direita\n");
	fscanf(stdin, " %c", &mov);
	switch(mov)
	{
		case 'b':	
			if(barco->linha + 1 < mapa->altura && mapa->matriz[barco->linha + 1][barco->coluna] == '.')
			{
				mapa->matriz[barco->linha][barco->coluna] = 'T';
				mapa->matriz[barco->linha + 1][barco->coluna] = 'B';
				barco->linha++;
				naoRemou = 0;
			}
		break;
		
		case 'e':
			if(barco->coluna - 1 >= 0 && mapa->matriz[barco->linha][barco->coluna - 1] == '.')
			{
				mapa->matriz[barco->linha][barco->coluna] = 'T';
				mapa->matriz[barco->linha][barco->coluna - 1] = 'B';
				barco->coluna--;
				naoRemou = 0;
			}
		break;
		
		case 'd':
			if(barco->coluna + 1 >= 0 && mapa->matriz[barco->linha][barco->coluna + 1] == '.')
			{
				mapa->matriz[barco->linha][barco->coluna] = 'T';
				mapa->matriz[barco->linha][barco->coluna + 1] = 'B';
				barco->coluna++;
				naoRemou = 0;
			}	
		break;								
	}

	#ifdef DEBUG
	debug_message("Prestes a retornar %d\n", naoRemou);
	#endif
	return naoRemou;
}

void posiciona_barco(pMapa mapa, pBarco barco)
{
	int pos;
	#ifdef DEBUG
	static char funcname[] = "Chamado: posiciona_barco(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	for (pos = 0; pos < mapa->largura && mapa->matriz[0][pos] != 'B'; ++pos)
		; /* Procura um barco já inserido no mapa.*/
	
	if (pos < mapa->largura)
	{
		#ifdef DEBUG
		debug_message("Encontrado um barco pré-definido\n");
		#endif
		mapa->matriz[0][pos] = '.';
	}	

	printf("Escolha uma coluna para posicionar o barco. ");
	printf("Entre com uma coluna válida: entre 0 e %d\n", (mapa -> largura - 1));
	fscanf(stdin, " %d", &pos);
	
	while(pos < 0 && pos >= mapa->largura && mapa->matriz[0][pos] != '.')
	{
		printf("Posição inválida! Tente novamente\n");
		fscanf(stdin, " %d", &pos);	
	}
	mapa -> matriz[0][pos] = 'B';
	barco->linha = 0;
	barco->coluna = pos;

	#ifdef DEBUG
	debug_message("Prestes a retornar\n");
	#endif
}
