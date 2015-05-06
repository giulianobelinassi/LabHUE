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

/** Afunda um destroyer 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_destroier(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_destroyer(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
}


/** Afunda um cruzador 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_cruzador(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_cruzador(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
}


/** Afunda um porta-avião 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_porta_aviao(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_porta_aviao(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
}


/** Afunda um hidro-avião 
  * @param mapa	Referência ao mapa.
  * @param i 	i-ésima linha.
  * @param j	j-ésima coluna.
  * @return	Sucesso?
  */
int afunda_hidro_aviao(Mapa* mapa, int i, int j)
{
	#ifdef DEBUG
	static char funcname[] = "Em: afunda_hidro_aviao(%d, %d)\n";
	debug_message(funcname, i, j);
	#endif

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
}

int ganhou_jogo(const Mapa* mapa, const Barco* barco)
{
	#ifdef DEBUG
	static char funcname[] = "Em: ganhou_jogo(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
