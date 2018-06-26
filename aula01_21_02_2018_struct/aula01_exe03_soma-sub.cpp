#include <stdlib.h>
#include <stdio.h>

struct calculo {
	int number;
};
struct calculo number[5];

int i, soma, sub;

int main() {
	for(i=0; i<=4; i++) {
		printf("Digite um numero do vetor number: ");
		scanf("%d", &number[i].number);
	}
	
	for(i=0; i<=4; i++) {
		soma+= number[i].number;
	}
	
	for(i=3; i>=0; i--) {
		sub-= number[i].number;
	}
	
	sub+= number[4].number;
	
	printf("\nSoma: %d", soma);
	printf("\nSubtracao: %d", sub);
	
	
	return 0;
}

