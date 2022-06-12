#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//		AGENDA DE ANIVERSARIOS

typedef struct{
	char nome[50];
	int dia, mes , ano;
}Contato;


void imprimir(Contato **c, int quant){
	
	int i;
	
	printf("\n\tLista de Contatos:\n");
	printf("\t---------------------------------------\n");
	
	for(i = 0; i < quant; i++){					//se usa a -> pois estamos mostrando o endereco de memoria e nao a varial de um contato
		printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
	}
	
	printf("\t---------------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant , int tam){
	
	if(quant < tam){
		Contato *novo = malloc(sizeof(Contato));
		
		printf("\nDigite o nome do contato: ");
		scanf("%50[^\n]", novo->nome);
		
		printf("\nDigite a data de aniversario dd mm aaaa: ");
		scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
		
		getchar();//tirar o buffer do teclado
		
		c[quant] = novo;
		
		
		return 1;//continua o cadastro
	}else{
		printf("\n\tImpossivel novo cadastro. Agenda cheia!!\n");
		return 0;//para de executar, interrompe a execução 
	}
}

void alterar_contato(Contato **c, int quant){
	int id;
	
	imprimir(c, quant);
	
	printf("\n\tDigite o codigo do contato que deseja alterar: \n");
	scanf("%d", &id);
	getchar();
	id--;
	
	if(id >= 0 && id < quant){
		Contato *novo = malloc(sizeof(Contato));
		
		printf("\nDigite o nome do contato: ");
		scanf("%50[^\n]", novo->nome);
		
		printf("\nDigite a data de aniversario dd mm aaaa: ");
		scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();//tirar o buffer do teclado
		c[id] = novo;
		
	}else{
		printf("\n\tCodigo invalido!\n");
	}
}


int main(){
	
	Contato *agenda[50];
	int opcao, tam = 50, quant = 0;
	
	do{
		printf("\n\t0 - Sair");
		printf("\n\t1 - Cadastrar");
		printf("\n\t2 - Alterar");
		printf("\n\t3 - Imprimir");
		printf("\n\t4 - Salvar");
		printf("\n\t5 - Ler arquivo\n");
	
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			case 1:
				quant += cadastrar_contato(agenda, quant, tam);
				break;
				
			case 2:
				alterar_contato(agenda, quant);
				break;
			case 3:
				imprimir(agenda, quant);
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				if(opcao != 0){
					printf("\n\tOpção invalida!!!\n");
				}
				
			
		}
		
	}while(opcao != 0);
	
/*	imprimir(agenda, quant);
	quant += cadastrar_contato(agenda, quant, tam);
	printf("\nquant: %d\n",quant);

	imprimir(agenda, quant);
	quant += cadastrar_contato(agenda, quant, tam);
	printf("\nquant: %d\n",quant);
	imprimir(agenda, quant);	*/
		
	return 0;
}
