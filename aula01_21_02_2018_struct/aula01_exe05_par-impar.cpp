#include <stdlib.h>
#include <stdio.h>

int i, x=0, y=0;

struct parImpar {
	int number;
	int par;
	int impar;
};
struct parImpar number[8];

int main() {
	for(i=0; i<=7; i++) {
		printf("Digite um numero do vetor number: ");
		scanf("%d", &number[i].number);
	}
	
	//verificar numeros pares
	for(i=0; i<=7; i++) {
		if((number[i].number % 2) == 0) {
			number[i].par = number[i].number;
		}
		else {
			number[i].impar = number[i].number;
		}
	}
	
	printf("\nPares: ");
	for(i=0; i<=7; i++) {
		if((number[i].par % 2) == 0 && number[i].par != 0) {
			printf("%d ", number[i].par);
		}
	}
	
	printf("\nImpares: ");
	for(i=0; i<=7; i++) {
		if((number[i].impar % 2) == 1) {
			printf("%d ", number[i].impar);
		}
	}

	return 0;
}

/*
	//print pares
	printf("Pares: ");
	for(i=0; i<=x; i++) {
		printf("%d ", number[i].par);
	}
	
	printf("\n");
	
	//verificar numeros impares
	for(i=0; i<=7; i++) {
		if((number[i].number % 2) == 1) {
			number[i].impar = number[i].number;
			n++;
		}
	}
	
	//print impares
	printf("Impares: ");
	for(i=0; i<=y; i++) {
		printf("%d ", number[i].impar);
	} */
