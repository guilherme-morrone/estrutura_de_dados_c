#include<stdio.h>
#include<stdlib.h>

typedef struct No {
	int conteudo;
	struct No* esq;
	struct No* dir;
} No;

No* criarNo(int qtd) {
	No* novo_no;
	if (qtd == 0)
		novo_no = NULL;
	else
	{
		novo_no = (No*)calloc(1, sizeof(No));
		printf("Digite o valor: ");
		scanf_s("%d", &novo_no->conteudo);
		novo_no->esq = criarNo(qtd / 2);
		novo_no->dir = criarNo(qtd - qtd / 2 - 1);
	}
	return novo_no;
}

void apresentar(No* raiz)
{
	if (raiz != NULL)
	{
		printf("%d ", raiz->conteudo);
		apresentar(raiz->esq);
		apresentar(raiz->dir);
	}
}

void retorna_folhas(No* raiz){
	if (raiz != NULL) {
		if (raiz->esq == NULL && raiz->dir == NULL) {
			printf("folha: %d\n", raiz->conteudo);
		}
		retorna_folhas(raiz->esq);
		retorna_folhas(raiz->dir);
	}
}

void retorna_nao_folhas(No* raiz) {
	if (raiz != NULL) {
		if (raiz->esq != NULL && raiz->dir != NULL) {
			printf("Nao Folha: %d\n", raiz->conteudo);
		}
		retorna_nao_folhas(raiz->esq);
		retorna_nao_folhas(raiz->dir);
	}
}

int main()
{
	No* Raiz;
	Raiz = criarNo(10);
	printf("Elementos da arvore: ");
	apresentar(Raiz);
	printf("\n");
	printf("Folhas: \n");
	retorna_folhas(Raiz);
	printf("\n");
	printf("Nao Folhas: \n");
	retorna_nao_folhas(Raiz);

	
}
