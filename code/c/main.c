/*
  *@file Lógica principal
  */
#include "mapa.h"
#include "barco.h"
#include "eventos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BECO_SEM_SAIDA 3 /**< Quantidade de jogadas sem o barco se mover até que o jogo pare.*/


/**
  * Recebe via argumentos o mapa e opcionalmente o arquivo de saída.
  * @brief		Lógica principal do programa
  * @return 		0, se sucesso.
  */
int main(int argc, char* argv[])
{
	const static char ARQ_SAIDA[] = "saida.txt";
	const static char ATINGIDO[]  = "Seu barco foi atingido!\n";
	const static char PRESO[]     = "Seu barco ficou preso!\n";
	const static char GANHOU[]    = "Você Ganhou!";

	Mapa_t* mapa;
	Barco_t barco;
	
	const char* caminho_mapa;
	const char* caminho_saida = ARQ_SAIDA;
	
	FILE* file;
	
	int naoAtingido, naoRemou, travado = 0;
	srand(time(NULL));
	
	if (argc < 2)
	{
		fprintf(stdout, "Uso: %s caminho_para_mapa.dat caminho_mapa_saida.dat\n", argv[0]);
		return 1;
	}
	
	if (argc >= 3)
		caminho_saida = argv[2];
	
	
	file = fopen(caminho_saida, "w");
	if (file == NULL)
		return 3;
	
	caminho_mapa = argv[1];
	
	if (leia_mapa(&mapa, caminho_mapa))
	{	
		fprintf(stdout, "Erro ao ler o mapa.\n");
		return 2;
	}
	
	posiciona_barco(mapa, &barco);
	escreva_mapa_tela(mapa);
	
	do
	{
		naoRemou = rema_barco(mapa, &barco);
		naoAtingido = dispara_tiros(mapa, file);
		
		escreva_mapa_tela(mapa);
		escreva_mapa_arquivo(mapa, file);
		
		travado = (travado + naoRemou)*naoRemou; /* Caso ele tenha remado, naoRemou é 0, anulando assim a soma.**/
		
		fputc('\n', file);
	} while (naoAtingido && travado < BECO_SEM_SAIDA && !ganhou_jogo(mapa, &barco));
	
	if (!naoAtingido)
	{              
		fputs(ATINGIDO, stdout);
		fputs(ATINGIDO,   file);
	}
	else if (travado >= BECO_SEM_SAIDA)
	{
		fputs(PRESO, stdout);
		fputs(PRESO,   file);
	}
	else
	{
		fputs(GANHOU, stdout);
		fputs(GANHOU,   file);
	}
	
	escreva_mapa_arquivo(mapa, file);
	
	fclose(file);
	destroi_mapa(&mapa);
	
	
	return 0;
}
