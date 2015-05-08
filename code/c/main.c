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

/**
  * Lógica principal do programa
  * @param argc		
  * @param argv
  * @return 
  */


/** Sugestão (o que acham?)
  *
  * posiciona_barco
  * turno = 0
  * emboscada = 0
  * while(!fimDoJogo)
  *   exibe mapa na tela completado por '-' da linha ocupada pelo barco até (linha mapa->altura - 1)
  *   rema barco
  *   dispara tiros
  *	  se (posicao atual do barco == posicao anterior do barco) emboscada++
  *   se (barco foi atingido || barco->linha == mapa.altura - 1 || emboscada == 3) fimDoJogo
  *
  */

int main(int argc, char* argv[])
{
	Mapa* mapa;
	#ifdef DEBUG
	char funcname[] = "main(%d)\n";
	debug_message(funcname, argc);
	#endif
	
	if (leia_mapa(&mapa, "mapas/mapa3.dat"))
		fprintf(stdout, "leia_mapa() :(");
	
	escreva_mapa_tela(mapa);
	
	if (escreva_mapa_arquivo(mapa, "hue.dat"))
		fprintf(stdout, "escreva_mapa_arquivo() :(");
	
	destroi_mapa(&mapa);
	
	return 0;
}
