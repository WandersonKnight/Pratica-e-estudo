#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "omp.h"

int main(int argc, char **argv){
	
	int num;
	int i;
	int num_th;
	int alo;
	long long int soma = 1;
	
	printf("Digite o valor que deseja realizar o fatorial\n");
	scanf("%d", &num);
	
	printf("Digite o numero de threads que deseja, entre 2 e 6\n");
	scanf("%d", &num_th);

	omp_set_num_threads(num_th);
	
	#pragma omp parallel for reduction(*:soma)
	for(i = 1; i <= num; i++){
	
		soma = soma * i;
		
	}
	
	printf("O resultado e %lld", soma);
	
	return 0;
	
}