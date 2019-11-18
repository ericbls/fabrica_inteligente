#include "desafio1_FI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) // Função principal de execução________________________________________
{
	int option=0;
	struct torta *receitas = malloc(sizeof(struct torta));

	while (option != 6)
	{
		option=0;
		printf("\n========== MENU =========================================================================\n");
		printf("escolha uma das opções abaixo\n");
		printf("1) Adicionar novo produto\n");
		printf("2) Excluir produto da lista\n");
		printf("3) Listar produtos existentes\n");
		printf("4) Buscar nome\n");
		printf("6) Cancelar\n");
		printf("===========================================================================================\n");
		printf("Qual a opção desejada?: ");
		scanf("%d", &option);
		system("clear");

		switch (option)
		{
			case 1: //Adicionar novo elemento na lista
				printf("\nVocê apertou 1\n\n");
				addSabor(receitas);

			break; //---------------------------------

			case 2: //Exclusão de elemento da lista
				printf("\nVocê apertou 2\n\n");
				listSabor(receitas);
				delSabor(receitas);

			break; //---------------------------------

			case 3: //Listar elementos
				printf("\nVocê apertou 3\n\n");
				listSabor(receitas);

			break; //---------------------------------
			
			case 4: //Buscar elementos
				printf("\nVocê apertou 4\n\n");
				getSabor(receitas);

			break; //---------------------------------

			case 5: //Nada por enquanto
				printf("\nVocê apertou 5\n\n");

			break; //---------------------------------

			case 6: //Sair do programa
				printf("\nVocê apertou 6\n\n");

			break; //---------------------------------

		}
	}
	return 0;
}

void addSabor(struct torta *receitas) // Função para adicionar novo sabor de torta______________________
{
	
	char input_sabor[50];
	char input_ingred1[100];
	char input_ingred2[100];
	printf("Digite o nome do sabor: ");
	scanf("%s", input_sabor);
	printf("Digite o primeiro ingrediente: ");
	scanf("%s", input_ingred1);
	printf("Digite o segundo ingrediente: ");
	scanf("%s", input_ingred2);
	struct torta *temp1 = malloc(sizeof(struct torta));
	temp1->prox=NULL;
	strcpy(temp1->sabor, input_sabor);
	strcpy(temp1->ingrediente1, input_ingred1);
	strcpy(temp1->ingrediente2, input_ingred2);

	struct torta *temp2;
	temp2 = receitas;

	while(temp2->prox)
	{
		temp2 = temp2->prox;
		//temp2=(*temp2).prox
	}
	temp2->prox = temp1;
}

void delSabor(struct torta *receitas) // Função para remover um sabor de torta__________________________
{
	char get_sabor[100];
	int quit_loop = 0;
	int count_index = 0;
	printf("Digite o sabor que quer deletar: ");
	scanf("%s", get_sabor);
	char confirmar[5];
	struct torta *temp3;
	temp3=receitas;
	struct torta *temp4;
	temp4=receitas;

	while(quit_loop==0)
	{
		if (strcmp(get_sabor,temp4->sabor)==0)
		{
			printf("Index: %d | ", count_index);
			printf("Sabor: %s | ", temp4->sabor);
			printf("Ingrediente 1: %s | ", temp4->ingrediente1);
			printf("Ingrediente 2: %s \n", temp4->ingrediente2);
			printf("Deseja deletar o item acima? (S/N): ");
			scanf("%s", confirmar);

			if (strcmp(confirmar,"S")==0)
			{
				quit_loop=1;
			}
			else if (strcmp(confirmar,"N")==0)
			{
				quit_loop=2;
			}
			else
			{
				printf("Opção Inválida\n");
			}

		}
		else
		{
			if (temp4->prox)
			{
				temp3 = temp4;
				temp4 = temp4->prox;
			}
			else
			{
				quit_loop=3;
			}
		}
		count_index++;
	}

	if(quit_loop==1)
	{
		printf("\nRemoção concluída\n");
		temp3->prox = temp4->prox;
		free(temp4);
	}

	else if (quit_loop==2)
	{
		
		printf("\nRemoção cancelada\n");
	}

	else
	{
		printf("\nSabor não encontrado\n");
	}
}

void listSabor(struct torta *receitas) // Função para listar os sabores de torta já adicionados__________
{
	struct torta *temp5;
	temp5 = receitas;
	int count_index=0;
	while(temp5->prox)
	{
		count_index++;
		temp5 = temp5->prox;
		printf("Index: %d | ", count_index);
		printf("Sabor: %s | ", temp5->sabor);
		printf("Ingrediente 1: %s | ", temp5->ingrediente1);
		printf("Ingrediente 2: %s \n\n", temp5->ingrediente2);	
	}
}

void getSabor(struct torta *receitas) // Função para procurar e printar um determinado sabor_____________
{
	char get_sabor[100];
	int quit_loop = 0;
	int count_index = 0;
	printf("\nDigite o sabor que quer printar: ");
	scanf("%s", get_sabor);
	struct torta *temp6;
	temp6=receitas;
	while(temp6->prox && quit_loop==0)
	{
		temp6 = temp6->prox;
		count_index++;
		if (strcmp(get_sabor,temp6->sabor)==0)
		{
			printf("Index: %d | ", count_index);
			printf("Sabor: %s | ", temp6->sabor);
			printf("Ingrediente 1: %s | ", temp6->ingrediente1);
			printf("Ingrediente 2: %s \n\n", temp6->ingrediente2);
			quit_loop=1;
		}
	}

	if(quit_loop==0)
	{
		printf("\nSabor não encontrado\n");
	}
}



