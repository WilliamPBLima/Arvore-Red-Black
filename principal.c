#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bib.h"

#define SIG 4096
#define PVR 256

int main(){
	system("clear");
	arv root; /*raiz*/ 
	int num;
	char op;
	char significado[SIG];
	char palavra[PVR];
	char *retorno;

	root = criaArv();

	for ( ; ; ){
		puts("\t      DICIONARIO        ");
		puts("\n\t========================");
		puts("\t| Para INSERIR :  i    |");
		puts("\t| Para BUSCAR  :  b    |");
		puts("\t| Para REMOVER :  r    |");
		puts("\t========================");
		printf("\t ->"); scanf(" %c", &op); 
		switch(op){
			case 'i':
				puts("Palavra:\n");
				scanf(" %s", palavra); 
				puts("\nSignificado:\n");
				scanf(" %s", significado); 
				retorno = insere(&root->raiz, palavra, significado);
				system("clear");
				continue;
			case 'b':
				
				system("clear");
				continue;
			case 'r':
				
				system("clear");
				continue;
			default:
				system("clear");
				puts("\tOpcao incorreta!\n");
		}
	}
	return 0;
}
