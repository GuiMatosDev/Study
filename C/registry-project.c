#include <stdio.h> //Bliblioteca de comunicação com o usuário
#include <stdlib.h> //Bliblioteca focada em alocação de memória
#include <locale.h> //Biblioteca de aloção de texto por região

int main()
{
	setlocale(LC_ALL, "Portuguese");	//Usando a biblioteca locale.h define a região para português. Formata o texto em português
	printf("============================================\n");
	printf("              Cartório - EBAC\n");
	printf("============================================\n");
	printf("[1] Registrar Nomes \n[2] Consultar Nomes\n[3] Deletar Nomes\n");
	printf("============================================\n");
	printf("Escolha a opção desejada: \n\n");
	
	printf("Software de Uso Live. V0.1");
}