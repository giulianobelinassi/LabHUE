/**
  * @file 
  * @brief Arquivo implementando as funções que lidam com operações navais
  */

#include "barco.h"

#ifdef DEBUG
#include "debug.h"
#endif

int rema_barco(Mapa* mapa, Barco* barco)
{
	#ifdef DEBUG
	static char funcname[] = "Chamado: rema_barco(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

int posiciona_barco(Mapa* mapa, Barco* barco)
{
	#ifdef DEBUG
	static char funcname[] = "Chamado: posiciona_barco(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
