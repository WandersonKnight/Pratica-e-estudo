#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila{
	
	int capacidade;
	int inicio;
	int fim;
	int quantidade;
	
	float *valores;

};

typedef struct fila fila;

void init(fila *fila, int capacidade){
	
	fila -> valores = (float*)malloc(sizeof(float) * capacidade);
	
	fila -> inicio = 0;
	fila -> fim = -1;
	fila -> quantidade = 0;
	fila -> capacidade = capacidade;
	
}

void insert(fila *fila, float valor){
	
	if(fila -> quantidade >= fila -> capacidade){
		
		printf("Fila cheia");
		
	}
	
	else{
		
		if(fila -> fim >= fila -> capacidade - 1){
			
			fila -> fim = -1;
			
		}
		
		fila -> fim += 1;
		
		fila -> valores[fila -> fim] = valor;
		fila -> quantidade += 1;
		
	}
	
}

float pop(fila *fila){
	
	float aux;
	
	if(fila -> inicio >= fila -> capacidade - 1){
		
		fila -> fim = 0;
		
	}
	
	aux = fila -> valores[fila -> inicio];
	
	fila -> inicio += 1;
	fila -> quantidade += 1;
	
	return aux;
	
}

int main(){
	
	fila teste;
	float temp;
	
	init(&teste, 6);
	
	insert(&teste, 2);
	printf("%.2f\n", teste.valores[teste.inicio]);
	
	insert(&teste, 54);
	printf("%.2f\n", teste.valores[teste.inicio]);
	printf("%.2f\n", teste.valores[teste.fim]);
	
	insert(&teste, 23);
	printf("%.2f\n", teste.valores[teste.inicio]);
	printf("%.2f\n", teste.valores[teste.fim]);
	
    temp = pop(&teste);
	printf("%.2f\n", teste.valores[teste.inicio]);
	printf("%.2f\n", teste.valores[teste.fim]);
	printf("%.2f\n", temp);
	
	return 0;
	
}


