void ordenacres(cad *list) {
	
	cad *TEMP1 = list -> prox;
	cad *TEMP2 = TEMP1 -> prox;
	
	while(TEMP1 -> prox != NULL && TEMP2 -> prox != NULL) {
		while(TEMP1 -> valor > TEMP2 -> valor && TEMP1 -> prox != NULL) {
			if(TEMP1 -> valor > TEMP2 -> valor && TEMP2 -> prox != NULL) {
				//printf("\nteste 0\n");
				TEMP1 -> ant -> prox = TEMP2;
				TEMP1 -> prox = TEMP2 -> prox;
				TEMP2 -> prox -> ant = TEMP1;
				TEMP2 -> prox = TEMP1;
				TEMP2 -> ant = TEMP1 -> ant;
				TEMP1 -> ant = TEMP2;
				/*show(list);
				printf("\nteste 1\n");
				system("pause");*/
			}
			TEMP2 = TEMP1 -> prox;
			/*printf("\nteste 2\n");
			system("pause");*/
			
			if(TEMP1 -> prox -> prox == NULL && TEMP1 -> valor > TEMP2 -> valor) {
				TEMP1 -> ant -> prox = TEMP2;
				TEMP1 -> prox = TEMP2 -> prox; //nulo
				TEMP2 -> prox = TEMP1;
				TEMP2 -> ant = TEMP1 -> ant;
				TEMP1 -> ant = TEMP2;
				//TEMP1 -> prox -> ant = TEMP1;
				
				TEMP1 = list -> prox;
				TEMP2 = TEMP1 -> prox;
				
				/*show(list);
				printf("\nteste 3\n");
				system("pause");*/
				
			}
			else if(TEMP2 -> prox != NULL && TEMP1 -> valor < TEMP2 -> valor) {
				TEMP1 = TEMP2;
				TEMP2 = TEMP1 -> prox;
			}
			else {
				TEMP1 = list -> prox;
				TEMP2 = TEMP1 -> prox;
				//printf("\nteste 5\n");
			}

			/*show(list);
			printf("\nteste 6\n");
			printf("Valor de TEMP1: %d\n", TEMP1 -> valor);
			printf("Valor de TEMP2: %d\n", TEMP2 -> valor);
			system("pause");*/
		}
		while(TEMP2 -> prox != NULL && TEMP1 -> valor < TEMP2 -> valor) {
			TEMP1 = TEMP2;
			TEMP2 = TEMP1 -> prox;
		}
	}
	TEMP1 = list -> prox;
	TEMP2 = TEMP1 -> prox;
	//printf("\nteste 7\n");
	
	show(list);
	printf("Valor de TEMP1: %d\n", TEMP1 -> valor);
	printf("Valor de TEMP2: %d\n", TEMP2 -> valor);
	system("pause");
}
