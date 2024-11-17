#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Projeto para Média de Vendedores

int media(){
	
	char arquivo[200];
	char nome[40];
	long int vendas = 0;
	long int vendas_semana_passada = 0;
	int dia_util = 0;
	int dias_vendidos = 0;
	
	setlocale(LC_ALL,"Portuguese");
	
	system("cls");
	printf("================================\n            Media\n================================\n");
	printf("Nome: ");
	scanf("%s", &nome);
	printf("Vendido atualmente: ");
	scanf("%d", &vendas);
	printf("Vendido semana passada: ");
	scanf("%d", &vendas_semana_passada);
	printf("Dias uteis desse mês: ");
	scanf("%d", &dia_util);
	printf("Dias vendidos: ");
	scanf("%d", &dias_vendidos);
	
	
	FILE *file;
	file = fopen(arquivo,"w");
	fprintf(file,"Nome:",nome);
	
	
	fclose(file);
	
	
}

int main(){
	
	int controle = 0;
	int loop = 0;
	
	for(loop=0;loop=1;){
	
		system("cls");
		setlocale(LC_ALL,"Portuguese");
		printf("================================\n            Media\n================================\n");
		printf("[1] Entrar\n[2] Sair\n>>>");
		scanf("%d", &controle);
		
		switch(controle){
			case 1:
			media();
			break;
			
			case 2:
			return 0;
			break;
			
			default:
			printf("Não reconheci seu comando, vou te encaminhar novamente ao menu...");
		}
	}	
}
