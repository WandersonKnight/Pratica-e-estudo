#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	float energia_c;
	float massa;
	float velocidade_i = 0;
	float velocidade_f = 0;
	char resposta[5];
	
	
	printf("Sera realizado o calculo da Energia Cinetica ou de seu Trabalho a partir de valores fornecidos de massa e velocidade\n\n");
	printf("Formula da Energia Cinetica: [Ec = mv^2/2]\n");
	printf("Trabalho da Energia Cinetica: [Ec = m(vf - vi)^2/2]\n\n");
	
	printf("Digite o valor da massa em [Kg]\n");
	scanf("%f", &massa);
	
	while(1){
		
		printf("Ha um valor de velocidade inicial e outro final? [SIM] ou [NAO]\n");
		scanf("%s", resposta);

	    if(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0) {
			
			printf("Digite a velocidade inicial em [m/s^2]\n");
			scanf("%f", &velocidade_i);
			
			printf("Digite a velocidade final em [m/s^2]\n");
			scanf("%f", &velocidade_f);
			
			velocidade_f = velocidade_f - velocidade_i;
			
			break;
			
		}
		
		else if(strcmp(resposta, "nao") == 0 || strcmp(resposta, "NAO") == 0){
			
			printf("Digite a velocidade em [m/s^2]\n");
			scanf("%f", &velocidade_f);
			
			break;
			
		}
		
		else{
			
			printf("Erro na resposta\n");
			
		}
		
	}
	
	energia_c = (massa * (velocidade_f * velocidade_f)) / 2;
	
	if(velocidade_i != 0){
		
		printf("O Trabalho da Energia Cinetica e: Ec = %.2f J", energia_c);
		
	}
	
	else{
		
		printf("A Energia Cinetica e: Ec = %.2f J", energia_c);
	
	}
	
    return 0;
	
}