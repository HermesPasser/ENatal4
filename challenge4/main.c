/*
 * =================================================================
 * Desafio de Natal
 *
 * Nível: Intermediário
 *
 * Objetivo:
 * Consertar o organizador de presentes.
 * O sistema deve selecionar presentes de forma aleatória porém
 * os presentes não podem se repetir nos lotes, pois os mesmos devem
 * ser removidos da lista para despache.
 * Cada lote deve conter presentes antes de ser despachado para
 * o envio para as crianças.
 * =================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>
#include <Windows.h>

#include "gifts.h"

#define LIST_SIZE 9
#define BATCH_SIZE 3

void Init()
{
	puts("*** SEPARADOR DE PRESENTES ***\n");
	puts("Iniciando a máquina...");
	Sleep(1000);
	puts("Aquecendo os motores...");
	Sleep(2000);
	puts("Detectando os presentes...");
	GenerateGiftList();
	Sleep(2000);
	puts("Pronto!\n");
}

int CreateBatches(GIFT** batches, GIFT* base)
{
	BOOL packed[9] = { FALSE };

	if (batches)
	{
		for (register size_t i = 0; i < LIST_SIZE / BATCH_SIZE; ++i)
		{
			batches[i] = (GIFT*) malloc(BATCH_SIZE * sizeof(GIFT));
			if (batches[i])
			{
				for (register size_t j = 0; j < BATCH_SIZE; ++j)
				{
					size_t num;
					while(packed[num = rand() % LIST_SIZE]);
					
					batches[i][j] = base[num];
					packed[num] = TRUE;
				}
			}
		}
		return 1;
	}
	return 0;
}


int main(int argv, char** argc)
{
	srand((unsigned int) time(NULL));
	setlocale(LC_ALL, "portuguese");
	Init();

	GIFT** batches = (GIFT**)malloc(LIST_SIZE / BATCH_SIZE * sizeof(GIFT*));
	puts("Separando os presentes...");
	Sleep(1000);
	CreateBatches(batches, gifts);

	if (batches)
	{
		for (register size_t i = 0; i < LIST_SIZE / BATCH_SIZE; ++i)
		{
			printf("\nLote #%d:\n---------\n", (i + 1));
			for (register size_t j = 0; j < BATCH_SIZE; ++j)
			{
				WriteGift(batches[i][j]);
			}
		}
		puts("\nTodos os presentes foram despachados com sucesso!");
	}
	else
	{
		puts("\nNão há nenhum lote para despachar os presentes.");
	}

	free(batches);
	return 0;
}
