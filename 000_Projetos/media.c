#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Projeto para Média de Vendedores

int media(){
	
	setlocale(LC_ALL,"Portuguese");
	
	system("cls");
	printf("Média");
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