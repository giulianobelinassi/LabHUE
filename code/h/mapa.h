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
  * @author		Giuliano
  */
pMapa novo_mapa(int M, int N);

/**
  * Destroi um mapa apontado por <b>mapa</b>
  * @param mapa		Referência ao mapa a ser destruido.
  * @author		Giuliano 
  */
void destroi_mapa(Mapa** mapa);

/**
 * Abre o <b>mapa</b> especificado em <b>arquivo</b>
 * @param mapa		Mapa a ser aberto. Passagem por referência.
 * @param arquivo	String com o caminho do arquivo.
 * @return		0, se sucesso. <p>
 *			1, se o mapa estiver corrompido (WARNING) <p>
 *			2, se o mapa não foi encontrado <p>
 *			3, se houver erro na alocação <p>
 *			4, se a função não foi chamada corretamente.
 * @author		Giuliano
 */
int leia_mapa(Mapa** mapa, const char* arquivo);

/**
 * Escreve mapa na tela
 * @param mapa 		Mapa alocado dinamicamente.
 * @author		Giuliano
 */
void escreva_mapa_tela(const Mapa* mapa);

/**
 * Escreve um mapa especificado por <b>arquivo</b>
 * @param mapa 		Mapa alocado dinamicamente.
 * @param arquivo	String com o caminho do arquivo.
 * @return		0, se sucesso.
 *			2, se acesso negado.
 * @author		Giuliano
 */
int escreva_mapa_arquivo(const Mapa* mapa, const char* arquivo);

#endif

