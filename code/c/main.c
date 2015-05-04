/**
  *@file Lógica principal
  */
#include "mapa.h"
#include "barco.h"
#include "eventos.h"

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
	char funcname[] = "main(%d)";
	debug_message(funcname, argc);
	#endif
	
	mapa = novo_mapa(5000, 5000);
	destroi_mapa(&mapa);
	
	return 0;
}
