#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list{	

    char *cidade;
	
	struct list *prev;
	struct list *next;
	
};
typedef struct list list;


list *mem_aloc(){
	
	list *temp_list = malloc(sizeof(list));
	temp_list -> cidade = malloc(sizeof(char) *15);
	temp_list -> prev = NULL;
	temp_list -> next = NULL;
	
	return temp_list;
	
}

void cidade_check(list **any_list, char *current_cidade){
	
	if(strlen(current_cidade) > 14){
		
		(*any_list) -> cidade = malloc(sizeof(char) * (strlen(current_cidade) + 10));
		
	}
	
}
	
void add_prev(list **current_list, char *current_cidade){
	
	list *temp_list = mem_aloc();
	
	strcpy(temp_list -> cidade, current_cidade);
	temp_list -> next = *current_list;
	
	if((*current_list) != NULL){
		
		(*current_list) -> prev = temp_list;
		
		*current_list = temp_list;
		
	}
	
}

void add_next(list **current_list, char *current_cidade){
	
	list *temp_list = *current_list;
	
	if((*current_list) -> next == NULL){

		(*current_list) -> next = mem_aloc();
		(*current_list) -> next -> prev = *current_list;
		
	    strcpy((*current_list) -> next -> cidade, current_cidade);
		
	}
	
	else{
		
		do{
		
		    temp_list = temp_list -> next;
		
		}
		
		while(temp_list -> next != NULL);
		
		temp_list -> next = mem_aloc();
		temp_list -> next -> prev = temp_list;
		
		strcpy(temp_list -> next -> cidade, current_cidade);
	}

}


int main(){

    list *main_list = NULL;
	int check;
	
	char cidade_temp[20];
	
    main_list = mem_aloc();
	
	printf("Digite a primeira cidade\n");
	fgets(main_list -> cidade, 14, stdin);
	main_list -> cidade[strlen(main_list -> cidade) - 1] = '\0';
	
	printf("%s - ", main_list -> cidade);

    do{
		
	    printf("Escolha uma opcao\nAdicionar proximo(1)| Adicionar anterior (2)| Exit (0)\n");
	    scanf("%d", &check);
		
	    switch(check){
		
		    case 1:
		    printf("Digite a cidade\n");
		    scanf("%s", cidade_temp);
		    add_next(&main_list, cidade_temp);
			break;
			
			case 2:
			printf("Digite a cidade\n");
			scanf("%s", cidade_temp);
			add_prev(&main_list, cidade_temp);
			break;
			
		}
	}
	while(check != 0);
	
	printf("Para frente\n");
	
	list *temp_list2 = main_list;
	
	do{
		
	    printf("%s - ", temp_list2 -> cidade);
	    temp_list2 = temp_list2 -> next;
		
	}
	while(temp_list2 -> next != NULL);
	
	printf("%s - ", temp_list2 -> cidade);
	
	printf("\nPara tras\n");
	
	do{
		
	    printf("%s - ", temp_list2 -> cidade);
	    temp_list2 = temp_list2 -> prev;
		
	}
	while (temp_list2 -> prev != NULL);
	
	printf("%s - ", temp_list2 -> cidade);
	
}
	
	
	
	
	

	
	