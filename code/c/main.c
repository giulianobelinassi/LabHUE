/**
  *@file Lógica principal
  */
#include "mapa.h"
#include "barco.h"
#include "eventos.h"
#include <stdio.h>

#ifdef DEBUG
#include "debug.h"
#endif

#define BECO_SEM_SAIDA 3 /**< Quantidade de jogadas sem o barco se mover até que o jogo pare.*/


/**
  * Recebe via argumentos o mapa e opcionalmente o arquivo de saída.
  * @brief		Lógica principal do programa
  * @return 		0, se sucesso.
  */
int main(int argc, char* argv[])
{
	Mapa* mapa;
	static Barco lbarco;
	Barco* barco = &lbarco;
	int naoAtingido, naoRemou, travado = 0;
	char* caminho_mapa;
	char* caminho_saida = NULL;
	FILE* file;
	#ifdef DEBUG
	char funcname[] = "main(%d)\n";
	debug_message(funcname, argc);
	#endif
	
	if (argc < 2)
	{
		fprintf(stdout, "Uso: %s caminho_para_mapa.dat caminho_mapa_saida.dat\n", argv[0]);
		return 1;
	}
	
	file = fopen("huehuehue.txt", "w");
	caminho_mapa = argv[1];
	
	/*if (argc >= 3)
		caminho_saida = argv[2];
	*/
	if (leia_mapa(&mapa, caminho_mapa))
	{	
		fprintf(stdout, "Erro ao ler o mapa.\n");
		return 2;
	}
	posiciona_barco(mapa, barco);
	escreva_mapa_tela(mapa);
	
	do
	{
		naoRemou = rema_barco(mapa, barco);
		naoAtingido = dispara_tiros(mapa, file);
		escreva_mapa_tela(mapa);
		escreva_mapa_arquivo(mapa, file);
		travado = (travado + naoRemou)*naoRemou;
	} while (naoAtingido && travado < BECO_SEM_SAIDA && !ganhou_jogo(mapa, barco));
	
	if      (!naoAtingido)
	{              
		fprintf(stdout, "Seu barco foi atingido.\n");
		fprintf(file, "Seu barco foi atingido.\n");
	}
	else if (travado >= BECO_SEM_SAIDA)
	{
		fprintf(stdout, "Seu barco ficou preso.\n");
		fprintf(file, "Seu barco ficou preso.\n");
	}
	else{
	        fprintf(stdout, "Você ganhou.\n");
	        fprintf(file, "Você ganhou.\n");
	}
	
	if (caminho_saida != NULL)
		escreva_mapa_arquivo(mapa, file);
	
	fclose(file);
	destroi_mapa(&mapa);
	
	
	return 0;
}
