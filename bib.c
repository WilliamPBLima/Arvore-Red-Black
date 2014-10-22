#include "bib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criaArv(arv *raiz){  // Inicializa arvore
  *raiz = NULL;
  return;
}

//////////////////////////////////////////////////////q
no criaNo(arv T, int k){ // Cria novo nodo
  no p;

  p = (no) malloc( sizeof(no) );
  p->chave = k;
  p->pai = T->NIL;
  p->esq = T->NIL;
  p->dir = T->NIL;
  return p;
}

///////////////////////////////////////////////////////////



void RB_insert(arv T, no z){
    no x,y;
    y = T->NIL;      // no y vai apontar para o pai de x
    x = T->raiz;

	while(x != T->NIL){ // Quando x for NILL, y sera pai de x. (sabe onde inserir novo nodo)
		y = x;
		if(z->chave < x->chave)
			x = x->esq;
		else
			x = x->dir;
    }

	z->pai = y;
	if( y == T->NIL ) // se arvore for vazia, raiz recebe z
		T->raiz = z; // primeira insercao na arvore
	else // senao ira verificar se chave eh menor ou maior que y->chave (y = folha)
           if(z->chave < y->chave)
               y->esq = z;
           else
               y->dir = z;
    z->esq = T->NIL;
    z->dir = T->NIL;
    z->cor = RED; // insere sempre vermelho
    RB_insert_fixup(T, z); // chama funcao para arrumar a arvore
}



//////////////////////////////////////////////////////////////
void RB_insert_fixup(arv T, no z)
{
    no y;
    while(z->pai->cor==RED)
    {
        if(z->pai == z->pai->pai->esq)  //se eu sou filho a esquerda do meu pai
        {
            y = z->pai->pai->dir;
            if(y->cor==RED)         //CASO1: 2 pretos consecutivos e tio RED
            {
                z->pai->cor=BLACK;
                y->pai->cor=BLACK; //y e meu tio
                z->pai->pai->cor=RED;
                z=z->pai->pai; //z e meu avo
            }
            else
            {
                if(z==z->pai->dir) //CASO 2: rotacao zig-zag
                {
                    z=z->pai;
                    rot_esq(T,z);
                }
                z->pai->cor=BLACK; //CASO 3: tio e preto e eu nao posso recolorir
                z->pai->pai->cor=RED;
                rot_dir(T,z);
            }
        }
        else
        {
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
                    rot_dir(T,z);
                }
                z->pai->cor=BLACK; //CASO3: tio eh preto e eu nao posso recolorir
                z->pai->pai->cor=RED;
                rot_esq(T,z);
            }
        }
    }
    T->raiz->cor=BLACK;
}


///////////////////////////////////////////////////////////
////////////////////////////
// Rotacoes na arvore //////
////////////////////////////
void rot_esq(arv T, no z){
	no y;
	y = z->dir;
	z->dir = y->esq;
	y->esq->pai = z;
	y->pai = z->pai;
	if (z->pai == T->NIL)
		T->raiz = y;
	else if (z = z->pai->esq)
		z->pai->esq = y;
	else
		z->pai->dir = y;
	y->esq = z;
	z->pai = y;
}

void rot_dir(arv T, no z){
	no y;
	y = z->esq;
	z->esq = y->dir;
	y->dir->pai = z;
	y->pai = z->pai;
	if (z->pai == T->NIL)
		T->raiz = y;
	else if (z = z->pai->esq)
		z->pai->dir = y;
	else
		z->pai->esq = y;
	y->dir = z;
	z->pai = y;

}
