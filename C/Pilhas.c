#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pilha{
	
	int topo;
	int capacidade;
	float *valores;
	
};

typedef struct pilha pilha;


// Functions

void init(pilha *pilha, int capacidade){
	
	pilha -> valores = (float*)malloc(sizeof(float) * capacidade);
	pilha -> topo = -1;
	pilha -> capacidade = capacidade;
	
}
	
void push(pilha *pilha, float valor){
	
	if(pilha -> topo >= (pilha -> capacidade - 1)){
		
		printf("Limite da pilha excedido");
		
	}
	
	else{
		
		pilha -> topo++;
		pilha -> valores[pilha -> topo] = valor;
	
	}

}

float pop(pilha *pilha){

    float aux;
	aux = pilha -> valores[pilha -> topo];
    pilha -> topo--;
	
	return aux;
	
}

void check(pilha *pilha){
	
	if(pilha -> topo == -1){
		
		printf("Pilha vazia");
		
	}
	
	else{
		
		printf("Pilha disponivel para o uso");
		
	}
	
}

int main(){
	
	pilha teste;
	float demo;
	
	init(&teste, 6);
	
	push(&teste, 2);
	printf("%.1f\n", teste.valores[teste.topo]);
	
	push(&teste, 5);
	printf("%.1f\n", teste.valores[teste.topo]);
	
	demo = pop(&teste);
	printf("%.1f\n", teste.valores[teste.topo]);
	printf("%.1f\n", demo);
	
	check(&teste);
	
	free(teste);
	
	return 0;
	
}
	
	
	
	
	
	
	
	
	
	