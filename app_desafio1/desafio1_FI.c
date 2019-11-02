#include "desafio1_FI.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	clear;
	char input_nome[100];
	char input_sabor[50];
	int option=0;
	struct estrutura *grupo = malloc(sizeof(struct estrutura));

	while (option != 6)
	{
		option=0;
		cout << "\nMenu - escolha uma das opções abaixo\n";
		cout << "1) Adicionar novo produto\n";
		cout << "2) Excluir produto da lista\n";
		cout << "3) Listar produtos existentes\n";
		cout << "4) Buscar nome\n\n";
		cout << "6) Cancelar\n\n";
		cout << "Qual a opção desejada?:___\n";
		cin >> option;

		switch (option)
		{
			case 1: //Adicionar novo elemento na lista
			
				addPessoa(grupo);

			break; //---------------------------------

			case 2: //Exclusão de elemento da lista

			break; //---------------------------------

			case 3: //Listar elementos

			break; //---------------------------------
			
			case 4: //Buscar elementos

			break; //---------------------------------
		}
	}
	return 0;
}


void addPessoa(struct estrutura *grupo)
{
	cout << "Digite o nome da pessoa:\n";
	cin >> input_nome;
	cout << "Digite o sabor de torta predileto:\n"
	cin >> input_sabor;
	struct estrutura *pessoa = malloc(sizeof(struct estrutura));
	pessoa->prox=NULL;
	strcpy(pessoa->nome, input_nome);
	strcpy(pessoa->sabor, input_sabor);

	struct estrutura *temp2;
	temp2 = grupo;

	while(temp2->prox)
	{
		temp2 = temp2->prox;
		//temp2=(*temp2).prox
	}
	temp2->prox = pessoa;
}




