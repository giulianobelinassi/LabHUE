/**
  * @file 
  * @brief Arquivo contendo os escopos das funções e estruturas que lidam com operações navais
  */
 
#ifndef BARCO_H
#define BARCO_H

#include "mapa.h"

/**
  * Abstração de barco.
  */
typedef struct
{
	int linha;  /**< Linha atual do barco.*/
	int coluna; /**< Coluna atual do barco.*/
} Barco, *pBarco;

/**
  * Movimenta o barco horizontalmente ou verticalmente, dependendo
  * da entrada do teclado, tomando o cuidado de não colidir com outra
  * embarcação. As posições anteriormente ocupadas pelo barco são
  * marcadas com 'T', e a posição atual com 'S'.
  * @param mapa 	Mapa alocado dinamicamente.
  * @param barco	Referência ao barco.
  * @return		Sucesso?
  */
int rema_barco(Mapa* mapa, Barco* barco);

/**
  * Lê do teclado a posição inicial do barco e marca com 'B' esta posição
  * na matriz. Note que uma posição já ocupada por outro barco é inválida.
  * @param mapa		Mapa alocado dinamicamente
  * @param barco	Referência ao barco.
  * @param i		i-ésima linha da matriz
  * @param j		j-ésima coluna da matriz.
  * @return 		Sucesso?
  */
int posiciona_barco(Mapa* mapa, Barco* barco);

#endif