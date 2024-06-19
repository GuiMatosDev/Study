#include <stdio.h> //Bliblioteca de comunicação com o usuário
#include <stdlib.h> //Bliblioteca focada em alocação de memória
#include <locale.h> //Biblioteca de aloção de texto por região
#include <string.h> //Biblioteca responsáovel por gerenciar strings

int registro() //Função responsável por cadastrar o usuário no sistema
{
	//Definição de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int controle = 0;
	
	
	setlocale(LC_ALL, "Portuguese"); // Ajustando para português
	
	system("cls");

	printf("====================Registro======================\n");
	printf("Digite o CPF para cadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copia os valores da variavel cpf para variavel arquivo
	
	FILE *file; //Função para criar um arquivo
	file = fopen(arquivo, "w"); // Cria um arquivo com a variável arquivo que clonou os dados do cpf
	fprintf(file, "CPF:");
	fprintf(file,cpf); // Salva dentro do arquivo criado os valores da variavel cpf
	fclose(file); //Fecha o arquivo
	
	//Recebendo dados
	printf("Digie o NOME para cadastro: ");
	scanf("%s",nome);
	printf("Digite o SOBRENOME para cadastro: ");
	scanf("%s",sobrenome);
	printf("Digite o CARGO para cadastro: ");
	scanf("%s",cargo);
	
	//Atualizando o arquivo com as variáveis
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome:");
	fprintf(file,nome);
	fprintf(file, "\nSobrenome:");
	fprintf(file,sobrenome);
	fprintf(file, "\nCargo:");
	fprintf(file,cargo);
	fclose(file);
	
	printf("============================================\n");
	printf("Registro inserido com sucesso!\n");
	
	//Decisão para inserir novo registro ou voltar ao menu
	printf("============================================\n");
	printf("Deseja inserior novo registro?\n[1]Sim [2]Não\nR: ");
	scanf("%d", &controle);
	
	switch(controle)
	{
		case 1: 
		registro();
		break;
		
		case 2:
		return 0;
		break;
	}
}

int consulta() //Função responsável por consultar os usuários no sistema
{
	char cpf[40];
	char conteudo[200];
	int auxiliar = 0;
	int controle = 0;
	int c = 0;
	
	setlocale(LC_ALL, "Portuguese"); // Ajustando para português

	for(auxiliar = 0; auxiliar = 1; auxiliar++)
	{
		system("cls");
		printf("====================Consulta======================\n");
		printf("Digite o CPF para consulta: ");
		scanf("%s", cpf);
		
		//Abrindo arquivo
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL) //Validção
		{
			//Falha monstra mensagem de erro e volta para digitar CPF
			system("cls");
			fclose(file);
			printf("Não consegui localizar o usuário.\n[1] Tentar novamente\n[2] Menu\nDigite a opção desejada:");
			scanf("%d", &c);
			if (c == 1)
			{
				printf("Menu");
			}
			else
			{
				return 0;
			}
			
			
		}
		else
		{
			//Sucesso monsta o arquivo e finaliza retornando ao Menu
			printf("==============Informações Do Usuário===============\n");		
			while(fgets(conteudo,200,file) != NULL ) //Mostrando na tela arquivo escoliho
			{	
				printf("%s", conteudo);	
			}
			fclose(file);
					
			//Decisão para inserir nova consulta ou voltar ao menu
			printf("\n============================================\n");
			printf("Deseja Consultar novamente?\n[1]Sim [2]Não\nR: ");
			scanf("%d", &controle);
			
			switch(controle)
			{
				case 1: 
				consulta();
				break;
				
				case 2:
				return 0;
				break;
			}
		}	
		
	}	
}

int deletar()
{
	//Declaração de variáveis
	char cpf[40];
	int controle = 0;
	
	setlocale(LC_ALL, "Portuguese"); // Ajustando para português
	
	system("cls");
	
	printf("====================Deletar======================\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	//Localiza o arquivo
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //Validação
	{
		//Falha: sinaliza que não encontrou o arquivo
		printf("Usuário não localizado\n");
		system("pause");
	}
	else
	{
		//Sucesso: remove o arquivo e retorna para o Menu
		remove(cpf);
		printf("\n============================================\n");
		printf("Usuário removido com sucesso\n");
		//Decisão para deletar novamente ou voltar ao menu
		printf("============================================\n");
		printf("Deseja deletar outro usuário?\n[1]Sim [2]Não\nR: ");
		scanf("%d", &controle);
	
		switch(controle)
		{
			case 1: 
			deletar();
			break;
			
			case 2:
			return 0;
			break;
		}
	}
}

menu() //Menu Pinrcipal
{
	//Definindo Variáveis
	int controle = 0;
	int auxiliar = 0;
	
	for (auxiliar = 0; auxiliar = 1; auxiliar++) //Estrutura de Repetição Principal: Menu
	{
	
		system("cls"); //Limpa Tela
		
		setlocale(LC_ALL, "Portuguese"); // Ajustando para português
		
		//Menu incial
		printf("============================================\n              Cartório - EBAC\n============================================\n");
		printf("[1] Registrar Nomes \n[2] Consultar Nomes\n[3] Deletar Nomes\n[4] Sair\n");
		printf("============================================\n");
		printf("Escolha a opção desejada: ");
		scanf("%d", &controle); //Armezenando na Nariável Controle
		
		system("cls"); // Limpa Tela
		
		switch(controle) //Estrutura secundária: Opções
		{
			case 1:
			registro();
			break;	
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			exit(0); //encerra de uma vez o progama ao contrário do return0 que encerra a função
			break;
			
			default:
			printf("Não consegui detectar seu comando \n");
			system("pause");
			break;		
		}
	}
}

int main() //Função Principal: Validação de Usuário
{
	setlocale(LC_ALL, "Portuguese"); // Ajustando para português
	
	//Declaração de Variáveis
	char senha[40];
	char usuario[40];
	char vad [40];
	char nova[40];
	int controle=0;
	int auxiliar=0;
	int teste = 0;

	
	for(controle=0; controle=1;) //Loop infinito
	{
		system("cls"); 
		//Menu Inicial
		printf("============================================\n              Cartório - EBAC\n============================================\n");
		printf("[1]Entrar\n[2]Criar Conta\n[3]Sair\n============================================\nDigite a opção desejada: ");
		scanf("%d", &auxiliar);
		
		
		switch(auxiliar) //Escolha
		{
			case 1: //Accesso
			system("cls");
			printf("============================================\n              Cartório - EBAC\n============================================\n");
			printf("Digite o usuário: ");
			scanf("%s", &usuario);
			printf("Digite sua senha: ");
			scanf("%s", &senha);
			
			//Procura do arquivo
			FILE *file;
			file = fopen(usuario, "r"); 
			
			while(fgets(vad,40,file) != NULL) //Copia o conteudo do arquivo usario para a variavel vad
			{	
			}
			
		
			teste = ("%d",strncmp(vad,senha,20)); //A variável teste recebe a comparação das duas strings
			
					
			if(teste == 0) //Validação - Teste= 0 verdadeiro, Teste >= 0 igual a falso
			{
				printf("Senha Correta");
				menu(); //
				if (menu != 0)
				{
					return 0;
				}
			}
			else
			{
				printf("Senha Incorreta\n");
			}
			fclose(file);
			break;
			
			case 2:
			system("cls");
			printf("====================Criação de Usuário==========================\n");
			printf("Digite o usuário: ");
			scanf("%s", &usuario);
			printf("Digite nova senha: ");
			scanf("%s", &nova);
			
			//Cria um arquivo com o nome do usuário e armazena a senha dentro do arquivo
			file = fopen(usuario, "w");
			fprintf(file, nova);
			fclose(file);
			
			printf("Senha Criada Com Sucesso!!\n");
			system("pause");
			main();
			break;
			
			case 3:
			return 0;	
			break;
			
		}
		
		//Caso não reconheça em qualquer parte o comando
		printf("Não recoheci seu comando, vou direcionar novamente ao MENU\n");
		system("pause");
		
	}
}
