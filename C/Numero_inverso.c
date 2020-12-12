#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char numero[100];
	char temp;
	int inicio;
	int fim;

	printf("Digite uma sequencia numerica a ser invertida\n");
	
	scanf("%s", numero);
	
	inicio = 0;
	fim = strlen(numero) - 1;
	
	while (inicio < fim){
		
		temp = numero[inicio];
		numero[inicio] = numero[fim];
		numero[fim] = temp;
		
		inicio++;
		fim--;
		
	}
	
	printf("O resultado da inversao e: %s", numero);

	return 0;
	
}