#include "graficos.h"
#include "mapa.h"
#include "barco.h"

#include "xwc.h"

int carrega_graficos(Graficos_t* graficos)
{
	return 0;
}

WINDOW* inicializa_tela(Graficos_t* graficos, const Mapa_t* mapa)
{
	return NULL;
}

void desenha_celula_tela(WINDOW* win, const Mapa_t* mapa, const Graficos_t* graficos, int variacao, int i, int j)
{
	
}

void matricial_para_cartesiana(const Mapa_t* mapa, int i, int j, int* x, int* y)
{

}

void cartesiana_para_matricial(const Mapa_t* mapa, int* i, int* j, int x, int y)
{

}

void desenha_mapa_tela(WINDOW* win, const Mapa_t* mapa, const Barco_t* barco)
{

}
