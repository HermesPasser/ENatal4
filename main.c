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

#include "gifts.h"

const unsigned int nGiftCount = 5;

// Escreve uma a lista de presentes na tela
void WriteList(struct GIFT* lpGifts, size_t size)
{
	if (lpGifts)
	{
		printf("\nLista de Presentes:\n-------------------\n\n");

		for (size_t i = 0; i < size; ++i)
		{
			if (!lpGifts[i].lpchName)
				break;
			GiftData(lpGifts[i]);
		}
		printf("\nPeso total: %d\n", GetTotalWeight(lpGifts, size));
	}
	else
	{
		printf("Não há presentes na lista.");
	}
}

struct GIFT* FilterByWeight(struct GIFT* gifts, size_t weight, size_t* outSize) {
	struct GIFT* filtered = malloc(nGiftCount * sizeof(struct GIFT));
	
	size_t count = 0;
	for (size_t i = 0; i < MAX_GIFTS; ++i) {
			struct GIFT item = gifts[i];
			if (item.nWeight > weight)
				filtered[count++] = item;
	}

	filtered = realloc(filtered, count *  sizeof(struct GIFT));
	*outSize = count;
	return filtered;
}

int main(int argv, char** argc)
{
	setlocale(LC_ALL, "portuguese");

	// Cria a lista de presentes e, em seguida, escreve na tela
	struct GIFT* lpGifts  = malloc(nGiftCount * sizeof(struct GIFT));
	ListGifts(lpGifts , nGiftCount);
	WriteList(lpGifts, nGiftCount);

	/*
	 * ====================================================
	 * Seu código começa aqui
	 * ====================================================
	 */
	printf("\n------ filtrados ------\n");
	size_t size;
	struct GIFT* lpFilteredGifts = FilterByWeight(lpGifts , 200, &size);
	WriteList(lpFilteredGifts, size);

	free(lpFilteredGifts);
	free(lpGifts);
	return 0;
}
