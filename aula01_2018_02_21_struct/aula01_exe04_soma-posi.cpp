#include <stdlib.h>
#include <stdio.h>

struct calculo {
	int number1;
	int number2;
	int soma;
};
struct calculo number[5];

int i;

int main() {
	for(i=0; i<=4; i++) {
		printf("Digite um numero do vetor number1: ");
		scanf("%d", &number[i].number1);
	}
	for(i=0; i<=4; i++) {
		printf("Digite um numero do vetor number2: ");
		scanf("%d", &number[i].number2);
		
		number[i].soma = number[i].number1 + number[i].number2;
	}
	
	printf("\nA soma dos vetores number1 e numer2 e:\n\n");
	for(i=0; i<=4; i++) {
		printf("%d ", number[i].soma);
	}
	return 0;
}

