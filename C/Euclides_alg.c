#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	
	int num1;
	int num2;
	int resto;
	
	printf("Este programa realiza o calculo de mdc entre dois numeros inteiros diferentes de 0\n"
	        "utilizando o Algoritmo de Euclides\n\n");
	
	while(1){
	
		printf("Digite o primeiro numero\n");
		scanf("%d", &num1);
	
		printf("Digite o segundo numero\n");
		scanf("%d", &num2);
	
		if(num1 != 0 && num2 != 0){
		
			while(num2 != 0){
			
				resto = num1 % num2;
				num1 = num2;
				num2 = resto;
			
			}
			
		    printf("O resultado do mdc e: %d", num1);
			
			break;
		
		}
		
		else{
			
			printf("Erro. Utilize um numero diferente de zero\n");
		
		}
		
	}
	
    return 0;
	
}