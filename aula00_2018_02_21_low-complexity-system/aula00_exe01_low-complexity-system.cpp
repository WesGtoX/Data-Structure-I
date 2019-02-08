// library
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

// variables
int opcao,i=1, fb=0, n=0, qtd=0, cons, d;
char feed, controle;

// vector of register
char name[100][50];
char address[100][50];
char cpf[100][50];
char rg[100][50];
char phone[100][50]; 
char email[100][50];


void header() {
	// screen menu
	printf("::::::::::::::::::::::::::::::::::::::::::\n");
	printf(":.\t LOW COMPLEXITY SYSTEM \t\t.:\n");
	printf("::::::::::::::::::::::::::::::::::::::::::\n\n");
}

main() {
	while(i != 0) {		
		system("cls");		// clean the screen
				
		header();		// screen menu
	
		// info
		printf("1 - CADASTRAR CLIENTE\n2 - CONSULTAR CLIENTE\n3 - REMOVER CLIENTE\n4 - IMPRIMIR TUDO\n0 - SAIR\n\n");
		printf("O que deseja fazer? ");
		scanf("%i", &opcao);
		
		if(opcao > 4) {
			system("cls");
			
			header();
			
			printf("\nOpcao invalida! Tente novamente.\n\n");
		}

		switch(opcao) {
			
			case 1 : {		// client registration
				do {
					system("cls");		// clean the screen
					
					header();		// screen menu
					
					printf("- CADASTRO DE CLIENTE -\n\n");
					
					printf("Nome Completo: \n");
					fflush(stdin);
					scanf("%s", &name[n]);
					
					printf("\nEndereco: \n");
					fflush(stdin);
					scanf("%s", &address[n]);
					
					printf("\nCPF: \n");
					fflush(stdin);
					scanf("%s", &cpf[n]);
					
					printf("\nRG: \n");
					fflush(stdin);
					scanf("%s", &rg[n]);
					
					printf("\nTelefone: \n");
					fflush(stdin);
					scanf("%s", &phone[n]);
					
					printf("\nE-mail: \n");
					fflush(stdin);
					scanf("%s", &email[n]);
					
					n++;
					qtd++;
					
					// what to do now?
					printf("Cadastrar outro cliente? <S/N>: ");
					controle = getche();
				
				} while(toupper(controle)=='S');
				break;
			}
			
			case 2 : {		// customer inquiry

				do {
					system("cls");		// clean the screen
				
					header();		// screen menu

					printf("- CONSULTA DE CLIENTE -\n\n");
					
					printf("Digite o numero do cliente que deseja consultar: ");
					scanf("%i", &cons);
					
					// show the specific client
					if(cons < qtd) {
						printf("\n\nCliente %i: ", cons);
						printf("\n------------\n");
						
						printf("Nome Completo: %s", name[cons]);
						printf("\nEndereco: %s", address[cons]);
						printf("\nCPF: %s", cpf[cons]);
						printf("\nRG: %s", rg[cons]);
						printf("\nTelefone: %s", phone[cons]);
						printf("\nE-mail: %s\n", email[cons]);
					}
					else {		// if the client doesn't exist, show th message
						printf("\nCliente nao existente!\n");
					}
					
					// what to do now?
					printf("\nConsultar outro cliente? <S/N> ");
					controle = getche();

				} while(toupper(controle)=='S');
				break;
			}
			
			case 3 : {		// client delete
				do {
					system("cls");		// clean the screen
				
					header();		// screen menu

					printf("- REMOVER CLIENTE -\n\n");
									
					printf("Digite o numero do cliente que deseja excluir: ");
					scanf("%i", &d);
					
					if(cons < qtd) {		// deleate de client
						printf("\nCliente excluido com sucesso!\n");
						
						memset(&name[d], 0, sizeof (name[d]));
						memset(&address[d], 0, sizeof (address[d]));
						memset(&cpf[d], 0, sizeof (cpf[d]));
						memset(&rg[d], 0, sizeof (rg[d]));
						memset(&phone[d], 0, sizeof (phone[d]));
						memset(&email[d], 0, sizeof (email[d]));
					}
					else {		// if the client doesn't exist, show th message
						printf("\nCliente nao existente!\n");
					}
					
					// what to do now?
					printf("\nExcluir outro cliente? <S/N> ");
					controle = getche();

				} while(toupper(controle)=='S');
				break;
			}
			
			case 4 : {		// list all clients
				system("cls");		// clean the screen
				
				header();		// screen menu
				
				printf("- LISTA DE CLIENTES -\n\n");
				
				n=0;
				
				do {		// print all client on the screen, even the deleted
					while(n < qtd) {
						printf("Cliente %i: ", n);
						printf("\n------------\n");
						
						printf("Nome Completo: %s", name[n]);
						printf("\nEndereco: %s", address[n]);
						printf("\nCPF: %s", cpf[n]);
						printf("\nRG: %s", rg[n]);
						printf("\nTelefone: %s", phone[n]);
						printf("\nE-mail: %s\n\n", email[n]);
						
						n++;
					}
					
					printf("\nPrecione qualquer tecla para voltar para o menu: ");
					controle = getche();

				} while(toupper(controle)=='$');
				break;
			}
			
			case 0 : {		// leave the system
				system("cls");		// clean the screen
				
				header();		// screen menu
				
				// please choose YES! :)
				printf("\nPoderia deixar um feedback sobre o nosso sistema? <S/N> ");
				feed  = getche();
					
				if(toupper(feed == 'S' || 's')) {		// system feedback
					printf("\n\nO que achou sobre o nosso sistema?\n\n");
					printf("1 - RUIM\n2 - REGULAR\n3 - BOM\n4 - MUITO BOM\n5 - OTIMO");
					printf("\n\nQual o seu feedback? ");
					scanf("%i", &fb);
					
					switch(fb) {		// messages
						case 1 : {
							printf("\n\nVamos nos esforcar muito para melhorar isso!");
							break;
						}
						case 2 : {
							printf("\n\nAcho que estamos no caminho!");
							break;
						}
						case 3 : {
							printf("\n\n:)");
							break;
						}
						case 4 : {
							printf("\n\n:D");
							break;
						}
						case 5 : {
							printf("\n\nIsso nos faz querer melhorar cada dia mais!!!! :D");
							break;
						}
					}
					
					printf("\n\n------------------------\n");
					printf("Obrigado por usar o LCS!\n");
					printf("------------------------\n\n");
				}
				else {
					printf("\n\n------------------------\n");
					printf("Obrigado por usar o LCS!\n");
					printf("------------------------\n\n");
				}
				break;
			}
		}
		i = opcao;
	}
	
	system("pause");
}
