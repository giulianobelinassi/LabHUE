/**
  * @file 
  * @brief Arquivo implementando funções que lidam com operações com mapas
  */
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

#ifdef DEBUG
#include "debug.h"
#endif

pMapa novo_mapa(int M, int N)
{
	int i;
	Mapa* mapa;
	#ifdef DEBUG
	static char funcname[] = "Em: novo_mapa(%d, %d)\n";
	debug_message(funcname, M, N);
	#endif
	
	mapa = malloc(sizeof(Mapa));
	mapa->altura = M;
	mapa->largura = N;
	
	mapa->matriz = malloc(M*sizeof(char*));
	
	if(mapa->matriz == NULL) /**< Falha na alocação.*/
	{
		free(mapa);
		#ifdef DEBUG
		debug_message("Erro: Pouca memória. Prestes a retornar NULL");
		#endif
		return NULL; /**< Não há memória suficiente no sistema.*/
	}
		
	for (i = 0; i < M; ++i)
	{
		mapa->matriz[i] = malloc(N*sizeof(char));
		if (mapa->matriz[i] == NULL) /**< Falha na alocação.*/
		{
			int j = 0;
			while (j < i)
				free(mapa->matriz[j++]);
			
			free(mapa->matriz);
			free(mapa);
			
			#ifdef DEBUG
			debug_message("Erro: Pouca memória. Prestes a retornar NULL");
			#endif
			
			return NULL;
		}
		memset(mapa->matriz[i], '.', N*sizeof(char)); /**< Preenche a linha com '.'*/
	}
	
	#ifdef DEBUG
	debug_message("Prestes a retornar apontador para mapa (%p)\n", mapa);
	#endif
	return mapa;
}

void destroi_mapa(Mapa** mapa)
{
	int i;
	int M;
	#ifdef DEBUG
	static char funcname[] = "Em: destroi_mapa(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	if (mapa == NULL || *mapa == NULL)
		return; /**< Não há nada para destruir*/
	
	M = (*mapa)->altura;
	for (i = 0; i < M; ++i)
		free((*mapa)->matriz[i]);
	
	free((*mapa)->matriz);
	free(*mapa);
	
	*mapa = NULL;
	
	#ifdef DEBUG
	debug_message("Prestes a retornar\n");
	#endif
}

int leia_mapa(Mapa* mapa, const char* arquivo)
{
	#ifdef DEBUG
	static char funcname[] = "Em: leia_mapa(%p, %s)\n";
	debug_message(funcname, mapa, arquivo);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

void escreva_mapa_tela(const Mapa* mapa)
{
	#ifdef DEBUG
	static char funcname[] = "Em: escreva_mapa_tela(%p)\n";
	debug_message(funcname, mapa);
	#endif	

	#ifdef DEBUG
	debug_message("Prestes a retornar\n");
	#endif
}

int escreva_mapa_arquivo(const Mapa* mapa, const char* arquivo)
{	
	#ifdef DEBUG
	static char funcname[] = "Em: escreva_mapa_arquvo(%p, %s)\n";
	debug_message(funcname, mapa, arquivo);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
