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
int vetor[10] = {3,5,0,2,9,7,4,1,8,6}, n=0; //TEMP
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
		//count++;
			
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
	
	x = rand() % 10;
	
	return x;
}

//function ordenacres
void ordenacres(cad *list) {
	//local variables
	int p, j=0, n, m, verify=0, ordenado=0, check=0;
	int vector[count];
	
	/*printf("Vector: ");
	for(m=0; m < count; m++) {
		vector[m] = 'n';
		printf("%i ", vector[m]);
	}
	printf("\n");
	system("pause");*/
	
	cad *pivo;
	
	cad *TEMP;
	cad *aux;
	cad *TEMP2;
	cad *ord;
	
	while(ordenado == 0) {
		if(check == 0) {
	//============================== ESCOLHER O PIVO ==============================			
			pivo = list -> prox;

			show(list);

			printf("\nEscolha o pivo: ");
			scanf("%i", &p);
			
	//============================== PIVO RANDOM (EM TESTE) ==============================
	/*		while(verify == 0) {
				verify = 1;
				
				p = random();
				
				for(n=0; n < count; n++) {
					if(p == vector[n]) {
						verify = 0;
					}
				}
				if(verify == 1) {
					vector[j] = p;
					j++;
				}
			}
			verify = 0;
	*/
	//============================== PIVO RANDOM (FIM) ==============================

			while(pivo -> valor != p) {
				pivo = pivo -> prox;
			}
			TEMP = pivo -> prox;
			aux = pivo;
		}
		
	check = 0;		
	//============================== VERIFICAR SE HÁ ALGUM Nº MENOR A DIREITA ==============================
		while(TEMP -> prox != NULL) {
			//printf("\n\nwhile 1\n\n");
			if(TEMP -> valor < pivo -> valor && TEMP -> valor < aux -> valor || TEMP -> valor < aux -> valor && pivo != aux) {
				aux = TEMP;
			}
			TEMP = TEMP -> prox;
			
			if(TEMP -> prox == NULL) {
				if(TEMP -> valor < pivo -> valor && TEMP -> valor < aux -> valor || TEMP -> valor < aux -> valor && pivo != aux) {
					aux = TEMP;
				}
			}
		}
		if(pivo -> prox != aux && aux -> prox != NULL && pivo != aux) {
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
		}
		else if(pivo -> prox == aux) {
			pivo -> ant -> prox = aux;
			pivo -> prox = aux -> prox;
			aux -> prox -> ant = pivo;
			aux -> prox = pivo;
			aux -> ant = pivo -> ant;
			pivo -> ant = aux;
			
			check = 1;
		}
		else if(pivo -> prox == aux && aux -> prox == NULL) {
			pivo -> prox = aux -> prox;
			aux -> prox = pivo;
			pivo -> ant -> prox = aux;
			aux -> ant = pivo -> ant;
			pivo -> ant = aux;
			
			check = 1;
		}		
		else if(aux -> prox == NULL && pivo != aux) {
			pivo -> prox -> ant = aux;
			aux -> prox = pivo -> prox;
			pivo -> prox = NULL;
			
			pivo -> ant -> prox = aux;
			aux -> ant -> prox = pivo;
			TEMP = pivo-> ant;
			pivo -> ant = aux -> ant;
			aux -> ant = TEMP;
			
			check = 1;
		}
	//============================== VERIFICAR SE HÁ ALGUM Nº MAIOR A ESQUERDA ==============================
		TEMP = pivo -> ant;		aux = pivo;
		while(TEMP -> ant != list) {
			if(TEMP -> valor > pivo -> valor && TEMP -> valor > aux -> valor || TEMP -> valor > aux -> valor && pivo != aux) {
				aux = TEMP;			
			}
			TEMP = TEMP -> ant;
			if(TEMP -> ant == list) {
				if(TEMP -> valor > pivo -> valor && TEMP -> valor > aux -> valor || TEMP -> valor > aux -> valor && pivo != aux) {
					aux = TEMP;
				}
			}
		}
		if(pivo -> ant != aux && pivo -> prox != NULL && pivo != aux) {
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
		}
		else if(pivo -> ant == aux && pivo -> prox != NULL && pivo != aux) {
			aux -> ant -> prox = pivo;
			aux -> prox = pivo -> prox;
			pivo -> prox -> ant = aux;
			pivo -> prox = aux;
			pivo -> ant = aux -> ant;
			aux -> ant = pivo;
			
			check = 1;
		}
		else if(pivo -> ant == aux && pivo -> prox == NULL && pivo != aux) {
			aux -> prox = pivo -> prox;
			pivo -> prox = aux;
			aux -> ant -> prox = pivo;
			pivo -> ant = aux -> ant;
			aux -> ant = pivo;
			
			check = 1;
		}
		else if(pivo -> prox == NULL && pivo != aux) {
			aux -> prox -> ant = pivo;
			pivo -> prox = aux -> prox;
			aux -> prox = NULL;
			
			aux -> ant -> prox = pivo;
			pivo -> ant -> prox = aux;
			TEMP = aux-> ant;
			aux -> ant = pivo -> ant;
			pivo -> ant = TEMP;
			
			check = 1;
		}
		
		TEMP = pivo -> prox;		
		aux = pivo;
		
	//============================== VERIFICAR SE ESTÁ ORDENADO ==============================
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
