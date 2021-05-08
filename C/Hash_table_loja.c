#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HashSize 20

struct cliente{
	
	char email[60];
	char nome[80];
	int idade;
	
};

typedef struct cliente Cliente;

// Criar hash function

unsigned long int hash_function(char *string){
	
	int lenght = strlen(string);
	unsigned long int hash_key = 0;
	
	for(int i = 0; i < lenght; i++){
		
		hash_key += string[i];
		hash_key = hash_key * i % HashSize;
		
	}
	
	hash_key =  hash_key % HashSize;
	
	return hash_key;
	
}

// Functions direcionadas a hash table

// Iniciar tabela

void init_hash(Cliente **hash){
	
	for(int i = 0; i < HashSize; i++){
		
		hash[i] = NULL;
		
	}
	
}

// Iniciar struct

Cliente *init_struct(char nome_i[80] , char email_i[60] , int idade_i){
	
	Cliente *Novo = malloc(sizeof(Cliente));
	
	strcpy(Novo -> email, email_i);
    strcpy(Novo -> nome, nome_i);
		
	Novo -> idade = idade_i;
	
	return Novo;
		
}

//Inserir elemento

void insert(Cliente **hash, char nome_i[80] , char email_i[60] , int idade_i){
	
	int index = hash_function(email_i);
	int aux;
	
    for(int i = 0; i < HashSize; i++){

        aux = (index + i) % HashSize;
		
		if(hash[aux] == NULL){
			
			hash[aux] = init_struct(nome_i, email_i, idade_i);
		    return;
			
		}
		
	}
	
	printf("Lista cheia\n");

}

// Remover elemento

void pop(Cliente **hash, char *email_i){
	
	int index = hash_function(email_i);
	int aux;

	for(int i = 0; i < HashSize; i++){
		
		aux = (index + i) % HashSize;
		
		if(hash[aux] != NULL && strcmp(hash[aux] -> email, email_i) == 0){
			
			hash[aux] = NULL;
			return;
			
		}
		
	}
	
	printf("Usuario nao encontrado");
	
}

// Exibir elementos

void print_hash(Cliente **hash){
	
	for(int i = 0; i < HashSize; i++){
		
		if(hash[i] != NULL){
			
			printf("%d -> [%s -- %s -- %d]\n", i, hash[i] -> nome, hash[i] -> email, hash[i] -> idade);
			
		}
		
		else{
			
			printf("%d -> VAZIO\n", i);
			
		}
		
	}

}

// Buscar elemento

Cliente *lookup(Cliente **hash, char *email_i){
	
	int index = hash_function(email_i);
	int aux;
	
	for(int i = 0; i < HashSize; i++){
		
		aux = (index + i) % HashSize;

		if(hash[aux] != NULL && strcmp(hash[aux] -> email, email_i) == 0){
		
		    return hash[aux];
		
	    }
		
    }
	
	return NULL;
	
}

int main(){
	
	Cliente *test;
	
	//hash table
	
	Cliente *hash_table[HashSize];
	
	init_hash(hash_table);
	
	// Inserir
	
    insert(hash_table, "Carlos Filho", "carlosfilho1@gmail.com", 35);
	insert(hash_table, "Ana Maria", "ananunesneto@gmail.com", 27);
	insert(hash_table, "Zeca Pagodinho da Silva", "zecapg@hotmail.com", 62);
	insert(hash_table, "Antonio", "antonio55@gmail.com", 56);
	insert(hash_table, "Luna Souza", "luhsouza@outlook.com", 23);
	
	print_hash(hash_table);
	
	// Buscar
	
	test = lookup(hash_table, "carlosfilho1@gmail.com");
	if(test != NULL){
		
		printf("Usuario encontrado:\nNome: '%s', email: '%s', idade: '%d'\n", test -> nome, test -> email, test -> idade);
		
	}
	
	else{
		
		printf("Usuario nao encontrado\n");
		
	}
	
	test = lookup(hash_table, "kellymoreira9@uol.com");
	if(test != NULL){
		
		printf("Usuario encontrado:\n Nome: '%s', email: '%s', idade: '%d'\n", test -> nome, test -> email, test -> idade);
		
	}
	
	else{
		
		printf("Usuario nao encontrado\n");
	
	}
	
	// Remover
	
	pop(hash_table, "carlosfilho1@gmail.com");
	pop(hash_table, "zecapg@hotmail.com");
	
	print_hash(hash_table);
	
	return 0;
	
}