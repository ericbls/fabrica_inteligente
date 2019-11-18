#ifndef _INCL_MAIN_
#define _INCL_MAIN_

struct torta {
		char sabor[100];
		char ingrediente1[200];
		char ingrediente2[200];
		struct torta *prox;
	};

void addSabor(struct torta *receitas);
void delSabor(struct torta *receitas);
void listSabor(struct torta *receitas);
void getSabor(struct torta *receitas);

#endif