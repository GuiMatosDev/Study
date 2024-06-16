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
	int loop = 0;
	
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
		main();
		break;
	}
}

int consulta() //Função responsável por consultar os usuários no sistema
{
	char cpf[40];
	char conteudo[200];
	int auxiliar = 0;
	int controle = 0;
	
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
			printf("Não consegui localizar o usuário, prossiga para tentar novamente\n\n");
			system("pause");
		}
		else
		{
			//Sucesso monsta o arquivo e finaliza retornando ao Menu
			printf("==============Informações Do Usuário===============\n");		
			while(fgets(conteudo,200,file) != NULL ) //Mostrando na tela arquivo escoliho
			{	
				printf("%s", conteudo);	
			}
					
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
				main();
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
			main();
			break;
		}
	}
}

int main() //Função Principal
{
	//Definindo Variáveis
	int controle = 0;
	int auxiliar = 0;
	
	for (auxiliar = 0; auxiliar = 1; auxiliar++) //Estrutura de Repetição Principal: Menu
	{
	
		system("cls"); //Limpa Tela
		
		setlocale(LC_ALL, "Portuguese"); // Ajustando para português
		
		//Menu incial
		printf("============================================\n");
		printf("              Cartório - EBAC\n");
		printf("============================================\n");
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
			return 0;
			break;
			
			default:
			printf("Não consegui detectar seu comando \n");
			system("pause");
			break;		
		}
	}	
}
