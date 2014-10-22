#ifndef _bib_h
#define _bib_h



enum colorType {RED,BLACK};

typedef enum colorType tipoCor;
typedef struct nodo *nodoNulo;
typedef struct nodo *no;
typedef struct nodo *apontador;
typedef struct arvore *arv;

struct arvore{
	no raiz;
	nodoNulo NIL;
};

struct nodo {
	int chave;
	apontador esq, dir;
	apontador pai;
	tipoCor cor;
};


void criaArv(arv *raiz);

no criaNo( arv T, int k );

void RB_insert(arv T, no z);

void RB_insert_fixup(arv T, no z);

void rot_esq(arv T, no z);

void rot_dir(arv T, no z);

#endif
