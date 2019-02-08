#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

struct baralho {
	int naipe, carta, peso, peso_naipe;
	
};
//struct baralho naipe[4] = {PAUS,COPAS,ESPADA,OURO};
//struct baralho carta[27] = {AS,DOIS,TRES,QUATRO,SETE,DAMA,VALETE,REI};

struct team1 {
	int player1;
	int player3;
};
struct team1 cartas1;

struct team2 {
	int player2;
	int player4;
};
struct team2 cartas2;

int i,j,n,vec[12]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},k;
int A,Q,J,K;
int PAUS,COPAS,ESPADA,OURO;

char jasorteado;

int opcao, round=3, qtde_sorteios=0 ;

char team() {
	/*
	//nome do primeiro jogador
	printf("Nome do time 1: ");
	//fflush(stdin);
	//gets(team1);
	
	//nome do segundo jogador
	printf("Nome do time 2: ");
	//fflush(stdin);
	//gets(team2);*/
}

void header() {
	/*
	system("cls");
	
	//screen header	
	printf("Player: %s", team1);
	printf("\tRound: %i", round);
	printf("\t\tPlayer: %s", team2);
	*/
}

void dar_cartas() {
	
	
}

void game() {
	
}

main() {
	
	//team();
	
	//header();
	
		//randomizar as cartas
		
		
//	for(j=0; j<=4; j++)  {
		srand(time(NULL));
		i=0;
		while(i<12) {
			n = rand() % 26;
			printf("\t -> %i",n);
			qtde_sorteios = qtde_sorteios + 1;
			jasorteado = 'n';
			for(k=0; k<12; k++) {
				if(vec[k] == n) {
					jasorteado = 's';
					//exit(1);
				}
			}
			if(jasorteado == 'n') {
				vec[i] = n;
				
				i++;
			}			
				
			printf("\tvalor de i = %i \n",i);
			printf("total de sorteios %i",qtde_sorteios);
		}
//	}
	
	switch(opcao) {
		case 1 : {
			game();
			
			break;
		}
		
		case 2 : {
		//	truco();
			
			break;
		}
		
		case 3 : {
		//	correr();
			
			break;
		}
		
		case 4 : {
	//		descartar();
			
			break;
		}
	}	
	
}
