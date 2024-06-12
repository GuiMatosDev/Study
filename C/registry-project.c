#include <stdio.h> //Bliblioteca de comunicação com o usuário
#include <stdlib.h> //Bliblioteca focada em alocação de memória
#include <locale.h> //Biblioteca de aloção de texto por região

int main()
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
		printf("[1] Registrar Nomes \n[2] Consultar Nomes\n[3] Deletar Nomes\n");
		printf("============================================\n");
		printf("Escolha a opção desejada: ");
		scanf("%d", &controle); //Armezenando na Nariável Controle
		
		system("cls"); // Limpa Tela
		
		switch(controle) //Estrutura secundária: Opções
		{
			case 1:
			printf("Você escolheu Registrar Nomes \n");
			system("pause");
			break;	
			
			case 2:
			printf("Você escolheu a Consultar Nomes \n");
			system("pause");
			break;
			
			case 3:
			printf("Você escolheu a Deletar Nomes \n");
			system("pause");
			break;
			
			default:
			printf("Não consegui detectar seu comando \n");
			system("pause");
			break;
			
		}
	}	

}