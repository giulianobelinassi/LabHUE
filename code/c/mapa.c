/*
  * @file 
  * @brief Arquivo implementando funções que lidam com operações com mapas
  */
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

pMapa novo_mapa(int M, int N)
{
	int i;
	Mapa_t* mapa;
	
	mapa = malloc(sizeof(Mapa_t));
	if (mapa == NULL)
		return NULL; /*Não há memória suficiente no sistema.*/
	
	mapa->altura = M;
	mapa->largura = N;
	
	mapa->matriz = malloc(M*sizeof(char*));
	
	if(mapa->matriz == NULL) /* Falha na alocação.*/
	{
		free(mapa);
		return NULL; /* Não há memória suficiente no sistema.*/
	}
		
	for (i = 0; i < M; ++i)
	{
		mapa->matriz[i] = malloc(N*sizeof(char));
		if (mapa->matriz[i] == NULL) /* Falha na alocação.*/
		{
			int j = 0;
			while (j < i)
				free(mapa->matriz[j++]);
			
			free(mapa->matriz);
			free(mapa);
						
			return NULL;
		}
		memset(mapa->matriz[i], '.', N*sizeof(char)); /* Preenche a linha com '.'*/
	}
	
	return mapa;
}

void destroi_mapa(Mapa_t** mapa)
{
	int i;
	int M;
	
	if (mapa == NULL || *mapa == NULL)
		return; /* Não há nada para destruir*/
	
	M = (*mapa)->altura;
	for (i = 0; i < M; ++i)
		free((*mapa)->matriz[i]);
	
	free((*mapa)->matriz);
	free(*mapa);
	
	*mapa = NULL;
	
}

int leia_mapa(Mapa_t** mapa, const char* arquivo)
{
	FILE* file;
	static char linhastr[20];
	static char colunastr[20];
	int M, N;
	int i, j=0;
	char c;
	
	if (arquivo == NULL || mapa == NULL)
		return 4; /* Função chamada de forma incorreta*/
	
	file = fopen(arquivo, "r");
	if (file == NULL)
		return 2; /** Erro: Mapa não encontrado.*/
	
	for (i = 0; (c = fgetc(file)) != EOF && c != ' '; ++i)
		linhastr[i] = c;
	linhastr[++i] = '\0'; /* Adiciona o NULL character no final da string*/
	
		
	for (i = 0; (c = fgetc(file)) != EOF && c != ' ' &&  c != '\n'; ++i)
		colunastr[i] = c;
	colunastr[++i] = '\0'; /* Adiciona o NULL character no final da string*/
	
	
	M = atoi(linhastr);
	N = atoi(colunastr);
	
	*mapa = novo_mapa(M, N);
	if (*mapa == NULL)
	{
		fclose(file);
		return 3; /* Erro de alocação*/
	}
	
	(*mapa)->altura = M;
	(*mapa)->largura = N;
	
	if (c != '\n') /* Se houver lixo no cabeçalho*/
	{	
		while ((c = fgetc(file)) != EOF && c != '\n')
			; /* Ignora todos os espaços até o fim da linha.*/
	}
	
	/*
	 * Aqui começa os dados da primeira linha do mapa (O cabeçalho já foi processado).
	 */
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			c = fgetc(file);
			
			if (c == EOF) /* Nesse caso, talvez encontramos o fim do arquivo sem a quantidade*/
			      break;  /* total de dados necessária para prosseguir com o programa. */ 
			
			if (c != ' ') /* Ignoro todos os espaços*/
				(*mapa)->matriz[i][j] = c;
		}
		
		while ((c = fgetc(file)) != '\n') /* Ignora todos os espaços até o fim da linha.*/
			if (c == EOF)
				break;
	}
	
	fclose(file);
	
	if (i != M || j != N)
		return 1; /* Mapa corrompido?*/
	
	return 0;
}

void escreva_mapa_tela(const Mapa_t* mapa)
{
	int i, j;
	int M, N;
	
	if (mapa == NULL)
	{	
		fputs("NULL\n", stdout);
		return; /* Função chamada de forma incorreta*/	
	}
	
	M = mapa->altura;
	N = mapa->largura;

	fputs("     " ,stdout);
	
	for (i = 0; i < N; ++i)
		fprintf(stdout, "%d ", i);
	putc('\n', stdout);
	
	for (i = 0; i < M; ++i)
	{
		int margemi = i;
		int log10_i;
		
		fprintf(stdout, "%d", i);
		
		for (log10_i = 0; (margemi/=10) != 0; ++log10_i)
			; /* Ajusta a saída para melhor se encaixar com o número.*/
		
		log10_i = 4 - log10_i;
		while (log10_i-- > 0)
			putc(' ', stdout);
		
		
		for (j = 0; j < N; ++j)
		{
			char c = mapa->matriz[i][j]; 
			int margemj = j;
			
			while ((margemj/=10) != 0) /* Ajusta a saída para melhor se encaixar com o número*/
				putc(' ', stdout);
			
			if (c == 'T' || c == 'B' || c == '=' || c == '*' || c == '+' || c == '!') 
				fprintf(stdout, "%c ", c);
			else
				fprintf(stdout, "- ");
		}
		putc('\n', stdout);
	}
}

int escreva_mapa_arquivo(const Mapa_t* mapa, FILE* arquivo)
{	
	int M, N;
	int i, j;

	if (arquivo == NULL)
		return 2; /* Erro: Arquivo NULL.*/

	
	M = mapa->altura;
	N = mapa->largura;

	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
			putc(mapa->matriz[i][j], arquivo);
		putc('\n', arquivo);
	}
	
	return 0;
}
