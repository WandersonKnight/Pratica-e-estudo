#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int *vetor;
	int i;
	int elementos;
	
	printf("Informe o tamanho desejado para o vetor. O valor necessita ser positivo e inteiro\n");
	
	while(1){
		
		scanf("%d", &elementos);
		
		if (elementos > 0){
			
			vetor = (int *)malloc(elementos * sizeof(int));
			
			break;
			
		}
		
		else{
			
			printf("Valor invalido. Utilize um numero inteiro positivo\n");
		
		}
		
	}
	
	printf("Os valores armazenados no vetor sao:\n");
	
	for (i = 0; i < elementos; i++){
		
		vetor[i] = i;
		
		printf("%d\n", vetor[i]);
		
	}
	
	free(vetor);
		
	
    return 0;

}	

