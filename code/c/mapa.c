/**
  * @file 
  * @brief Arquivo implementando funções que lidam com operações com mapas
  */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mapa.h"

#ifdef DEBUG
#include "debug.h"
#endif

#define MAPDELIMITER '|'

pMapa novo_mapa(int M, int N)
{
	int i;
	Mapa* mapa;
	#ifdef DEBUG
	static char funcname[] = "Em: novo_mapa(%d, %d)\n";
	debug_message(funcname, M, N);
	#endif
	
	mapa = malloc(sizeof(Mapa));
	if (mapa == NULL)
	{
		#ifdef DEBUG
		debug_message("Erro: Pouca memória. Prestes a retornar NULL");
		#endif
		return NULL; /**< Não há memória suficiente no sistema.*/
	}
	
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

int leia_mapa(Mapa** mapa, const char* arquivo)
{
	FILE* file;
	static char linhastr[20];
	static char colunastr[20];
	int M, N;
	int i, j=0;
	char c;
	
	#ifdef DEBUG
	static const char funcname[] = "Em: leia_mapa(%p, %s)\n";
	debug_message(funcname, mapa, arquivo);
	#endif
	
	if (arquivo == NULL || mapa == NULL || *mapa == NULL)
	{	
		#ifdef DEBUG
		debug_message("Erro: Chamaram-me errado. Prestes a retornar 4\n");
		#endif
		return 4; /**<Função chamada de forma incorreta*/
	}
	
	file = fopen(arquivo, "r");
	if (file == NULL)
	{
		#ifdef DEBUG
		debug_message("Erro: Arquivo não encontrado. Prestes a retornar NULL\n");
		#endif
		return 2; /**< Erro: Mapa não encontrado.*/
	}
	
	for (i = 0; (c = fgetc(file)) != EOF && c != ' '; ++i)
		linhastr[i] = c;
	linhastr[++i] = '\0'; /**< Adiciona o NULL character no final da string*/
	
		
	for (i = 0; (c = fgetc(file)) != EOF && c != ' '; ++i)
		colunastr[i] = c;
	colunastr[++i] = '\0'; /**< Adiciona o NULL character no final da string*/
	
	
	M = atoi(linhastr);
	N = atoi(colunastr);
	
	*mapa = novo_mapa(M, N);
	if (*mapa == NULL)
	{
		fclose(file);
		#ifdef DEBUG
		debug_message("Erro na alocação do mapa. Prestes a fechar o arquivo...\n");
		#endif
		return 3; /**< Erro de alocação*/
	}
	
	(*mapa)->altura = M;
	(*mapa)->largura = N;
	
	while ((c = fgetc(file)) != EOF && c != '\n')
		; /**< Ignora todos os espaços até o fim da linha.*/
	
	/**< Aqui começa os dados da primeira linha do mapa (O cabeçalho já foi processado).*/
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			c = fgetc(file);
			
			if (c == EOF) /**< Nesse caso, talvez encontramos o fim do arquivo sem a quantidade total*/
			      break;  /**< de dados necessária para prosseguir com o programa. */ 
			
			if (c != ' ') /**< Ignoro todos os espaços*/
				(*mapa)->matriz[i][j] = c;
		}
		
		while ((c = fgetc(file)) != '\n') /**< Ignora todos os espaços até o fim da linha.*/
			if (c == EOF)
				break;
	}
	
	if (i != M || j != N)
	{
		#ifdef DEBUG
		debug_message("WARNING: Mapa corrompido?\n");
		#endif
		return 1; /**<Mapa corrompido?*/
	}
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

void escreva_mapa_tela(const Mapa* mapa)
{
	int i, j;
	int M, N;
	#ifdef DEBUG
	static char funcname[] = "Em: escreva_mapa_tela(%p)\n";
	debug_message(funcname, mapa);
	#endif	
	
	if (mapa == NULL)
	{	
		#ifdef DEBUG
		debug_message("Erro: Chamaram-me errado. Prestes a retornar 4\n");
		#endif
		return 4; /**<Função chamada de forma incorreta*/	
	}
	
	M = mapa->altura;
	N = mapa->largura;
/*	
	fputs(stdout, "   ");
	
	for (i = 0; i < N; ++i)
		fprintf(stdout, "%d ", i);
	
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
	}
*/
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
