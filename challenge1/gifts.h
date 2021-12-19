#pragma once
#include <stdio.h>

#ifndef memcpy_s
#define memcpy_s memcpy
#endif

#define MAX_GIFTS 5

// Objeto que representa o presente
struct GIFT {
	const char* lpchName;
	unsigned int nWeight;
};

size_t ClampSize(size_t nSize)
{
	return (nSize > MAX_GIFTS) ? MAX_GIFTS : nSize;
}


// Criar uma lista de presentes
void ListGifts(struct GIFT* lpGifts, size_t nSize)
{
	const char* lpchNames[MAX_GIFTS] = {
		"Avião de Controle Remoto",
		"Boneca de Pano",
		"Tecladinho",
		"Bola Quadrada",
		"Jogo de Cházinho"
	};
	const unsigned int lpnWeights[MAX_GIFTS] = {
		200, 100, 350, 50, 250
	};

	for (register unsigned int i = 0; i < ClampSize(nSize); ++i)
	{
		lpGifts[i].lpchName = lpchNames[i];
		lpGifts[i].nWeight = lpnWeights[i];
	}
}

// Escrever dados do presente
void GiftData(struct GIFT gift)
{
	printf("%s | Peso: %d\n", gift.lpchName, gift.nWeight);
}

// Calcular o peso total do lote de presentes
unsigned int GetTotalWeight(struct GIFT* lpGifts, size_t nSize)
{
	unsigned int nTotal = 0;
	for (register unsigned int i = 0; i < ClampSize(nSize); ++i)
	{
		nTotal += lpGifts[i].nWeight;
	}
	return nTotal;
}
