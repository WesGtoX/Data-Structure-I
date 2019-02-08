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

//int vetor[10] = {3,5,14,2,9,7,12,1,18,6}, n=0; //TEMP

//function inserir
void inserir(cad *list) {
	system("cls");
	
	cad *novo = (cad *)malloc(sizeof(cad));
	
	/*printf("Digite um nome: ");
	fflush(stdin);
	gets(novo -> nome);*/
	
	printf("Digite um valor: ");
	scanf("%d", &novo -> valor);
	//novo -> valor = vetor[n];
	
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

//================================================
void atribuir(cad *list) { //FUNÇÃO DE TESTE
	/*while(n < 10) { //TEMP
		inserir(list);
		n++;
	} //TEMP*/
}
//================================================

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
	int i=0, ordenado=0, check=0;
	
	cad *TEMP1 = list -> prox;
	cad *TEMP2 = TEMP1 -> prox;
	cad *aux;
	cad *aux2;
	cad *ord;
	
	while(ordenado == 0) {
	
		while(TEMP1 -> prox != NULL) {
			if(TEMP2 -> valor < TEMP1 -> valor && TEMP2 -> valor < aux -> valor || TEMP2 -> valor < aux -> valor && TEMP1 != aux) {
				aux = TEMP2;
			}
			TEMP2 = TEMP2 -> prox;
			
			if(TEMP1 -> prox == NULL) {
				if(TEMP2 -> valor < TEMP1 -> valor && TEMP2 -> valor < aux -> valor || TEMP2 -> valor < aux -> valor && TEMP1 != aux) {
					aux = TEMP2;
				}
			}
		}	
		if(TEMP1 -> prox != aux && aux -> prox != NULL && TEMP1 != aux) {
			TEMP1 -> prox -> ant = aux;
			aux -> prox -> ant = TEMP1;
			TEMP2 = TEMP1 -> prox;
			TEMP1 -> prox = aux -> prox;
			aux -> prox = TEMP2;
					
			TEMP1 -> ant -> prox = aux;
			aux -> ant -> prox = TEMP1;
			TEMP2 = TEMP1-> ant;
			TEMP1 -> ant = aux -> ant;
			aux -> ant = TEMP2;
		}
		else if(TEMP1 -> prox == aux && TEMP1 != aux) {
			TEMP1 -> ant -> prox = aux;
			TEMP1 -> prox = aux -> prox;
			aux -> prox -> ant = TEMP1;
			aux -> prox = TEMP1;
			aux -> ant = TEMP1 -> ant;
			TEMP1 -> ant = aux;
		}
		else if(TEMP1 -> prox == aux && aux -> prox == NULL && TEMP1 != aux) {
			TEMP1 -> prox = aux -> prox;
			aux -> prox = TEMP1;
			TEMP1 -> ant -> prox = aux;
			aux -> ant = TEMP1 -> ant;
			TEMP1 -> ant = aux;
		}		
		else if(aux -> prox == NULL && TEMP1 != aux) {
			TEMP1 -> prox -> ant = aux;
			aux -> prox = TEMP1 -> prox;
			TEMP1 -> prox = NULL;
			
			TEMP1 -> ant -> prox = aux;
			aux -> ant -> prox = TEMP1;
			TEMP2 = TEMP1-> ant;
			TEMP1 -> ant = aux -> ant;
			aux -> ant = TEMP2;
		}
		ord = list -> prox;
		while(ord -> prox != NULL) {
			if(ord -> valor < ord -> prox -> valor) {
				ordenado = 1;
			}
			else {
				ordenado = 0;
				break;
			}
			ord = ord -> prox;
		}
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
				//atribuir(list);
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
