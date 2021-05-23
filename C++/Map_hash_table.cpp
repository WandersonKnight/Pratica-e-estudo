#include <map>
#include <iostream>
#include <string>

#define MSize 30;

struct contato{
	
	std::string nome;
	std::string email;
	long long int telefone;
	
};

typedef struct contato contato;

// hash function //

long int hash_function(std::string nome_i){

    long int aux = 0;

	for(int i = 0; i < nome_i.std::string::length(); i++){

		aux += int(nome_i[i]);

	}

	long int index = (aux % 25) * 7;
	
	index = index % MSize;
	
	return index;
	
}

int main(){
	
	std::map<int, contato> MapaEsp;
	contato novo_contato;

	int escolha;
	int aux_size = MSize
	int test = 0;
	
	// Valores recebidos para o contato //

	std::string nome_temp;
	std::string email_temp;
	long long int telefone_temp;

	int index_temp;
	contato encontrado;
	
    // Funcoes do mapa

	do{
		
		std::cout << "Digite o numero da operacao desejada\n1 - Criar novo contato\n2 - Excluir contato\n3 - Consultar agenda\n4 - Todos os contatos\n0 - Fechar programa" << std::endl;
		std::cin >> escolha;
		
		switch(escolha){
			
			case 1:
			
			    std::cout << "Digite o nome do novo contato" << std::endl;
				std::cin.ignore();
			    std::getline(std::cin, nome_temp);
				
				std::cout << "Digite o telefone do contato" << std::endl;
				std::cin >> telefone_temp;
				
				std::cout << "Digite o email do contato" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, email_temp);
				
				index_temp = hash_function(nome_temp);
				
				for(int i = 0; i < aux_size; i++){

					if(MapaEsp.count((index_temp + i) % aux_size) == 0){

						MapaEsp[(index_temp + i) % aux_size] = novo_contato;

						index_temp = (index_temp + i) % aux_size;

						break;

					}

				}
				
				MapaEsp[index_temp].nome = nome_temp;
				MapaEsp[index_temp].email = email_temp;
				MapaEsp[index_temp].telefone = telefone_temp;
			
                std::cout << "\nContato adicionado:" << std::endl;
				std::cout << "Nome - " << MapaEsp[index_temp].nome << "\nTelefone - " << MapaEsp[index_temp].telefone << "\nEmail - " << MapaEsp[index_temp].email << "\n\n";

				break;

		    case 2:

			    std::cout << "Digite o nome do contato que deseja excluir" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, nome_temp);

				index_temp = hash_function(nome_temp);

				for(int i = 0; i < aux_size; i++){

					if(MapaEsp[(index_temp + i) % aux_size].nome == nome_temp){

						MapaEsp.erase((index_temp + i) % aux_size);
						test = 0; 

						std::cout << "\nContato excluido!\n" << std::endl;

						break;

					}
					else{

						test = 1;

					}

				}

				if(test == 1){

					std::cout << "\nContato nao encontrado\n" << std::endl;

				}

				break;

			case 3:

			    std::cout << "Digite o contato desejado para a busca" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, nome_temp);

				index_temp = hash_function(nome_temp);

				for(int i = 0; i < aux_size; i++){

					if(MapaEsp[(index_temp + i) % aux_size].nome == nome_temp){

						encontrado = MapaEsp[(index_temp + i) % aux_size];

						break;

					}
					else{

						encontrado.nome = "null";

					}

				}

				if(encontrado.nome == "null"){

					std::cout << "\nContato nao encontrado\n" << std::endl;

				}
				else{

					std::cout << "\nNome - " << encontrado.nome << "\nTelefone - " << encontrado.telefone << "\nEmail - " << encontrado.email << "\n\n";

				}

			    break;

			case 4:

			    std::cout << "// Lista de todos os contatos //\n" << std::endl;
				
				for(std::map<int, contato>::iterator it = MapaEsp.begin(); it != MapaEsp.end(); it++){

					if(it -> second.telefone > 0){
						std::cout << "Nome - " <<  it -> second.nome << "\nTelefone - " <<  it -> second.telefone << "\nEmail - " <<  it -> second.email << "\n\n* --------- *\n\n";
					}

				}

			    break;

		}
		
	}
	while(escolha != 0);
	
	return 0;
	
}