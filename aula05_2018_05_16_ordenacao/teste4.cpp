//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct
struct ordem {
	struct ordem *prox;;
	struct ordem *ant;
	char nome[30];
	int valor;
};
typedef struct ordem cad;

//variables
int i,j;

//function inserir
void inserir(cad *list) {
	system("cls");
	
	cad *novo = (cad *)malloc(sizeof(cad));
	
	/*printf("Digite um nome: ");
	fflush(stdin);
	gets(novo -> nome);*/
	
	printf("Digite um valor: ");
	scanf("%d", &novo -> valor);
	
	novo -> prox = NULL;
	novo -> ant = NULL;
	
	if(list -> prox == NULL) {
		list -> prox = novo;
		novo -> ant = list;
	}
	else {
		cad *TEMP = list -> prox;
		
		while(TEMP -> prox != NULL) {
			TEMP = TEMP -> prox;
		}
		TEMP -> prox = novo;
		novo -> ant = TEMP;
	}
	printf("\nADICIONADO NO FIM DA FILA!!!\n\n");
	
	system("pause");
}

//function show
void show(cad *list) {
	system("cls");
	
	if(list -> prox == NULL) {
		printf("LISTA VAZIA!!\n\n");
	}
	else {
		cad *TEMP = list -> prox;
		while(TEMP -> prox != NULL) {
			//printf("Nome: %s\n", TEMP -> nome);
			printf("Valor: %d\n\n", TEMP -> valor);
			
			TEMP = TEMP -> prox;
		}
		//printf("Nome: %s\n", TEMP -> nome);
		printf("Valor: %d\n\n", TEMP -> valor);
	}
	system("pause");
}

//function ordenacres
void ordenacres(cad *list) {
	int i=0;
	
	cad *TEMP1 = list -> prox;
	cad *TEMP2 = TEMP1 -> prox;
	cad *aux;
	cad *aux2;
	
	while(TEMP1 -> prox != NULL) {
		//------------------------------------------
		printf("TEMP1: %d\n", TEMP1 -> valor);
		printf("TEMP2: %d\n", TEMP2 -> valor);
		printf("aux: %d\n", aux -> valor);
		show(list);
		//------------------------------------------
		
		while(TEMP1 -> valor < TEMP2 -> valor) {
			TEMP2 = TEMP2 -> prox;
			
			//------------------------------------------
			printf("TEMP1: %d\n", TEMP1 -> valor);
			printf("TEMP2: %d\n", TEMP2 -> valor);
			printf("aux: %d\n", aux -> valor);
			show(list);
			//------------------------------------------
		}
		aux = TEMP2;
		TEMP2 = TEMP2 -> prox;
		
		//------------------------------------------
		printf("TEMP1: %d\n", TEMP1 -> valor);
		printf("TEMP2: %d\n", TEMP2 -> valor);
		printf("aux: %d\n", aux -> valor);
		show(list);
		//------------------------------------------
		
		//while(aux -> valor < TEMP2 -> valor) {
		while(i == 0) {
			if(aux -> valor < TEMP2 -> valor && TEMP2 != NULL) {
				TEMP2 = TEMP2 -> prox;
				
				//------------------------------------------
				printf("TEMP1: %d\n", TEMP1 -> valor);
				printf("TEMP2: %d\n", TEMP2 -> valor);
				printf("aux: %d\n", aux -> valor);
				show(list);
				//------------------------------------------
			}
			else if(aux -> valor > TEMP2 -> valor && TEMP2 != NULL) {
				aux = TEMP2;
				TEMP2 = TEMP2 -> prox;
				i++;
				
				//------------------------------------------
				printf("TEMP1: %d\n", TEMP1 -> valor);
				printf("TEMP2: %d\n", TEMP2 -> valor);
				printf("aux: %d\n", aux -> valor);
				show(list);
				//------------------------------------------
			}
			else if(aux -> valor > TEMP2 -> valor && TEMP2 == NULL) {
				aux = TEMP2;
				TEMP2 = TEMP1 -> prox;
				i++;
				
				//------------------------------------------
				printf("TEMP1: %d\n", TEMP1 -> valor);
				printf("TEMP2: %d\n", TEMP2 -> valor);
				printf("aux: %d\n", aux -> valor);
				show(list);
				//------------------------------------------
			}
		}
		if(aux -> prox == NULL) {
			aux -> ant -> prox = TEMP1;
			TEMP1 -> ant -> prox = aux;
			aux -> prox = TEMP1 -> prox;
			aux -> prox -> ant = aux;
			TEMP2 = aux -> ant;
			aux -> ant = TEMP1 -> ant;
			TEMP1 -> ant = TEMP2;
			TEMP1 -> prox = NULL;
			
			//------------------------------------------
			printf("TEMP1: %d\n", TEMP1 -> valor);
			printf("TEMP2: %d\n", TEMP2 -> valor);
			printf("aux: %d\n", aux -> valor);
			show(list);
			//------------------------------------------
		}
		else if(TEMP1 -> prox == aux) {
			TEMP1 -> ant -> prox = aux;
			TEMP1 -> prox = aux -> prox;
			aux -> prox -> ant = TEMP1;
			aux -> prox = TEMP1;
			aux -> ant = TEMP1 -> ant;
			TEMP1 -> ant = aux;
			
			//------------------------------------------
			printf("TEMP1: %d\n", TEMP1 -> valor);
			printf("TEMP2: %d\n", TEMP2 -> valor);
			printf("aux: %d\n", aux -> valor);
			show(list);
			//------------------------------------------
		}
		else if(TEMP1 -> prox != aux && aux -> prox != NULL) {
			TEMP1 -> ant -> prox = aux;
			TEMP1 -> prox = aux -> prox;
			aux -> prox -> ant = TEMP1;
			aux -> prox = TEMP1;
			aux -> ant = TEMP1 -> ant;
			TEMP1 -> ant = aux;
			
			//------------------------------------------
			printf("TEMP1: %d\n", TEMP1 -> valor);
			printf("TEMP2: %d\n", TEMP2 -> valor);
			printf("aux: %d\n", aux -> valor);
			show(list);
			//------------------------------------------
		}
		TEMP1 = aux -> prox;
		//------------------------------------------
		printf("TEMP1: %d\n", TEMP1 -> valor);
		printf("TEMP2: %d\n", TEMP2 -> valor);
		printf("aux: %d\n", aux -> valor);
		show(list);
		//------------------------------------------
	}
	
	show(list);
}

//function ordenadecres
void ordenadecres(cad *list) {

}

//function menu
void menu(cad *list) {
	system("cls");
	
	int opcao, i=0;
	
	while(i == 0) {
		system("cls");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::::::::. MENU .:::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n1 - Inserir");
		printf("\n2 - Imprimir");
		printf("\n3 - Imprimir Ordenado Crescente");
		printf("\n4 - Imprimir Ordenado Decrescente");
		printf("\n0 - Sair");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1 : {
				//inserir fim
				system("cls");
				inserir(list);
				break;
			}
			case 2 : {
				//imprimir todos
				system("cls");
				show(list);
				break;
			}
			case 3 : {
				//imprimir especifico				
				ordenacres(list);
				break;
			}
			case 4 : {
				//inserir no inicio
				system("cls");
				ordenadecres(list);
				break;
			}
			case 0 : {
				//sair
				system("cls");
				printf("\tSAINDO...\n");
				exit(1);
				break;
			}
		}
	}
	system("pause");
}

//function main
main() {
	cad *list = (cad *)malloc(sizeof(cad));
	list -> prox = NULL;
	list -> ant = NULL;
	
	menu(list);
}
