#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TSize 10

struct person{
	
	char name[40];
	int age;
	
};

typedef struct person person;

// Criar hash function

unsigned long int hash_function(char *string){
	
	int lenght = strlen(string);
	unsigned long int hash_key = 0;
	
	for(int i = 0; i < lenght; i++){
		
		hash_key += string[i];
		
	}
	
	hash_key =  hash_key * 11 % TSize;
	
	return hash_key;
	
}

// Functions sobre a hash table

void init(person **hash){
	
	for(int i = 0; i < TSize; i++){
		
		hash[i] = NULL;
		
	}
	
}

void insert(person **hash, person *insert){
	
	int index = hash_function(insert -> name);
	int aux;
	
    for(int i = 0; i < TSize; i++){

        aux = (index + i) % TSize;
		
		if(hash[aux] == NULL){
			
			hash[aux] = insert;
		    return;
			
		}
		
	}
	
	printf("Lista cheia\n");

}


void pop(person **hash, char *string){
	
	int index = hash_function(string);
	int aux;

	for(int i = 0; i < TSize; i++){
		
		aux = (index + i) % TSize;
		
		if(hash[aux] != NULL && strcmp(hash[aux] -> name, string) == 0){
			
			hash[aux] = NULL;
			return;
			
		}
		
	}
	
	printf("Nome nao encontrado");
	
}

void print_hash(person **hash){
	
	for(int i = 0; i < TSize; i++){
		
		if(hash[i] != NULL){
			
			printf("%d -> %s\n", i, hash[i] -> name);
			
		}
		
		else{
			
			printf("%d -> NULL\n", i);
			
		}
		
	}

}

person *lookup(char *string, person **hash){
	
	int index = hash_function(string);
	int aux;
	
	for(int i = 0; i < TSize; i++){
		
		aux = (index + i) % TSize;

		if(hash[aux] != NULL && strcmp(hash[aux] -> name, string) == 0){
		
		    return hash[aux];
		
	    }
		
    }
	
	return NULL;
	
}

int main(){
	
	person Carlos = {.name = "Carlos", .age = 30};
	person John = {.name = "John", .age = 22};
	person Alex = {.name = "Alex", .age = 17};
	person Jule = {.name = "Erica", .age = 29};
	person Seraphine = {.name = "Seraphine", .age = 34};
	
	person *test;
	
	//hash table
	
	person *hash_table[TSize];
	
	init(hash_table);
	
    insert(hash_table, &Carlos);
	insert(hash_table, &John);
	insert(hash_table, &Alex);
	insert(hash_table, &Jule);
	insert(hash_table, &Seraphine);
	
	print_hash(hash_table);
	
	test = lookup("John", hash_table);
	if(test != NULL){
		
		printf("Econtrado o nome '%s'\n", test);
		
	}
	
	else{
		
		printf("Nome nao encontrado\n");
		
	}
	
	test = lookup("Ana", hash_table);
	if(test != NULL){
		
		printf("Econtrado o nome '%s'\n", test);
		
	}
	
	else{
		
		printf("Nome nao encontrado\n");
	
	}
	
	pop(hash_table, "Erica");
	
	test = lookup("Erica", hash_table);
	if(test != NULL){
		
		printf("Econtrado o nome '%s'\n", test);
		
	}
	
	else{
		
		printf("Nome nao encontrado\n");
	
	}
	
	return 0;
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
