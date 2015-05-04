/**
  * @file 
  * @brief Arquivo implementando funções que lidam com operações eventuais
  */

#include "eventos.h"

#ifdef DEBUG
#include "debug.h"
#endif

int dispara_tiros(Mapa* mapa)
{
	#ifdef DEBUG
	static char funcname[] = "Em: dispara_tiros(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

int coordenadas_tiro(int* i, int* j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: coordenadas_tiro(%p, %p)\n";
	debug_message(funcname, i, j);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

int identifica_alvo_atingido(Mapa* mapa)
{
	#ifdef DEBUG
	static char funcname[] = "Em: identifica_alvo_atingido(%p)\n";
	debug_message(funcname, mapa);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}

int afunda_embarcacao(Mapa* mapa)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_embarcacao(%p)\n";
	debug_message(funcname, mapa);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
