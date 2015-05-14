/**
  * @file 
  * @brief Arquivo contendo os escopos das funções e estruturas que lidam com operações eventuais
  */
 
#include <stdio.h>

#ifndef EVENTOS_H
#define EVENTOS_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct Mapa;  /* Dependencias*/
struct Barco;
#endif

/**
  * Função inline.<p>
  * Sorteia com a seguinte regra matemática: <p>
  * \f$sorteia(k) = \frac{rand()}{1 + R_{max}}\cdot k\f$
  */
#define SORTEIA(k) ((int)((rand()/(RAND_MAX+1.0))*(k)))

/**
  * Determina os três tiros a serem disparados pelo computador, a cada remada. Imprime as
  * mensagens correspondentes ao efeito de cada tiro, e atualiza a matriz representando o mapa.
  *
  * @param mapa		Mapa alocado dinamicamente.
  * @param arquivo	Arquivo para escrever os logs.
  * @author		Rodrigo, Thais
  * @return 		0, se o barco não foi atingido. <p>
  *			1, caso contrário.
  */
int dispara_tiros(struct Mapa* mapa, FILE* arquivo);

/**
  * Determina as coordenadas de um tiro, utilizando a função sorteia.
  *
  * @param mapa		Mapa alocado dinamicamente.
  * @param i		Linha sorteada passada por referência.
  * @param j		Coluna sorteada passada por referência.
  *
  */
void coordenadas_tiro(const struct Mapa* mapa, int* i, int* j);

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
 * @param i		i-ésima linha.
 * @param j		j-ésima coluna.
 * @author		Rodrigo, Thais
 * @param arquivo	Arquivo para escrever os logs.
 * @return		Caractere correspondente ao alvo atingido.
 */
char identifica_alvo_atingido(struct Mapa* mapa, int i, int j, FILE* arquivo);

/**
 * Afunda totalmente a embarcacao atingida por um tiro; ou seja, atribui '∗' a todas as posições
 * da matriz ocupadas por essa embarcaçao.
 * funcao chamada por identifica_alvo_atingido()
 * a funcao acima deve passar a posicao que o tiro atingiu e o tipo de embarcação atingida
 * Afunda recursivamente: afunda posição atual e busca pelas partes adjacentes
 * Obs: afunda todos os tipos de embarcação, exceto o submarino
 *
 * @param mapa		Mapa alocado dinamicamente
 * @param tipo		Tipo de embarcação atingida
 * @param linha		Linha
 * @param coluna	Coluna
 * @author		Thais
 */
void afunda_embarcacao(struct Mapa* mapa, char tipo, int linha, int coluna);

/**
  * Verifica se o jogo foi ganho.
  * @param mapa		Mapa alocado dinamicamente.
  * @param barco	Barquinho do jogador.
  * @return		1, se o jogo foi ganho.<p>
  *			0, caso contrário.
  * @author		Giuliano
  */
int ganhou_jogo(const struct Mapa* mapa, const struct Barco* barco);

#endif
