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
	int valido = 0;
	char mov;

	#ifdef DEBUG
	static char funcname[] = "Chamado: rema_barco(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	printf("Mova o barco\n");
	printf("(b)baixo  (e)esquerda  (d)direita\n");
	fscanf(stdin, "%c", &mov);

	printf("mov %c\n", mov);

	switch(mov)
	{
		case 'b':	if(barco->linha + 1 < mapa->altura && mapa->matriz[barco->linha + 1][barco->coluna] == '.')
					{
						valido = 1;
						mapa->matriz[barco->linha + 1][barco->coluna] = 'B';
						barco->linha++;
					}
					break;
		case 'e':	if(barco->coluna - 1 >= 0 && mapa->matriz[barco->linha][barco->coluna - 1] == '.')
					{
						valido = 1;
						mapa->matriz[barco->linha][barco->coluna - 1] = 'B';
						barco->coluna--;
					}
					break;
		case 'd':	if(barco->coluna + 1 >= 0 && mapa->matriz[barco->linha][barco->coluna + 1] == '.')
					{
						valido = 1;
						mapa->matriz[barco->linha][barco->coluna + 1] = 'B';
						barco->coluna++;
					}	
					break;								
	}
	if(valido)
		mapa->matriz[barco->linha][barco->coluna] = 'T';

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

/** Sucesso em posicionar o barco retorna 0
 */
int posiciona_barco(pMapa mapa, pBarco barco)
{
	int pos, valido;

	#ifdef DEBUG
	static char funcname[] = "Chamado: posiciona_barco(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	printf("Escolha uma coluna para posicionar o barco. ");
	printf("Entre com uma coluna valida: entre 0 e %d\n", (mapa -> largura - 1));
	fscanf(stdin, "%d", &pos);
	if(pos <= 0 && pos >= mapa -> largura)
		valido = 0;
	while(!valido && mapa -> matriz[0][pos] != '.')
	{
		printf("Posicao inválida! Tente novamente\n");
		fscanf(stdin, "%d", &pos);
		if(pos >= 0 && pos <= mapa -> largura) valido = 1;
	}
	mapa -> matriz[0][pos] = 'B';
	barco->linha = 0;
	barco->coluna = pos;

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
