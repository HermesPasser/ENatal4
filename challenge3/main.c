/*
 * =================================================================
 * Desafio de Natal
 *
 * N�vel: Intermedi�rio
 *
 * Objetivo:
 * Ler o CSV com a lista de todas as crian�as contendo seu nome,
 * idade e o presente pedido para este Natal.
 * Ap�s isso, o sistema deve organizar a lista com a idade
 * das crian�as, come�ando da mais nova at� a mais velha.
 * =================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

typedef struct GiftData {
	char* name;
	char* gift;
	size_t age;
} GiftData;

#define NUM_GIFTS 5
GiftData data[NUM_GIFTS];

void parse_gifts(char* filepath) {
	FILE* fp = fopen(filepath, "r");
	if (!fp) {
		printf("Não foi possível abrir arquivo");
		exit(1);
	}

	size_t i = 0;
	size_t len = 0;
	char* line = NULL;
	int read = 0;

	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0] == '\0')
			break;
		
		// GiftData item;

		char *tok = strtok(line, ",");
		printf("%s\n", tok);
		strcpy(data[i].name, tok);

		data[i].age = atoi(strtok(NULL, ","));
		strcpy(data[i].gift, strtok(NULL, ","));
		
		// data[i] = item;
		printf("-----------");
		printf("??.%d\n",  data[i].gift);
		i++;

	}  

	fclose(fp);
}

void sort_gifts() {

	// for (int i = 0; i < NUM_GIFTS; ++i)
	// 	for (int j = i; j < NUM_GIFTS; ++j) {
	// 		printf("%s\n", data[i].name);
	// 	}
}

int main(int argv, char** argc)
{
	setlocale(LC_ALL, "portuguese");

	puts("*** LOTE DE PRESENTES - #211213 ***");
	puts("-----------------------------------\n");
	puts("Lista de Pedidos:\n");

	/*
	* ====================================
	* Seu c�digo come�a aqui
	* ====================================
	*/
	// data = malloc(NUM_GIFTS * sizeof(GiftData));
	parse_gifts("criancas.csv");
	sort_gifts();
		// printf("%s %d %s\n", item.name, item.age, item.gift);
	
	puts("\n-----------------------------------\n");
	return 0;
}