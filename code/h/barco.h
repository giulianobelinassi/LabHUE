/**
  * @file 
  * @brief Arquivo contendo os escopos das funções e estruturas que lidam com operações navais
  */
 
#ifndef BARCO_H
#define BARCO_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct Mapa; /* Dependencia*/
#endif

/**
  * Abstração de barco.
  */
struct Barco
{
	int linha;  /**< Linha atual do barco.*/
	int coluna; /**< Coluna atual do barco.*/
};

/* Notações alternativas para evitar possíveis verborragias.*/
typedef struct Barco Barco_t,   /** Typedef padrão*/
                     *pBarco_t, /** Typedef apontador*/
                     *pBarco;   /** Typedef apontador*/


/**
  * Movimenta o barco horizontalmente ou verticalmente, dependendo
  * da entrada do teclado, tomando o cuidado de não colidir com outra
  * embarcação. As posições anteriormente ocupadas pelo barco são
  * marcadas com 'T', e a posição atual com 'B'.
  * @param mapa 	Mapa alocado dinamicamente.
  * @param barco	Referência ao barco.
  * @return		1, se o barco não se moveu. <p>
  *			0, se o barco se moveu.
  */
int rema_barco(struct Mapa* mapa, struct Barco* barco);

/**
  * Lê do teclado a posição inicial do barco e marca com 'B' esta posição
  * na matriz. Note que uma posição já ocupada por outro barco é inválida.<p>
  * Note também que se o mapa conter um barco predefinido, então ele utilizará esse.
  * @param mapa		Mapa alocado dinamicamente
  * @param barco	Referência ao Barco.
  */
void posiciona_barco(struct Mapa* mapa, struct Barco* barco);

#endif
