/*
 * =================================================================
 * Desafio de Natal
 *
 * Nível: Fácil
 *
 * Objetivo:
 * Listar os nomes de todas as crianças que receberão presente
 * neste lote de entrega do Papai Noel.
 * =================================================================
 */

#include <stdio.h>
#include <locale.h>

#define NUM_CHILDREN 12

const char* lpchChildren[NUM_CHILDREN] = {
	"Yoshinho", "Aikinha", "Pinsher", "Dovinha", "Nalfito",
	"Drakito", "Simãozinho", "Brunito", "Caiozito", "Nolanino",
	"Douglinhas", "Cenourino"
};


int main(int argv, char** argc)
{
	setlocale(LC_ALL, "portuguese");

	puts("*** LOTE DE PRESENTES - #211213 ***");
	puts("-----------------------------------\n");
	puts("Lista de crianças:\n");

	/*
	 * ====================================
	 * Seu código começa aqui
	 * ====================================
	 */
	 
	 for (int i = 0; i < NUM_CHILDREN; ++i)
		 printf("%s\n", lpchChildren[i]);

	puts("\n-----------------------------------\n");
	return 0;
}
