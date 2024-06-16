#include <stdio.h> //Bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Bliblioteca focada em aloca��o de mem�ria
#include <locale.h> //Biblioteca de alo��o de texto por regi�o
#include <string.h> //Biblioteca respons�ovel por gerenciar strings

int registro() //Fun��o respons�vel por cadastrar o usu�rio no sistema
{
	//Defini��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int controle = 0;
	int loop = 0;
	
	setlocale(LC_ALL, "Portuguese"); // Ajustando para portugu�s
	
	system("cls");

	printf("====================Registro======================\n");
	printf("Digite o CPF para cadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copia os valores da variavel cpf para variavel arquivo
	
	FILE *file; //Fun��o para criar um arquivo
	file = fopen(arquivo, "w"); // Cria um arquivo com a vari�vel arquivo que clonou os dados do cpf
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
	
	//Atualizando o arquivo com as vari�veis
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
	
	//Decis�o para inserir novo registro ou voltar ao menu
	printf("============================================\n");
	printf("Deseja inserior novo registro?\n[1]Sim [2]N�o\nR: ");
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

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	char cpf[40];
	char conteudo[200];
	int auxiliar = 0;
	int controle = 0;
	
	setlocale(LC_ALL, "Portuguese"); // Ajustando para portugu�s

	for(auxiliar = 0; auxiliar = 1; auxiliar++)
	{
		system("cls");
		printf("====================Consulta======================\n");
		printf("Digite o CPF para consulta: ");
		scanf("%s", cpf);
		
		//Abrindo arquivo
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL) //Valid��o
		{
			//Falha monstra mensagem de erro e volta para digitar CPF
			system("cls");
			printf("N�o consegui localizar o usu�rio, prossiga para tentar novamente\n\n");
			system("pause");
		}
		else
		{
			//Sucesso monsta o arquivo e finaliza retornando ao Menu
			printf("==============Informa��es Do Usu�rio===============\n");		
			while(fgets(conteudo,200,file) != NULL ) //Mostrando na tela arquivo escoliho
			{	
				printf("%s", conteudo);	
			}
					
			//Decis�o para inserir nova consulta ou voltar ao menu
			printf("\n============================================\n");
			printf("Deseja Consultar novamente?\n[1]Sim [2]N�o\nR: ");
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
	//Declara��o de vari�veis
	char cpf[40];
	int controle = 0;
	
	setlocale(LC_ALL, "Portuguese"); // Ajustando para portugu�s
	
	system("cls");
	
	printf("====================Deletar======================\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	//Localiza o arquivo
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //Valida��o
	{
		//Falha: sinaliza que n�o encontrou o arquivo
		printf("Usu�rio n�o localizado\n");
		system("pause");
	}
	else
	{
		//Sucesso: remove o arquivo e retorna para o Menu
		remove(cpf);
		printf("\n============================================\n");
		printf("Usu�rio removido com sucesso\n");
		//Decis�o para deletar novamente ou voltar ao menu
		printf("============================================\n");
		printf("Deseja deletar outro usu�rio?\n[1]Sim [2]N�o\nR: ");
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

int main() //Fun��o Principal
{
	//Definindo Vari�veis
	int controle = 0;
	int auxiliar = 0;
	
	for (auxiliar = 0; auxiliar = 1; auxiliar++) //Estrutura de Repeti��o Principal: Menu
	{
	
		system("cls"); //Limpa Tela
		
		setlocale(LC_ALL, "Portuguese"); // Ajustando para portugu�s
		
		//Menu incial
		printf("============================================\n");
		printf("              Cart�rio - EBAC\n");
		printf("============================================\n");
		printf("[1] Registrar Nomes \n[2] Consultar Nomes\n[3] Deletar Nomes\n[4] Sair\n");
		printf("============================================\n");
		printf("Escolha a op��o desejada: ");
		scanf("%d", &controle); //Armezenando na Nari�vel Controle
		
		system("cls"); // Limpa Tela
		
		switch(controle) //Estrutura secund�ria: Op��es
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
			printf("N�o consegui detectar seu comando \n");
			system("pause");
			break;		
		}
	}	
}
