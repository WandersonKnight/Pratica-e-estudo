#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int inicio = 1;
	long int soma = 0;

	printf("Este programa exibe o resultado da somatoria de 10000, cuja formula e: (a1 + an)*n/2\n");
	
	while(inicio <= 10000){
		
		soma = soma + inicio;
		
		inicio++;
		
	}
	
	printf("A somatoria de 10000 e: %ld", soma);
	
    return 0;
	
}