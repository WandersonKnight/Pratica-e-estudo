#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "omp.h"

int main(int argc, char **argv){
	
	long int soma = 0;
	int num;
	int num_th;
	int tid;
	int i;
	
	printf("Digite o valor que deseja realizar o somatorio\n");
	scanf("%d", &num);
	
	printf("Digite o numero de threads que deseja, entre 2 e 6\n");
	scanf("%d", &num_th);
	
	omp_set_num_threads(num_th);
	
	#pragma omp parallel for reduction(+:soma)
	for(i = 1; i <= num; i++){
			
		tid = omp_get_thread_num();

		soma += i;
		
		printf("%ld = %d\n", soma, tid);
		
	}
	
	printf("O somatorio e %ld", soma);
	
	return 0;
	
}