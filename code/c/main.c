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
