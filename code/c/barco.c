/*
  * @file 
  * @brief Arquivo implementando as funções que lidam com operações navais
  */

#include "barco.h"
#include "mapa.h"
#include <stdio.h>

#ifndef NO_GUI 
#include "graficos.h"
#endif

/**
  * Verifica se a posição é válida. Ou seja, se não há uma embarcação
  * na posição. Quando uma embarcação é afundada, ela abre caminho para
  * o barco passar.
  * @param		c caracter correspondente a situação da posição.
  * @return		1 se válido, 0 caso contrário. 
  */
static int p_valida(char c)
{
	if (c == 'T' || c == '=' || c == '*' || c == '+' || c == '!' || c == '.')
		return 1;
	return 0;
}

int rema_barco(struct Win* win, pMapa mapa, pBarco barco)
{
	char mov;
	int naoRemou = 1;
	
	printf("Mova o barco\n");
	printf("(b)baixo  (e)esquerda  (d)direita (c)cima\n");

	#ifndef NO_GUI
	desenha_mensagem_janela(win, "Mova o Barco usando as setas\n");
	mov = pega_seta_janela(win);
	#else
	fscanf(stdin, " %c", &mov);
	#endif

	switch(mov)
	{
		case 'b':
			barco->bussola = 'b';
			if(barco->linha + 1 < mapa->altura && p_valida(mapa->matriz[barco->linha + 1][barco->coluna]))
			{
				mapa->matriz[barco->linha][barco->coluna] = 'T';
				mapa->matriz[barco->linha + 1][barco->coluna] = 'B';
				barco->linha++;
				naoRemou = 0;
			}
		break;
		
		case 'e':
			barco->bussola = 'e';
			if(barco->coluna - 1 >= 0 && p_valida(mapa->matriz[barco->linha][barco->coluna - 1]))
			{
				mapa->matriz[barco->linha][barco->coluna] = 'T';
				mapa->matriz[barco->linha][barco->coluna - 1] = 'B';
				barco->coluna--;
				naoRemou = 0;
			}
		break;
		
		case 'd':
			barco->bussola = 'd';
			if(barco->coluna + 1 >= 0 && p_valida(mapa->matriz[barco->linha][barco->coluna + 1]))
			{
				mapa->matriz[barco->linha][barco->coluna] = 'T';
				mapa->matriz[barco->linha][barco->coluna + 1] = 'B';
				barco->coluna++;
				naoRemou = 0;
			}	
		break;
		
		case 'c':
			barco->bussola = 'c';
			if(barco->linha - 1 >= 0 && p_valida(mapa->matriz[barco->linha - 1][barco->coluna]))
			{
				mapa->matriz[barco->linha][barco->coluna] = 'T';
				mapa->matriz[barco->linha - 1][barco->coluna] = 'B';
				barco->linha--;
				naoRemou = 0;
			}	
		break;			
	}

	return naoRemou;
}

void posiciona_barco(pMapa mapa, pBarco barco)
{
	int pos;
	
	for (pos = 0; pos < mapa->largura && mapa->matriz[0][pos] != 'B'; ++pos)
		; /* Procura um barco já inserido no mapa.*/
	
	if (pos < mapa->largura) /* Se encontrou*/
		mapa->matriz[0][pos] = '.';
	

	printf("Escolha uma coluna para posicionar o barco. ");
	printf("Entre com uma coluna válida: entre 0 e %d\n", (mapa -> largura - 1));
	
	while(1)
	{
		fscanf(stdin, " %d", &pos);

		if (0 <= pos && pos < mapa->largura && mapa->matriz[0][pos] == '.')		
			break;
			
		printf("Posição inválida! Tente novamente\n");
	}
	mapa -> matriz[0][pos] = 'B';
	barco->linha = 0;
	barco->coluna = pos;
	barco->bussola = 'b';
}
