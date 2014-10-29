#include "bib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

arv criaArv(){  // Inicializa arvore
  return arv init=NULL;
}


////////////////////////////////////////////////////////// Deve ser tratado o caso de haver mais de uma chave igual na arvore!!!

char *insere (no *raiz, char *chave, char *conteudo){
    no x,y;
    no z;

    z = (no) malloc(sizeof(struct nodo));   //
    z->chave = chave;                //  EFETUANDO A 
    z->conteudo = conteudo;          //  INSERCAO
    z->pai = z->esq = z->dir = NULL; //

    
    if( (raiz) == NULL){ // se arvore for vazia, raiz recebe z
        z->cor = BLACK;
        *raiz = z; // primeira insercao na arvore
    }
    else{
        y = NULL;      // no y vai apontar para o pai de x

        x = *raiz;
	    while(x != NULL){ // Quando x for NILL, y sera pai de x. (sabe onde inserir novo nodo)
		    y = x;
	       	if(z->chave == x->chave)
                return NULL;
            else if (z->chave < x->chave)            
			    x = x->esq;
            else
			    x = x->dir;
        }
	    z->pai = y;
            if(z->chave < y->chave) //aqui ira verificar se chave eh menor ou maior que y->chave (y = folha)
                y->esq = z;
            else
                y->dir = z;
        z->esq = NULL;
        z->dir = NULL;
        z->cor = RED; // insere sempre vermelho
        arrumaRedBlack(raiz, z); // chama funcao para arrumar a arvore
    }
    return z->conteudo;
}



//////////////////////////////////////////////////////////////
void arrumaRedBlack(no *raiz, no z){
    no y;
    char *conteudo;
    while(z->pai->cor==RED){
        if(z->pai == z->pai->pai->esq){ //se eu sou filho a esquerda do meu pai
            y = z->pai->pai->dir;
            if(y->cor==RED){            //CASO1: 2 pretos consecutivos e tio RED
                z->pai->cor=BLACK;
                y->pai->cor=BLACK; //y e meu tio
                z->pai->pai->cor=RED;
                z=z->pai->pai; //z e meu avo
            }
            else{
                if(z==z->pai->dir){ //CASO 2: rotacao zig-zag
                    z=z->pai;
                    rot_esq(raiz,z);
                }
                z->pai->cor=BLACK; //CASO 3: tio e preto e eu nao posso recolorir
                z->pai->pai->cor=RED;
                rot_dir(raiz,z);
            }
        }
        else{
            y = z->pai->pai->esq;
            if(y->cor==RED)         //CASO1: 2 pretos consecutivos e tio RED
            {
                z->pai->cor=BLACK;
                y->pai->cor=BLACK; //y e meu tio
                z->pai->pai->cor=RED;
                z=z->pai->pai; //z e meu avo
            }
            else
            {
                if(z==z->pai->esq) //CASO2: rotacao zig-zag
                {
                    z=z->pai;
                    rot_dir(raiz,z);
                }
                z->pai->cor=BLACK; //CASO3: tio eh preto e eu nao posso recolorir
                z->pai->pai->cor=RED;
                rot_esq(raiz,z);
            }
        }
    }
    (*raiz)->cor=BLACK; // OLHAR BEM ESSA PARTE!!!
}


///////////////////////////////////////////////////////////
////////////////////////////
// Rotacoes na arvore //////
////////////////////////////
void rot_esq(no *raiz, no z){
	no y;
	y = z->dir;
	z->dir = y->esq;
	y->esq->pai = z;
	y->pai = z->pai;
	if (z->pai == NULL)
		*raiz = y;
	else if (z = z->pai->esq)
		z->pai->esq = y;
	else
		z->pai->dir = y;
	y->esq = z;
	z->pai = y;
}

void rot_dir(no *raiz, no z){
	no y;
	y = z->esq;
	z->esq = y->dir;
	y->dir->pai = z;
	y->pai = z->pai;
	if (z->pai == NULL)
		*raiz = y;
	else if (z = z->pai->esq)
		z->pai->dir = y;
	else
		z->pai->esq = y;
	y->dir = z;
	z->pai = y;

}
