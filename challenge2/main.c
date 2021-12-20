/*
 * =================================================================
 * Desafio de Natal
 *
 * N�vel: F�cil
 *
 * Objetivo:
 * Listar os nomes de todas as crian�as que receber�o presente
 * neste lote de entrega do Papai Noel.
 * =================================================================
 */

#include <stdio.h>
#include <locale.h>

#define NUM_CHILDREN 12

const char* lpchChildren[NUM_CHILDREN] = {
	"Yoshinho", "Aikinha", "Pinsher", "Dovinha", "Nalfito",
	"Drakito", "Sim�ozinho", "Brunito", "Caiozito", "Nolanino",
	"Douglinhas", "Cenourino"
};


int main(int argv, char** argc)
{
	setlocale(LC_ALL, "portuguese");

	puts("*** LOTE DE PRESENTES - #211213 ***");
	puts("-----------------------------------\n");
	puts("Lista de crian�as:\n");

	/*
	 * ====================================
	 * Seu c�digo come�a aqui
	 * ====================================
	 */
	 
	 for (int i = 0; i < NUM_CHILDREN; ++i)
		 printf("%s\n", lpchChildren[i]);

	puts("\n-----------------------------------\n");
	return 0;
}
