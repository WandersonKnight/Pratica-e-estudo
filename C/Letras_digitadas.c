#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char lista[55];
	char lista_del[1] = " ";
	int i;
	int j;
	
	printf("Este programa imprimira na tela as letras digitadas ate um maximo de 50 letras. Caso queira encerra-lo digite 'parar'\n");
	
	for(i = 0; i <= 55; i++){
		
		printf("Digite uma letra: ");
		scanf("%s", &lista[i]);
		
		if (strstr(lista, "parar")){
			
			i = j;
			
			for(i; i <= j + 5; i++){
				
				lista[i] = lista_del[0];
				
			}
			
            break;
			
        }
		
		else{
			
		    printf("%s\n", lista);
		
		}
		
	}
	
	return 0;
	
}	
