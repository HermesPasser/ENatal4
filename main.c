/*
 * =================================================================
 * Desafio de Natal
 * 
 * Nível: Fácil
 * 
 * Objetivo:
 * Filtrar o lote de presentes, permitindo somente aqueles possuem
 * o peso maior que 200 gramas.
 * =================================================================
 */

#include <stdio.h>
#include <locale.h>
#include <malloc.h>

#include "gifts.h";

const unsigned int nGiftCount = 5;

// Escreve uma a lista de presentes na tela
void WriteList(struct GIFT* lpGifts)
{
	if (lpGifts)
	{
		printf("\nLista de Presentes:\n-------------------\n\n");
		for (register unsigned int i = 0; i < nGiftCount; ++i)
		{
			if (!lpGifts[i].lpchName)
				break;
			GiftData(lpGifts[i]);
		}
		printf("\nPeso total: %d\n", GetTotalWeight(lpGifts, nGiftCount));
	}
	else
	{
		printf("Não há presentes na lista.");
	}
}


int main(int argv, char** argc)
{
	setlocale(LC_ALL, "portuguese");

	// Cria a lista de presentes e, em seguida, escreve na tela
	struct GIFT* lpGifts = malloc(nGiftCount * sizeof(struct GIFT));
	ListGifts(lpGifts, nGiftCount);
	WriteList(lpGifts);

	/*
	 * ====================================================
	 * Seu código começa aqui
	 * ====================================================
	 */

	free(lpGifts);
	return 0;
}
