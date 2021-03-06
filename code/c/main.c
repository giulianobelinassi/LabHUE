/*
  *@file Lógica principal
  */
#include "mapa.h"
#include "barco.h"
#include "eventos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef NO_GUI
#include "graficos.h"
#endif

#define BECO_SEM_SAIDA 3 /**< Quantidade de jogadas sem o barco se mover até que o jogo pare.*/


/**
  * Recebe via argumentos o mapa e opcionalmente o arquivo de saída.
  * @brief		Lógica principal do programa
  * @return 		0, se sucesso.
  */
int main(int argc, char* argv[])
{
	static const char ARQ_SAIDA[] = "saida.txt";
	static const char ATINGIDO[]  = "Seu barco foi atingido!\n";
	static const char PRESO[]     = "Seu barco ficou preso!\n";
	static const char GANHOU[]    = "Você Ganhou!\n";

	Mapa_t* mapa;
	Barco_t barco;
	
	const char* caminho_mapa;
	const char* caminho_saida = ARQ_SAIDA;
	
	FILE* file;
	
	int naoAtingido, naoRemou, travado = 0;
	
	struct Win* win;
	struct Graficos* graficos;
	
	#ifdef NO_GUI
	win      = NULL;
	graficos = NULL;
	#endif
	
	srand(time(NULL));
	
	if (argc < 2)
	{
		fprintf(stdout, "Uso: %s caminho_para_mapa.dat caminho_texto_saida.txt\n", argv[0]);
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
	
	#ifndef NO_GUI
	win = inicializa_janela(&graficos, mapa);
	exibe_janela(win);
	#endif
	
	do
	{
		naoRemou = rema_barco(win, mapa, &barco);
		naoAtingido = dispara_tiros(mapa, file);
		
		escreva_mapa_tela(mapa);
		escreva_mapa_arquivo(mapa, file);
		
		#ifndef NO_GUI
		desenha_mapa_janela(win, graficos, mapa, &barco);
		#endif
		
		travado = (travado + naoRemou)*naoRemou; /* Caso ele tenha remado, naoRemou é 0, anulando a soma.**/
		
		fputc('\n', file);
	} while (naoAtingido && travado < BECO_SEM_SAIDA && !ganhou_jogo(mapa, &barco));
	
	if (!naoAtingido)
	{              
		fputs(ATINGIDO, stdout);
		fputs(ATINGIDO,   file);
		#ifndef NO_GUI
		desenha_mensagem_janela(win, ATINGIDO);
		#endif
	}
	else if (travado >= BECO_SEM_SAIDA)
	{
		fputs(PRESO, stdout);
		fputs(PRESO,   file);
		#ifndef NO_GUI
		desenha_mensagem_janela(win, PRESO);
		#endif
	}
	else
	{
		fputs(GANHOU, stdout);
		fputs(GANHOU,   file);
		#ifndef NO_GUI
		desenha_mensagem_janela(win, GANHOU);
		#endif
	}
	
	escreva_mapa_arquivo(mapa, file);
    
	#ifndef NO_GUI
	while (pega_seta_janela(win) == '\0')
		; /*Aguarde o usuário pressionar uma tecla válida na janela.*/
        
        destroi_janela(win);
	#endif
	
	fclose(file);
	destroi_mapa(&mapa);
	
	
	return 0;
}
