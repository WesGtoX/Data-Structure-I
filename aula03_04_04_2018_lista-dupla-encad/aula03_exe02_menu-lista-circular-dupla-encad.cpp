//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//data struct declare
struct number {
	struct number *prox;
	struct number *ant; //lista duplamente encadeada
	int valor;
	char nome[30];
};
typedef struct number cad;

void inserir_fim(cad *list) { // OK
	cad *novo = (cad *)malloc(sizeof(cad));
	
	printf("Informe seu nome: "); //name register
	fflush(stdin);
	gets(novo -> nome);
	
	printf("Informe o valor: "); //number register
	scanf("%d", &novo -> valor);

	novo -> prox = list;
	novo -> ant = list;

	if(list -> prox == list) {
		list -> prox = novo;
		list -> ant = novo;
	}
	else {
		cad *TEMP = list -> prox;
		 
		while(TEMP -> prox != list) {
			TEMP = TEMP -> prox;
		}
		TEMP -> prox = novo;
		novo -> ant = TEMP;
		list -> ant = novo;
	}
	printf("\nADICIONADO NO FIM DA FILA!!!\n\n");
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void show_all(cad *list) { //OK
	if(list -> prox == list) {
		printf("LISTA VAZIA!!\n\n");
	}
	else {
		cad *TEMP = list -> prox;
		while(TEMP -> prox != list) {			
			printf("Nome: %s\n", TEMP -> nome);
			printf("Valor: %d\n\n", TEMP -> valor);
			
			TEMP = TEMP -> prox;
		}
		printf("Nome: %s\n", TEMP -> nome);
		printf("Valor: %d\n\n", TEMP -> valor);
	}
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void show_specific(cad *list) {
	int search, i, opcao;
	char seek[30], control;
	
	if(list -> prox == NULL) {
		system("cls");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("::::::::::::. IMPRIMIR ESPECIFICO .:::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
		printf("LISTA VAZIA!!");
	}
	else {
		do {
			system("cls");
			printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
			printf("::::::::::::. IMPRIMIR ESPECIFICO .:::::::::::\n");
			printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
			
			printf("\n1 - Mostrar por Nome");
			printf("\n2 - Mostrar por Valor");
			printf("\n0 - Voltar para o Menu");
			
			printf("\n\nEscolha uma opcao: ");
			scanf("%d", &opcao);
			
			i = 0;
			
			switch(opcao) {
				case 1 : {
					//show with name
					system("cls");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
					printf("::::::::::::. IMPRIMIR ESPECIFICO .:::::::::::\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					
					printf("Insira o nome procurado: ");
					fflush(stdin);
					gets(seek);
					
					cad *TEMP = list -> prox;
					
					while(TEMP != list) {
						if(strcmp(seek,TEMP -> nome) == 0) {
							printf("\nNome: %s\n", TEMP -> nome);
							printf("Valor: %d\n", TEMP -> valor);
							i++;
						}
						TEMP = TEMP -> prox;
					}
					if(i == 0) {
						printf("\nESTE NOME NAO EXISTE!!\n");
					}
					break;
				}
				case 2 : {
					//show value
					system("cls");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
					printf("::::::::::::. IMPRIMIR ESPECIFICO .:::::::::::\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					
					printf("Insira o valor procurado: ");
					scanf("%d", &search);
					
					cad *TEMP = list -> prox;
					
					while(TEMP != list) {
						if(search == TEMP -> valor) {
							printf("\nNome: %s\n", TEMP -> nome);
							printf("Valor: %d\n", TEMP -> valor);
							i++;
						}
						TEMP = TEMP -> prox;
					}
					if(i == 0) {
						printf("\nESTE VALOR NAO EXISTE!!\n");
					}
					break;
				}
				case 0 : {
					system("cls");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
					printf("::::::::::::. IMPRIMIR ESPECIFICO .:::::::::::\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					
					printf("\n\tVOLTANDO PARA O MENU...");
					break;
				}
			}
			if(opcao != 0) {	
				printf("\nDeseja procurar outro? <S/N> ");
				control = getche();
			}
		} while(toupper(control) == 'S');
	}
	
	printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void inserir_inicio(cad *list) {
	cad *novo = (cad *)malloc(sizeof(cad));
	
	if(!novo) {
		printf("Nao ha memoria disponivel");
		exit(1);
	}
	else { //preenchimento de valor
		printf("Informe seu nome: "); //name register
		fflush(stdin);
		gets(novo -> nome);
		
		printf("Informe o valor: "); //number register
		scanf("%d", &novo -> valor);
	}
	
	if(list -> prox != list) {
		novo -> prox = list -> prox;
		list -> prox -> ant = novo;
	}
	else {
		novo -> prox = list;
		list -> ant = novo;
	}
	list -> prox = novo;
	novo -> ant = list;
		
	printf("\nADICIONADO NO INICIO DA FILA!!!\n\n");
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void remove_first(cad *list) { //OK
	if(list -> prox == list) {
		printf("LISTA VAZIA!!\n\n");
	}
	else {		
		cad *TEMP = list -> prox;
		
		list -> prox = TEMP -> prox;
		TEMP -> prox -> ant = TEMP -> ant;
		
		free(TEMP);
		
	printf("REMOVIDO!!!\n\n");
	}
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void remove_all(cad *list) { //EDITAR
	if(list -> prox == list) {
		printf("LISTA VAZIA!!\n\n");
	}
	else {
		cad *TEMP = list -> prox;
		
		while(TEMP -> prox != list) {
			TEMP = TEMP -> prox;
			free(TEMP -> ant);
		}
		free(TEMP);
		list -> prox = list;
		list -> ant = list;
		
	printf("TODOS FORAM REMOVIDOS!!!\n\n");
	}
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void remove_specific(cad *list) {
	int search, i, opcao;
	char seek[30], control;
	
	if(list -> prox == list) {
		system("cls");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::. REMOVER ESPECIFICO .:::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
		printf("LISTA VAZIA!!\n\n");
	}
	else {
		do {
			system("cls");
			printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
			printf(":::::::::::::. REMOVER ESPECIFICO .:::::::::::\n");
			printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
			
			printf("\n1 - Remover por Nome");
			printf("\n2 - Remover por Valor");
			printf("\n0 - Voltar para o Menu");
			
			printf("\n\nEscolha uma opcao: ");
			scanf("%d", &opcao);
			
			i = 0;

			switch(opcao) {
				case 1 : {
					//remove with name
					system("cls");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
					printf(":::::::::::::. REMOVER ESPECIFICO .:::::::::::\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					
					printf("Insira o nome que deseja remover: ");
					fflush(stdin);
					gets(seek);
					
					cad *TEMP = list -> prox;
					
					if(strcmp(seek,TEMP -> nome) == 0) {
						list -> prox = TEMP -> prox;
						TEMP -> prox -> ant = list;
						free(TEMP);
						i++;
					}
					else {
						while(TEMP != list && strcmp(TEMP -> nome,seek) != 0) {
							TEMP = TEMP -> prox;
						}
						if(TEMP != list) {
							TEMP -> ant -> prox = TEMP -> prox;
							free(TEMP);
							i++;
						}
					}
					if(i == 0) {
						printf("\nESTE NOME NAO EXISTE!!\n");
					}
					break;
				}
				case 2 : {
					//remove value
					system("cls");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
					printf(":::::::::::::. REMOVER ESPECIFICO .:::::::::::\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					
					printf("Insira o valor que deseja remover: ");
					scanf("%d", &search);
					
					cad *TEMP = list -> prox;
					
					if(search == TEMP -> valor) {
						list -> prox = TEMP -> prox;
						TEMP -> prox -> ant = list;
						free(TEMP);
						i++;
					}
					else {
						while(TEMP != list && TEMP -> valor != search) {
							TEMP = TEMP -> prox;
						}
						if(TEMP != list) {
							TEMP -> ant -> prox = TEMP -> prox;
							free(TEMP);
							i++;
						}
					}
					if(i == 0) {
						printf("\nESTE VALOR NAO EXISTE!!\n");
					}
					break;
				}
				case 0 : {
					//back to menu
					system("cls");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
					printf("::::::::::::. IMPRIMIR ESPECIFICO .:::::::::::\n");
					printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
					
					
					printf("\n\tVOLTANDO PARA O MENU...");
					break;
				}
			}
			if(i != 0) {
				printf("\nREMOVIDO!!!\n");
			}
			if(opcao != 0) {	
				printf("\nDeseja procurar outro? <S/N> ");
				control = getche();
			}
		} while(toupper(control) == 'S');
	}
	
	printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

show_invert(cad *list) {
	if(list -> prox == list) {
		printf("LISTA VAZIA!!\n\n");
	}
	else {
		cad *TEMP = list -> ant;
		while(TEMP -> ant != list) {			
			printf("Nome: %s\n", TEMP -> nome);
			printf("Valor: %d\n\n", TEMP -> valor);
			
			TEMP = TEMP -> ant;
		}
		printf("Nome: %s\n", TEMP -> nome);
		printf("Valor: %d\n\n", TEMP -> valor);
	}
	
	printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
	system("pause");
}

void menu(cad *list) {
	int opcao, i=0;
	
	system("cls");
	
	while(i == 0) {
		system("cls");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::::::::. MENU .:::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		
		printf("\n1 - Inserir");
		printf("\n2 - Imprimir Todos");
		printf("\n3 - Imprimir Especifico");
		printf("\n4 - Inserir Prioritario");
		printf("\n5 - Remover o Primeiro");
		printf("\n6 - Remover Todos");
		printf("\n7 - Remover Especifico");
		printf("\n8 - Imprimir Invertido");
		printf("\n0 - Sair");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1 : {
				//inserir fim
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf(":::::::::::::. INSERIR NO INICIO .::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				inserir_fim(list);
				break;
			}
			case 2 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR TODOS .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				show_all(list);
				break;
			}
			case 3 : {
				//imprimir especifico				
				show_specific(list);
				break;
			}
			case 4 : {
				//inserir no inicio
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf(":::::::::::::. INSERIR NO INICIO .::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				inserir_inicio(list);
				break;
			}
			case 5 : {
				//remover primeiro
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::. REMOVER O PRIMEIRO .::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				remove_first(list);
				break;
			}
			case 6 : {
				//remover todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. REMOVER TODOS .:::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				remove_all(list);
				break;
			}
			case 7 : {
				//remover especifico
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::. REMOVER ESPECIFICO .::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				remove_specific(list);
				break;
			}
			case 8 : {
				//imprimir invertido
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR TODOS .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				show_invert(list);
				break;
			}
			case 0 : {
				//sair
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. SAINDO DO MENU .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				printf("\tSAINDO...\n");
								
				exit(1);
				break;
			}
		}
	}
	
	system("pause");
}

int main() { 
	cad *list = (cad *)malloc(sizeof(cad));
	list -> prox = list;
	list -> ant = list;
	
	menu(list);
}
