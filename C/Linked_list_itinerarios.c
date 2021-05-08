#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct rota{
	
	char *parada;
	struct rota *next;

};
typedef struct rota rota;

//functions

rota *inicializar_rota(){
	
	rota *rota_temp_ini = malloc(sizeof(rota));
	rota_temp_ini -> parada = malloc(sizeof(char) * 20);
	rota_temp_ini -> next = NULL;
	
	return rota_temp_ini;
	
};

void add_parada(rota **rota_x, char *parada_x){
	
	rota *rota_temp_add;
	rota_temp_add = inicializar_rota();
	strcpy(rota_temp_add -> parada, parada_x);
	
	if(*rota_x == NULL){
		
		*rota_x = rota_temp_add;

	}
	
	else{
		
		rota *rota_temp_temp = *rota_x;
		
		while(rota_temp_temp -> next != NULL){
			
			rota_temp_temp = rota_temp_temp -> next;
			
		};
		
		rota_temp_temp -> next = rota_temp_add;
		
	};

};

void del_parada(rota **rota_x, char *parada_x){
	
	rota *rota_temp_del = *rota_x;
	
	if(*rota_x == NULL){
		
		printf("Lista vazia");
		
	}
	
	else if(strcmp(rota_temp_del -> parada, parada_x) == 0){
		
		rota *will_delete;
		will_delete = *rota_x;
		
		*rota_x = rota_temp_del -> next;
		
		free(will_delete);
		
	}
	
	else{
		
		do{
			
			if(strcmp(rota_temp_del -> next -> parada, parada_x) == 0){
				
				
				rota *will_delete;
				will_delete	= rota_temp_del -> next;
                
				rota_temp_del -> next = rota_temp_del -> next -> next;
				
                free(will_delete);

			    break;
				
			}
			
			rota_temp_del = rota_temp_del -> next;
			
		}
		while(rota_temp_del -> next != NULL);
	
    }
	
}	 

void alterar_parada(rota **rota_x, char *parada_x){
	
	if(*rota_x == NULL){
		
		printf("Lista vazia");
		
	}
	
	else{
		
		rota *rota_temp_alt = *rota_x;
		
		while(strcmp(rota_temp_alt -> next -> parada, parada_x) != 0){
			
			rota_temp_alt = rota_temp_alt -> next;
			
		};
		
		printf("Insira o novo ponto de parada\n");
		fgets(rota_temp_alt -> next -> parada, 40, stdin);
		rota_temp_alt -> next -> parada[strlen(rota_temp_alt -> next -> parada) - 1] = '\0';

	};
	
};


int main(){
	
	rota *itinerario1 = NULL;
	
	char choice[15];
    char choice_parada[40];
	
	while(strcmp(choice, "exit") != 0){
		
	    printf("[Adicionar Parada] [Deletar Parada] [Alterar Parada]\n");
	    printf("Para encerrar digite 'exit'\n");
	    fgets(choice, 15, stdin);

        choice[strlen(choice) - 1] = '\0';
		
	    if(strcmp(choice, "adicionar") == 0){
		    
			printf("Para encerrar a adicao de novos pontos digite 'back' a qualquer momento\n");
			
		    while(strcmp(choice_parada, "back") != 0){

	            printf("Digite um ponto de parada\n");
                fgets(choice_parada, 40, stdin);
				
				choice_parada[strlen(choice_parada) - 1] = '\0';
                
				if(strcmp(choice_parada, "back") != 0){
					
					add_parada(&itinerario1, choice_parada);
			    
				}
				
			}
		   
		}
		
		else if(strcmp(choice, "deletar") == 0){
			
		    printf("Digite um ponto de parada para deletar\n");
            fgets(choice_parada, 40, stdin);
			
			choice_parada[strlen(choice_parada) - 1] = '\0';
		    del_parada(&itinerario1, choice_parada);
	    
		}
		
		else if(strcmp(choice, "alterar") == 0){
			
			printf("Digite um ponto de parada para alterar\n");
            fgets(choice_parada, 40, stdin);
			
			choice_parada[strlen(choice_parada) - 1] = '\0';
			alterar_parada(&itinerario1, choice_parada);
			
		};
		
	};
	

	rota *temp = itinerario1;
	
	while(temp != NULL){
		
		printf("%s - ", temp -> parada);
		temp = temp -> next;
		
	};
	
	return 0;
	
}