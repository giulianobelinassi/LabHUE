/**
  * @file 
  * @brief Arquivo contendo os escopos e estruturas que lidam com operações com mapas
  */
 
#ifndef MAPA_H
#define MAPA_H

/**
 * Abstração de mapa. Note que o mesmo deverá sempre ser
 * alocado dinamicamente.
 *
 */
typedef struct
{
	int largura;    /**< Largura do mapa iniciando de 1.*/
	int altura;     /**< Altura do mapa iniciando de 1.*/
	char** matriz;  /**< Matriz do mapa. denote MATRIZ[linha][coluna]*/
	
} Mapa, *pMapa;

/** 
  * Cria um mapa alocado dinamicamente.
  * @param M		Altura do mapa a ser criado.
  * @param N		Largura do mapa a ser criado.
  * @return		Apontador para o mapa.
  */
pMapa novo_mapa(int M, int N);

/**
  * Destroi um mapa apontado por <b>mapa</b>
  * @param mapa		Referência ao mapa a ser destruido.
  * 
  */
void destroi_mapa(Mapa** mapa);

/**
 * Abre o <b>mapa</b> especificado em <b>arquivo</b>
 * @param mapa		Mapa a ser aberto. Passagem por referência.
 * @param arquivo	String com o caminho do arquivo.
 * @return		Sucesso?
 */
int leia_mapa(Mapa** mapa, const char* arquivo);

/**
 * Escreve mapa na tela
 * @param mapa 		Mapa alocado dinamicamente.
 */
void escreva_mapa_tela(const Mapa* mapa);

/**
 * Escreve um mapa especificado por <b>arquivo</b>
 * @param mapa 		Mapa alocado dinamicamente.
 * @param arquivo	String com o caminho do arquivo.
 * @return		Sucesso?
 */
int escreva_mapa_arquivo(const Mapa* mapa, const char* arquivo);

#endif

