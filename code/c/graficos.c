#include <stdlib.h>
#include "graficos.h"
#include "mapa.h"
#include "barco.h"

#include "xwc.h"

#ifndef NO_GUI /** Compilamos sem interface gráfica.*/

Graficos_t* carrega_graficos(WINDOW* win)
{
	/*Caminho para os arquivos gráficos*/
	static char BARCO_DIREITA[]	= "graficos/bd0.xpm";
	static char BARCO_ESQUERDA[]	= "graficos/be0.xpm";
	static char BARCO_BAIXO[]	= "graficos/bb0.xpm";
	static char AGUA[]		= "graficos/w48.xpm";
	static char DESTROCO[]		= "graficos/wfogo48.xpm";
	static char RASTRO[]		= "graficos/rastro.xpm";
	static char TIRO[]		= "graficos/tiro.xpm";
	static char ONDA[]		= "graficos/onda.xpm";
	
	Graficos_t* g = malloc(sizeof(Graficos_t));
	
	if (!g)
		return NULL;
	
	g->barco[BARCO_E] = ReadPic(win, BARCO_ESQUERDA, NULL);
	g->barco[BARCO_B] = ReadPic(win, BARCO_BAIXO, NULL);
	g->barco[BARCO_D] = ReadPic(win, BARCO_DIREITA, NULL);
	g->agua           = ReadPic(win, AGUA, NULL);
	g->destroco       = ReadPic(win, DESTROCO, NULL);
	g->rastro         = ReadPic(win, RASTRO, NULL);
	g->tiro           = ReadPic(win, TIRO, NULL);
	g->onda           = ReadPic(win, ONDA, NULL);
	
	return g;
}

void destroi_graficos(struct Graficos** graficos)
{
	Graficos_t* g = *graficos;
	
	FreePic(g->barco[BARCO_E]);
	FreePic(g->barco[BARCO_B]);
	FreePic(g->barco[BARCO_D]);
	FreePic(g->agua);
	FreePic(g->destroco);
	FreePic(g->rastro);
	FreePic(g->tiro);
	FreePic(g->onda);
	
	*graficos = NULL;
}

WINDOW* inicializa_janela(Graficos_t** graficos, const Mapa_t* mapa)
{
	static char NOME_JANELA[] = "Fuga Naval";
	int M = mapa->altura;
	int N = mapa->largura;
	int i, j;
	
	WINDOW* win = InitGraph(DIM_X*N, DIM_Y*M, NOME_JANELA);
	
	*graficos = carrega_graficos(win);
	
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
			desenha_cedula_janela(win, *graficos, mapa, 1, i, j);
			
	return win;
}

void desenha_cedula_janela(WINDOW* win, const Graficos_t* graficos, const Mapa_t* mapa, int variacao, int i, int j)
{
	char c = mapa->matriz[i][j];
	
	switch (c)
	{	
		case 'B':
			PutPic(win, graficos->barco[variacao], 0, 0, DIM_X, DIM_Y, j*DIM_X, i*DIM_Y);
		break;
		
		case '+':
		case '=':
			PutPic(win, graficos->onda, 0, 0, DIM_X, DIM_Y, j*DIM_X, i*DIM_Y);
		break;
		
		case 'T':
			PutPic(win, graficos->rastro, 0, 0, DIM_X, DIM_Y, j*DIM_X, i*DIM_Y);
		break;
		
		case '!':
		case '*':
			PutPic(win, graficos->destroco, 0, 0, DIM_X, DIM_Y, j*DIM_X, i*DIM_Y);
		break;
		
		default:
			PutPic(win, graficos->agua, 0, 0, DIM_X, DIM_Y, j*DIM_X, i*DIM_Y);
	}
}

void desenha_barco_janela(WINDOW* win, const Graficos_t* graficos, const Barco_t* barco)
{
	int variacao = 1;
	switch (barco->bussola)
	{
		case 'e':
			variacao = BARCO_E;
		break;
		
		case 'b':
			variacao = BARCO_B;
		break;
		
		case 'd':
			variacao = BARCO_D;
		break;
	}
	
	PutPic(win, graficos->barco[variacao], 0, 0, DIM_X, DIM_Y, barco->coluna*DIM_X, barco->linha*DIM_Y);
}

void desenha_mensagem_janela(WINDOW* win, const char* msg)
{
	WPrint(win, 0, 30, (char*) msg);
}

void desenha_mapa_janela(WINDOW* win, Graficos_t* graficos, const Mapa_t* mapa, const Barco_t* barco)
{
	int i, j;
	int M = mapa->altura;
	int N = mapa->largura;
	int variacao = 0;
	
	switch (barco->bussola)
	{
		case 'e':
			variacao = BARCO_E;
		break;
		
		case 'b':
			variacao = BARCO_B;
		break;
		
		case 'd':
			variacao = BARCO_D;
		break;
	}
	
	
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
			desenha_cedula_janela(win, graficos, mapa, variacao, i, j);
	
	/*desenha_barco_janela(win, graficos, barco);*/
}

char pega_seta_janela(WINDOW* win)
{
	KeyCode key;
	InitKBD(win);
	key = WGetKey(win);
	
	if (key == 113)
		return 'e';
	if (key == 116)
		return 'b';
	if (key == 114)
		return 'd';
	if (key == 36)
		return '='; /*Enter.*/
	
	return '\0';
}

void destroi_janela(WINDOW* win)
{
	WDestroy(win);
}

void exibe_janela(WINDOW* win)
{
	WShow(win);
}

void esconde_janela(WINDOW* win)
{
	WHide(win);
}

#endif
