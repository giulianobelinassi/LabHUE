/** @file
  * @brief		Arquivo lidando com os gráficos.
  */

#ifndef GRAFICOS_H
#define GRAFICOS_H


/*Dependências*/
struct Mapa;
struct Barco;
struct Win; /* Alguma biblioteca compatível com xwc do Gubitoso.*/
/**/

/** Largura em pixels de uma cédula*/
#define DIM_X    48
/** Altura em pixels de uma cédula*/
#define DIM_Y    48

/** Quantidade de orientações do barco.*/
#define FRAMES_BARCO 3

/** Struct guardando todos os possíveis gráficos (Conjunto de buffers).*/
struct Graficos
{
	struct Win* barco[FRAMES_BARCO]; /**< Os 3 frames do barco */
	struct Win* agua;                /**< Cédula água          */
	struct Win* destroco;            /**< Cédula destroço      */
	struct Win* onda;                /**< Cédula onda          */
	struct Win* rastro;              /**< Cédula rastro        */
};

typedef struct Graficos Graficos_t;
typedef struct Graficos *pGraficos_t;
typedef struct Graficos *pGraficos;

/**
  * Carrega as imagens em .xpm para uma estrutura com os buffers.
  * @param graficos		Conjunto de buffers;
  * @return			0, se sucesso.
  */
int carrega_graficos(struct Graficos* graficos);

/** Carrega todos os recursos, cria uma janela com as dimensões do mapa,
  * preenche-o com água, e retorna a janela.
  * @param graficos		Conjunto de buffers gráficos.
  * @param mapa			Mapa.
  * @return 			Janela.
  */
struct Win* inicializa_tela(struct Graficos* graficos, const struct Mapa* mapa);

/** Desenha uma cédula na tela.
  * @param win			Janela.
  * @param mapa			Mapa.
  * @param graficos		Conjunto de gráficos.
  * @param variacao		Variação gráfica (Qual barco imprimir?)
  * @param i			Linha da matriz.
  * @param j			Coluna da matriz.
  */
void desenha_celula_tela(struct Win* win, const struct Mapa* mapa, const struct Graficos* graficos, int variacao, int i, int j);

/**
 * Converte coordenadas matriciais para cartesianas.
 * param mapa		As dimensões do mapa são necessárias.
 * @param i		Linha em coordenada matricial.
 * @param j		Coluna em coordenada matricial.
 * @param x		Abscissa que será escrita (Referência).
 * @param y		Ordenada que será escrita (Referência).
 */
void matricial_para_cartesiana(const struct Mapa* mapa, int i, int j, int* x, int* y);

/**
 * Converte coordenadas matriciais para cartesianas.
 * param mapa		As dimensões do mapa são necessárias.
 * @param i		Linha que será escrita (Referência).
 * @param j		Coluna que será escrita (Referência).
 * @param x		Abscissa.
 * @param y		Ordenada.
 */
void cartesiana_para_matricial(const struct Mapa* mapa, int* i, int* j, int x, int y);

/**
 * Desenha o mapa com o barco numa janela.
 * @param mapa		Mapa alocado dinamicamente.
 * @param barco		Barco
 */
void desenha_mapa_tela(struct Win* win, const struct Mapa* mapa, const struct Barco* barco);

#endif
