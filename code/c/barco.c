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

/** Sucesso em posicionar o barco retorna 0
 */
int posiciona_barco(pMapa mapa, pBarco barco)
{
	int pos, valido;

	#ifdef DEBUG
	static char funcname[] = "Chamado: posiciona_barco(%p, %p)\n";
	debug_message(funcname, mapa, barco);
	#endif
	
	fprintf(stdout, "Escolha uma coluna para posicionar o barco. ");
	fprintf(stdout, "Entre com uma coluna valida: entre 0 e %d\n", mapa -> largura);
	fscanf(stdin, "%d", &pos);
	if(pos <= 0 && pos >= mapa -> largura)
		valido = 0;
	while(!valido && mapa -> matriz[0][pos] != '.')
	{
		printf("Posicao inválida! Tente novamente\n");
		scanf("%d", &pos);
		if(pos >= 0 && pos <= 9) valido = 1;
	}
	mapa -> matriz[0][pos] = 'B';
	barco->linha = 0;
	barco->coluna = pos;

	#ifdef DEBUG
	debug_message("Prestes a retornar 0\n");
	#endif
	return 0;
}
