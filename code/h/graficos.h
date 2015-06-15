/** @file
  * @brief		Arquivo lidando com os gráficos.
  */

#ifndef GRAFICOS_H
#define GRAFICOS_H

#ifndef NO_GUI /** Compilamos sem interface gráfica.*/

/*Dependências*/
struct Mapa;
struct Barco;
struct Win; /* Alguma biblioteca compatível com xwc do Gubitoso.*/
/**/

/** Largura em pixels de uma cédula. Note que a contagem inicia-se de zero.*/
#define DIM_X    47 

/** Altura em pixels de uma cédula*/
#define DIM_Y    47 

/** Quantidade de orientações do barco.*/
#define FRAMES_BARCO 4 

/** Possíveis orientações do Barco.*/
enum {BARCO_E, BARCO_B, BARCO_D, BARCO_C} FBARCO;

/** Struct guardando todos os possíveis gráficos (Conjunto de buffers).*/
struct Graficos
{
	struct Win* barco[FRAMES_BARCO]; /**< Os 4 frames do barco */
	struct Win* agua;                /**< Cédula água          */
	struct Win* destroco;            /**< Cédula destroço      */
	struct Win* rastro;              /**< Cédula rastro        */
	struct Win* tiro;                /**< Cédula tiro          */
	struct Win* onda;                /**< Cédula onda          */
};

typedef struct Graficos Graficos_t;
typedef struct Graficos *pGraficos_t;
typedef struct Graficos *pGraficos;

/**
  * Carrega as imagens em .xpm para uma estrutura com os buffers.
  * @param win			Janela.
  * @return			Buffer com gráficos.
  */
struct Graficos* carrega_graficos(struct Win* win);

/**
  * Apaga o buffer.
  * @param graficos		Conjunto de buffers passado por referência;
  */
void destroi_graficos(struct Graficos** graficos);

/** Carrega todos os recursos, cria uma janela com as dimensões do mapa,
  * preenche-o com o conteúdo da matriz, e retorna a janela.
  * @param graficos		Referência a um conjunto de buffers gráficos.
  				Note que ele será criado dentro da função,
  				então temos uma passagem por referência.
  * @param mapa			Mapa.
  * @return 			Janela.
  */
struct Win* inicializa_janela(struct Graficos** graficos, const struct Mapa* mapa);

/** Desenha uma cédula na tela.
  * @param win			Janela.
  * @param mapa			Mapa.
  * @param graficos		Conjunto de gráficos.
  * @param variacao		Variação gráfica (Qual barco imprimir?)
  * @param i			Linha da matriz.
  * @param j			Coluna da matriz.
  */
void desenha_cedula_janela(struct Win* win, const struct Graficos* graficos, const struct Mapa* mapa, int variacao, int i, int j);

/**
  * Desenha o barco na janela win.
  * @param win			Janela.
  * @param graficos		Graficos.
  * @param barco		Barco.
  */
void desenha_barco_janela(struct Win* win, const struct Graficos* graficos, const struct Barco* barco);


/**
 * Desenha o mapa com o barco numa janela.
 * @param mapa			Mapa alocado dinamicamente.
 * @param graficos		Graficos.
 * @param barco			Barco.
 */
void desenha_mapa_janela(struct Win* win, struct Graficos* graficos, const struct Mapa* mapa, const struct Barco* barco);

/**
  * Desenha uma mensagem no canto superior esquerdo da janela.
  * @param win			Janela.
  * @param msg			Mensagem.
  */
void desenha_mensagem_janela(struct Win* win, const char* msg);

/**
  * Aguarda o jogador pressionar uma seta.
  * @param win			Janela.
  * @return			'e', se Seta-esquerda pressionada. <p>
  *				'b', se Seta-baixo pressionada. <p>
  *		    		'd', se Seta-direita pressionada. <p>
  *				'c', se Seta-cima pressionada.
  *				'=', se ENTER pressionado.
  */
char pega_seta_janela(struct Win* win);


/**
  * Destroi a janela apontada por win.
  * @param win 			Janela.
  */
void destroi_janela(struct Win* win);


/**
  * Exibe a janela apontada por win.
  * @param win 			Janela.
  */
void exibe_janela(struct Win* win);


/**
  * Esconde a janela apontada por win.
  * @param win	 		Janela.
  */
void esconde_janela(struct Win* win);

#endif
#endif
