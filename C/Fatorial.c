#include <stdio.h>
#include <stdlib.h>

int main(){
	
	long long int i;
	long long int temp = 1;
	long long int num;
	
	printf("Digite um valor para ser realizado o fatorial\n");
	
    scanf("%lld", &num);
	
	for(i = 1; i <= num; i++){
		
		temp = temp * i;
		
	}
	
	printf("O resultado da fatorial de %lld e: %lld", num, temp);
	
	return 0;
	
}