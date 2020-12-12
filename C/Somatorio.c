#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	long int numero;
	long int soma = 0;
	int inicio = 1;
	
	printf("Digite um numero inteiro positivo, em seguida sera retornado o somatorio do numero e seus antecessores\n");
	
	while(1){
		
		scanf("%ld", &numero);
		
		if (numero > 0){
			
			break;
		
		}
		
		else {
			
			printf("Entrada invalida, tente novamente\n");
			
		}		
		
	}

    while (inicio <= numero){
		
		soma = soma + inicio;
		
		inicio++;
		
	}
	
	printf("A soma de todos os numeros ate o numero %ld e: %ld", numero, soma);
	
	return 0;
	
}