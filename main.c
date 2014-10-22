#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "bib.h"

void montaMenu(arv raiz){
	char op;
	int num;
	char vet[50];
	no inserir;	
	
	puts("===============================");
	puts("| Para INSERIR: i <num>       |");
	puts("| Para BUSCAR:  b <num>       |");
	puts("| Para REMOVER  r <num>       |");
	puts("===============================");
		
	fgets(vet,50,stdin);
	sscanf(vet,"%c %d", &op, &num);
	switch(op){
		case 'i':
			inserir = criaNo(raiz, num);			
			RB_insert(raiz, inserir);
			montaMenu(raiz);
		case 'b':
		

		case 'r':


		default:
			system("clear");
			puts("Opcao incorreta!");
			montaMenu(raiz);

	}

}


int main(){
	system("clear");
	arv raiz;
	criaArv(&raiz);
	montaMenu(raiz);	
	return 0;
}
