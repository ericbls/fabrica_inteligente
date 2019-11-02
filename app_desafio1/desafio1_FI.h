#ifndef _INCL_MAIN_
#define _INCL_MAIN_

struct estrutura {
		char nome[100];
		char sabor[100];
		struct torta *prox;
	};

void adicionaPessoa(struct estrutura grupo);

//printf("%p \n", pessoa );


#endif