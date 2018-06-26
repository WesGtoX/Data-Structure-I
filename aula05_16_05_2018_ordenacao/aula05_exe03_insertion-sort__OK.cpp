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
	cad *ref = list -> prox;
	cad *aux = ref -> prox;
	cad *TEMP;
	
	while(ref -> prox != NULL) {
		while(ref -> valor < aux -> valor && aux -> prox != NULL) {
			ref = ref -> prox;
			aux = aux -> prox;
		}
		if(ref -> valor < aux -> valor && ref -> prox -> prox == NULL) {
			ref = aux;
		}
		if(ref -> valor > aux -> valor && aux -> prox != NULL) {
			ref -> ant -> prox = aux;
			ref -> prox = aux -> prox;
			aux -> prox -> ant = ref;
			aux -> prox = ref;
			aux -> ant = ref -> ant;
			ref -> ant = aux;
		}
		if(ref -> valor > aux -> valor && aux -> prox == NULL) {
			ref -> prox = aux -> prox;
			ref -> ant -> prox = aux;
			aux -> ant = ref -> ant;
			aux -> prox = ref;
			ref -> ant = aux;
		}
		while(aux -> valor < aux -> ant -> valor && aux -> ant != list) {
			TEMP = aux -> ant;
			TEMP -> ant -> prox = aux;
			TEMP -> prox = aux -> prox;
			aux -> prox -> ant = TEMP;
			aux -> prox = TEMP;
			aux -> ant = TEMP -> ant;
			TEMP -> ant = aux;
		}
		if(ref -> prox != NULL) {
			aux = ref -> prox;
		}
	}
	show(list);
}

//function ordenadecres
void ordenadecres(cad *list) {
	cad *ref = list -> prox;
	cad *aux = ref -> prox;
	cad *TEMP;
	
	while(ref -> prox != NULL) {
		while(ref -> valor > aux -> valor && aux -> prox != NULL) {
			ref = ref -> prox;
			aux = aux -> prox;
		}
		if(ref -> valor > aux -> valor && ref -> prox -> prox == NULL) {
			ref = aux;
		}
		if(ref -> valor < aux -> valor && aux -> prox != NULL) {
			ref -> ant -> prox = aux;
			ref -> prox = aux -> prox;
			aux -> prox -> ant = ref;
			aux -> prox = ref;
			aux -> ant = ref -> ant;
			ref -> ant = aux;
		}
		if(ref -> valor < aux -> valor && aux -> prox == NULL) {
			ref -> prox = aux -> prox;
			ref -> ant -> prox = aux;
			aux -> ant = ref -> ant;
			aux -> prox = ref;
			ref -> ant = aux;
		}
		while(aux -> valor > aux -> ant -> valor && aux -> ant != list) {
			TEMP = aux -> ant;
			TEMP -> ant -> prox = aux;
			TEMP -> prox = aux -> prox;
			aux -> prox -> ant = TEMP;
			aux -> prox = TEMP;
			aux -> ant = TEMP -> ant;
			TEMP -> ant = aux;
		}
		if(ref -> prox != NULL) {
			aux = ref -> prox;
		}
	}
	show(list);
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
