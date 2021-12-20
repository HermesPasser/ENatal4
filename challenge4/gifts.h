#pragma once
#include <stdio.h>

typedef struct {
	const char* lpchName;
	const char* lpchTarget;
} GIFT;

GIFT gifts[9];


void GenerateGiftList()
{
	gifts[0].lpchName = "Biscoito de Tamarindo";
	gifts[0].lpchTarget = "Yoshinho";
	gifts[1].lpchName = "Kit de Jardinagem";
	gifts[1].lpchTarget = "Aikinha";
	gifts[2].lpchName = "Bolinha de Borracha";
	gifts[2].lpchTarget = "Pinsher";
	gifts[3].lpchName = "Bonecos dos 7 anões";
	gifts[3].lpchTarget = "Dovinha";
	gifts[4].lpchName = "DVD do Naruto";
	gifts[4].lpchTarget = "Nalfito";
	gifts[5].lpchName = "Aranha de Borracha";
	gifts[5].lpchTarget = "Aikinha";
	gifts[6].lpchName = "Caminha de Cachorro";
	gifts[6].lpchTarget = "Pinsher";
	gifts[7].lpchName = "Kit de Shurikens";
	gifts[7].lpchTarget = "Nalfito";
	gifts[8].lpchName = "Biribinha de Ovos";
	gifts[8].lpchTarget = "Yoshinho";
}

void WriteGift(GIFT gift)
{
	printf("\tNome: %s | Destinatário: %s\n", gift.lpchName, gift.lpchTarget);
}
