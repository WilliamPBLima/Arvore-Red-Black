#ifndef _bib_h
#define _bib_h

////////// http://en.literateprograms.org/Red-black_tree_%28C%29
////////// https://gist.github.com/pallas/10697727



typedef enum colorType {RED,BLACK} tipoCor;
typedef struct nodo *no;
typedef struct nodo *apontador;
typedef struct arvore *arv;

struct arvore{
	no raiz;
};

struct nodo {
	char *chave;
	char *conteudo;
	apontador esq, dir;
	apontador pai;
	tipoCor cor;
};



arv criaArv();

char *insere (no *raiz, char *chave, char *conteudo);

void arrumaRedBlack(no *raiz, no z);

void rot_esq(no *raiz, no z);

void rot_dir(no *raiz, no z);

#endif
