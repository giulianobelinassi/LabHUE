/**
  * @file 
  * @brief Arquivo contendo os escopos das funções e estruturas que lidam com operações eventuais
  */
 

#ifndef EVENTOS_H
#define EVENTOS_H

#include "mapa.h"

/**
  * Função inline. 
  *
  * Sorteia com a seguinte regra matemática:
  *
  * 1 + (rand()/RAND_MAX+1.0))*k
  *
  */
#define sorteia(k) ((int)(1 + (rand()/RAND_MAX+1.0))*k)

/**
  * Determina os três tiros a serem disparados pelo computador, a cada remada. Imprime as
  * mensagens correspondentes ao efeito de cada tiro, e atualiza a matriz representando o mapa.
  *
  * @param mapa		Mapa alocado dinamicamente.
  * @return		Sucesso?
  */
int dispara_tiros(Mapa* mapa);

/**
  * Determina as coordenadas de um tiro, utilizando a função sorteia.
  *
  * @param i		Linha sorteada passada por referência.
  * @param j		Coluna sorteada passada por referência.
  * @return 		Sucesso?
  */
int coordenadas_tiro(int* i, int* j);

/**
 * Imprime as coordenadas de um tiro e a mensagem correspondente ao efeito desse tiro.
 * Se o tiro acerta uma embarcação, especifica-se o seu tipo.
 * Além disso, atualiza na matriz a posição atingida pelo tiro, com um dos seguintes caracteres:
 * '=' se o tiro atingiu a água;
 ∗ '*' se o tiro atingiu alguma embarcacão;
 * '!' se o tiro atingiu o barco;
 * '+' se o tiro atingiu alguma posicão do caminho percorrido pelo barco, exceto a posisão atual.
 *
 * @param mapa		Mapa alocado dinamicamente.
 * @return		A ser especificado.
 */
int identifica_alvo_atingido(Mapa* mapa);

/**
 * Afunda totalmente a embarcacao atingida por um tiro; ou seja, atribui '∗' a todas as posições
 * da matriz ocupadas por essa embarcaçao.
 *
 * @param mapa		Mapa alocado dinamicamente
 * @return		A ser especificado.
 */
int afunda_embarcacao(Mapa* mapa);

/**
  * Verifica se o jogo foi ganho.
  * @param mapa		Mapa alocado dinamicamente.
  * @param barco	Barquinho do jogador.
  * @return		Sucesso?
  */
int ganhou_jogo(const Mapa* mapa, const Barco* barco);

#endif

