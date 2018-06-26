#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
 
int tempo_total = 500;  //tempo em milisegundos
float progresso = 0;
 
int main(){
 
	printf("Carregando... ");
	printf("\n");
	 
	while(progresso < 100) {
		progresso = progresso + 5; //A cada 5% a barra de progresso será atualizada
		Sleep(tempo_total);
		 
		printf("\xB2");
	}
}
