//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//struct
struct ordem {
	struct ordem *prox;;
	struct ordem *ant;
	char nome[30];
	int valor;
};
typedef struct ordem cad;

//variables
int i,j, count=10;
int vetor[10] = {3,5,14,2,9,7,12,1,18,6}, n=0; //TEMP
//int vetor[18] = {3,8,5,14,2,16,4,9,15,7,12,10,1,18,17,11,13,6}, n=0; //TEMP
//int vetor[30] = {26,20,27,29,9,5,4,30,23,1,9,4,20,30,6,21,28,2,5,24,23,28,19,17,30,20,25,12,1,29}, n=0;

//function inserir
void inserir(cad *list) {
	system("cls");
		cad *novo = (cad *)malloc(sizeof(cad));
		
		/*printf("Digite um nome: ");
		fflush(stdin);
		gets(novo -> nome);*/
		
		//printf("Digite um valor: ");
		//scanf("%d", &novo -> valor);
		
		novo -> valor = vetor[n];
		
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
		count++;
			
	printf("\nADICIONADO NO FIM DA FILA!!!\n\n");
	
	//system("pause");
}

//================================================
void atribuir(cad *list) {
	while(n < count) { //TEMP
		inserir(list);
		n++;
	} //TEMP
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

int random() {
	int x;
	
	srand(time(NULL));
	
	x = 1 + rand() % count;
	
	return x;
}

//function ordenacres
void ordenacres(cad *list) {
	//local variables
	int p, ordenado=0, check=0, pivos[count], vector[count];
	
	cad *pivo;
	
	cad *TEMP;
	cad *aux;
	cad *TEMP2;
	cad *ord;
	
/*	while(ordenado == 0) {
		//printf("\n\nwhile 0\n\n");
		
	//============================== SELECIONAR O PIVO ==============================
		if(check == 0) {
			pivo = list -> prox;*/
			
			//printf("Escolha o pivo: ");
			//scanf("%i", &p);			
		int resp;
		printf("Resposta: ");
		scanf("%i", &resp);

			p = random();
			printf("\n\nPivo random = %i\n\n", p);
			system("pause");
			
			
		while(resp == 1) {

			while(p != vector[j] && vector[j] != NULL){
				if(p == vector[j]) {
					p = random();
				}
				else {
					vector[i++] = p;
				}
				j++;
			}
			printf("\n\nPivo random = %i\n\n", p);
			system("pause");

			
			
		printf("\n\nResposta: ");
		scanf("%i", &resp);
		}
			for(i=0; i < count; i++) {
				printf("\nPivo random = %i\n", vector[i]);
			}
			system("pause");
/*			
			while(pivo -> valor != p) {
				pivo = pivo -> prox;
			}
			TEMP = pivo -> prox;
			aux = pivo;
																		printf("\nPivo: %i", pivo -> valor);printf("\naux: %i", aux -> valor);printf("\nTEMP: %i\n\n", TEMP -> valor);system("pause");
		}
	check = 0;		
	//============================== VERIFICAR SE H� ALGUM N� MENOR A DIREITA ==============================
		while(TEMP -> prox != NULL) {
			//printf("\n\nwhile 1\n\n");
			if(TEMP -> valor < pivo -> valor && TEMP -> valor < aux -> valor || TEMP -> valor < aux -> valor && pivo != aux) {
				aux = TEMP;
																		printf("\ntest: 0");printf("\nPivo: %i", pivo -> valor);printf("\naux: %i", aux -> valor);printf("\nTEMP: %i\n\n", TEMP -> valor);system("pause");
			}
			TEMP = TEMP -> prox;
			
			if(TEMP -> prox == NULL) {
				if(TEMP -> valor < pivo -> valor && TEMP -> valor < aux -> valor || TEMP -> valor < aux -> valor && pivo != aux) {
					aux = TEMP;
																		printf("\ntest: 0");printf("\nPivo: %i", pivo -> valor);printf("\naux: %i", aux -> valor);printf("\nTEMP: %i\n\n", TEMP -> valor);system("pause");
				}
			}
		}
		if(pivo -> prox != aux && aux -> prox != NULL && pivo != aux) {
																		printf("\nTROCA 1-1 in\n");system("pause");
			pivo -> prox -> ant = aux;
			aux -> prox -> ant = pivo;
			TEMP = pivo -> prox;
			pivo -> prox = aux -> prox;
			aux -> prox = TEMP;
					
			pivo -> ant -> prox = aux;
			aux -> ant -> prox = pivo;
			TEMP = pivo-> ant;
			pivo -> ant = aux -> ant;
			aux -> ant = TEMP;
			
			check = 1;
																		printf("\nTROCA 1-1 out\n");system("pause");
		}
		else if(pivo -> prox == aux) {
																		printf("\nTROCA 1-2 in\n");system("pause");
			pivo -> ant -> prox = aux;
			pivo -> prox = aux -> prox;
			aux -> prox -> ant = pivo;
			aux -> prox = pivo;
			aux -> ant = pivo -> ant;
			pivo -> ant = aux;
			
			check = 1;
																		printf("\nTROCA 1-2 out\n");system("pause");
		}
		else if(pivo -> prox == aux && aux -> prox == NULL) {
																		printf("\nTROCA 1-3 in\n");system("pause");
			pivo -> prox = aux -> prox;
			aux -> prox = pivo;
			pivo -> ant -> prox = aux;
			aux -> ant = pivo -> ant;
			pivo -> ant = aux;
			
			check = 1;
																		printf("\nTROCA 1-3 out\n");system("pause");
		}		
		else if(aux -> prox == NULL && pivo != aux) {
																		printf("\nTROCA 1-4 in\n");system("pause");
			pivo -> prox -> ant = aux;
			aux -> prox = pivo -> prox;
			pivo -> prox = NULL;
			
			pivo -> ant -> prox = aux;
			aux -> ant -> prox = pivo;
			TEMP = pivo-> ant;
			pivo -> ant = aux -> ant;
			aux -> ant = TEMP;
			
			check = 1;
																		printf("\nTROCA 1-4 out\n");system("pause");
		}
		
		show(list);
																		printf("\nPivo: %i", pivo -> valor);printf("\naux: %i", aux -> valor);printf("\nTEMP: %i\n\n", TEMP -> valor);system("pause");
	//============================== VERIFICAR SE H� ALGUM N� MAIOR A ESQUERDA ==============================
		TEMP = pivo -> ant;
		aux = pivo;
																		printf("\nPivo: %i", pivo -> valor);printf("\naux: %i", aux -> valor);printf("\nTEMP: %i\n\n", TEMP -> valor);system("pause");
		while(TEMP -> ant != list) {
			printf("\n\nwhile 2\n\n");
			if(TEMP -> valor > pivo -> valor && TEMP -> valor > aux -> valor || TEMP -> valor > aux -> valor && pivo != aux) {
				aux = TEMP;
			}
																		printf("\nPivo: %i", pivo -> valor);printf("\naux: %i", aux -> valor);printf("\nTEMP: %i\n\n", TEMP -> valor);system("pause");
			TEMP = TEMP -> ant;
																		printf("\nTEMP: %i\n", TEMP -> valor);system("pause");
			if(TEMP -> ant == list) {
				if(TEMP -> valor > pivo -> valor && TEMP -> valor > aux -> valor || TEMP -> valor > aux -> valor && pivo != aux) {
					aux = TEMP;
				}
			}
		}
		if(pivo -> ant != aux && pivo -> prox != NULL && pivo != aux) {
																		printf("\nTROCA 2-1 in\n");system("pause");
			pivo -> prox -> ant = aux;
			aux -> prox -> ant = pivo;
			TEMP = pivo -> prox;
			pivo -> prox = aux -> prox;
			aux -> prox = TEMP;
					
			pivo -> ant -> prox = aux;
			aux -> ant -> prox = pivo;
			TEMP = pivo-> ant;
			pivo -> ant = aux -> ant;
			aux -> ant = TEMP;
			
			check = 1;
																		printf("\nTROCA 2-1 out\n");system("pause");
		}
		else if(pivo -> ant == aux && pivo -> prox != NULL && pivo != aux) {
																		printf("\nTROCA 2-2 in\n");system("pause");
			aux -> ant -> prox = pivo;
			aux -> prox = pivo -> prox;
			pivo -> prox -> ant = aux;
			pivo -> prox = aux;
			pivo -> ant = aux -> ant;
			aux -> ant = pivo;
			
			check = 1;
																		printf("\nTROCA 2-2 out\n");system("pause");
		}
		else if(pivo -> ant == aux && pivo -> prox == NULL && pivo != aux) {
																		printf("\nTROCA 2-3 in\n");system("pause");
			aux -> prox = pivo -> prox;
			pivo -> prox = aux;
			aux -> ant -> prox = pivo;
			pivo -> ant = aux -> ant;
			aux -> ant = pivo;
			
			check = 1;
																		printf("\nTROCA 2-3 out\n");system("pause");
		}
		else if(pivo -> prox == NULL && pivo != aux) {
																		printf("\nTROCA 2-4 in\n");system("pause");
			aux -> prox -> ant = pivo;
			pivo -> prox = aux -> prox;
			aux -> prox = NULL;
			
			aux -> ant -> prox = pivo;
			pivo -> ant -> prox = aux;
			TEMP = aux-> ant;
			aux -> ant = pivo -> ant;
			pivo -> ant = TEMP;
			
			check = 1;
																		printf("\nTROCA 2-4 out\n");system("pause");
		}
		show(list);
		system("pause");
		
		TEMP = pivo -> prox;
		aux = pivo;
																		printf("\nPivo: %i", pivo -> valor);printf("\naux: %i", aux -> valor);printf("\nTEMP: %i\n\n", TEMP -> valor);system("pause");		
		
	//============================== VERIFICAR SE EST� ORDENADO ==============================
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
		printf("\n\nordenado = %i\n\n", ordenado);
		system("pause");
	}
	
	show(list);*/
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
				//inserir(list);
				atribuir(list);
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
