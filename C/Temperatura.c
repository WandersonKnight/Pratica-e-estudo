#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	float celsius;
	float fahrenheit;
	
	printf("Digite o valor em Celsius desejado para a conversao em Fahrenheit - ");
	
	scanf("%g", &celsius);
	
	fahrenheit = (celsius * 1.8) + 32;
	
	printf("\nO valor em Farenheit e: %g", fahrenheit);
	
	return 0;
	
}
