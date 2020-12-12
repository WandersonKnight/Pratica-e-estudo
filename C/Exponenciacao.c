#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int base;
	int expoente;
	long long int temp;
	
    temp = 1;
	
	while (1)
	{
		printf("Digite um numero a ser exponenciado\n");
		scanf("%d", &base);
		
		printf("Digite a potencia a ser aplicada no numero\n");
		scanf("%d", &expoente);
		
		if (expoente < 0)
		{
			
			printf("Erro, expoente inferior a zero selecionado, renicie o programa");
			
		}
		
		if (expoente == 0)
		{
			
			printf("O resultado da exponenciacao e: 1");
			
		}
		
		if (expoente >= 1)
		{
			
			for (int i = 1; i <= expoente; i++)
			{
				
				temp = temp * base;
				
			}
			
			printf("O resultado da exponenciacao e: %lld", temp);
		}
		
		break;
	
	}

	return 0;
	
}	
