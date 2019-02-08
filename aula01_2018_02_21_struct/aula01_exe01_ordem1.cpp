#include <stdlib.h>
#include <stdio.h>

struct calculo {
	int number;
};
struct calculo number[5] = {7,3,8,1,6};

int i;

int main() {
	for(i=0; i<=4; i++) {
		printf("%d ", number[i].number);
	}
	printf("\n");
	for(i=4; i>=0; i--) {
		
		printf("%d ", number[i].number);
	}
	
	return 0;
}

