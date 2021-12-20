/*
 * =================================================================
 * Desafio de Natal
 *
 * Nível: Intermediário
 *
 * Objetivo:
 * Ler o CSV com a lista de todas as crianças contendo seu nome,
 * idade e o presente pedido para este Natal.
 * Após isso, o sistema deve organizar a lista com a idade
 * das crianças, começando da mais nova até a mais velha.
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
		printf("NÃ£o foi possÃ­vel abrir arquivo");
		exit(1);
	}

	size_t i = 0;
	size_t len = 0;
	char* line = NULL;
	int read = 0;

	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0] == '\0')
			break;
		
		char* name = strtok(line, ",");
		int age = atoi(strtok(NULL, ","));
		char* gift = strtok(NULL, ",");

		data[i].age = age;
		data[i].name = malloc(sizeof(char) * strlen(name));
		data[i].gift = malloc(sizeof(char) * strlen(gift));
		strcpy(data[i].name, name);
		strcpy(data[i].gift, gift);

		i++;
	}  

	fclose(fp);
}

void sort_gifts() {
	for (int i = 0; i < NUM_GIFTS - 1; ++i) {
		for (int j = i; j < NUM_GIFTS; ++j) {
			if (data[i].age > data[j].age) {
				GiftData temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
}

void print_gifts() {
	for (int i = 0; i < NUM_GIFTS; ++i) 
		printf("%s %d %s\n", data[i].name, data[i].age, data[i].gift);
}

void free_gifts() {
	for (int i = 0; i < NUM_GIFTS; ++i) {
		free(data[i].name);
		free(data[i].gift);
	}
}


int main(int argv, char** argc)
{
	setlocale(LC_ALL, "portuguese");

	puts("*** LOTE DE PRESENTES - #211213 ***");
	puts("-----------------------------------\n");
	puts("Lista de Pedidos:\n");

	/*
	* ====================================
	* Seu câ–¡digo comeâ–¡a aqui
	* ====================================
	*/

	parse_gifts("criancas.csv");
	sort_gifts();
	print_gifts();
	free_gifts();
	
	puts("\n-----------------------------------\n");
	return 0;
}