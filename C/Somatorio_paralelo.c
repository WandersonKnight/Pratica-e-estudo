#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "omp.h"

int main(int argc, char **argv){
	
	long int soma = 0;
	int num_th;
	int i;
	
	printf("Este programa realiza o somatorio de 10000 paralelamente\n");
	
	printf("Digite o numero de threads que deseja, entre 2 e 6\n");
	scanf("%d", &num_th);
	
	omp_set_num_threads(num_th);
	
	#pragma omp parallel for reduction(+:soma)
	for(i = 1; i <= 10000; i++){
	
		soma += i;
		
	}
	
	printf("A soma e %ld", soma);
	
	return 0;
	
}