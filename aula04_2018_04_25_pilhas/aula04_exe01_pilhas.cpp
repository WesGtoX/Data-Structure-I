//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//data struct declare
struct monte {
	struct monte *prox;
	struct monte *ant; //lista duplamente encadeada
	int valor;
	int tam;
};
typedef struct monte pilha;

pilha *topo = (pilha *)malloc(sizeof(pilha));

void push() {
	pilha *novo = (pilha *)malloc(sizeof(pilha));
	novo -> prox = NULL;
	novo -> ant = NULL;
	
	printf("Informe o valor: ");
	scanf("%d", &novo -> valor);

	topo -> prox = novo;
	novo -> ant = topo;
	topo = novo;
	
	//printf("Valor: %d\n", topo -> valor);
	printf("\nEMPILHADO!!!\n\n");
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void pop() {
	if(topo -> ant == NULL) {
		printf("PILHA VAZIA!!\n\n");
	}
	else {
		topo = topo -> ant;
		free(topo -> prox);
		topo -> prox = NULL;
		
		printf("DESEMPILHADO!!!\n\n");
	}
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void show() {
	if(topo -> ant == NULL) {
		printf("PILHA VAZIA!!\n\n");
	}
	else {
		pilha *TEMP = topo;
		while(TEMP -> ant != NULL) {			
			printf("Valor: %d\n\n", TEMP -> valor);
			
			TEMP = TEMP -> ant;
		}
	//	printf("Valor: %d\n\n", TEMP -> valor);
	}
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void menu() {
	int opcao, i=0;
	
	system("cls");
	
	while(i == 0) {
		system("cls");
	
		printf("1 - PUSH");
		printf("\n2 - POP");
		printf("\n3 - MOSTRAR");
		printf("\n0 - Sair");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1 : {
				//empilhas
				system("cls");
				push();
				printf("%d", topo -> valor);
				break;
			}
			case 2 : {
				//desempilhar
				system("cls");
				pop();
				break;
			}
			case 3 : {
				//mostrar
				system("cls");
				show();
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

int main() {
	topo -> prox = NULL;
	topo -> ant = NULL;
	menu();
}
