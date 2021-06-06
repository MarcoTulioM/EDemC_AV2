#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct no {
    int id;
    char codprod;
    double preco;
    int quant;
 	struct no* prox;
};
typedef struct no No;

struct lista {
 	No *inicio;
 	No *fim;
}; 	
typedef struct lista Lista;

/*-----------------------------------------------------------------------------*/

void inicia(Lista* L){
 	L->inicio = L->fim = NULL;
}

void insere_fim(Lista* L, int _id, char _codprod, double _preco, int _quant){
  No* no;
  no = (No*) malloc(sizeof(No)); 

  no->id = _id;
  no->codprod = _codprod;
  no->preco = _preco;
  no->quant = _quant;

  no->prox = NULL; 
  
  if(L->inicio == NULL){
    L->inicio = L->fim = no;
  }else{ 
    (L->fim)->prox = no;
    L->fim = no;
  }
}

int remove_fim(Lista *L) {
  	No *nofinal, *noanterior;
  	int id; 					
  	if (L->inicio == NULL)
    	return -1;			
 	nofinal = L->inicio;
	while (nofinal != L->fim){
		noanterior = nofinal;
		nofinal = nofinal->prox;
	} 
	 
	if(L->inicio == L->fim) 
 		L->inicio = L->fim = NULL; 
 	else{
  		id = nofinal->id;
		nofinal = NULL;
  		noanterior->prox = NULL; 
		L->fim = noanterior;
 	}
  	free(nofinal);
  	return id;
}

int sup = 0;
void aplica_desc_e_quant_sup(Lista *L, int _desc){
 	int count = 0;
 	No* no;
 	no = L->inicio;
    while(no != NULL){

        no->preco -= (no->preco / 100) * _desc;

        if (no->quant > 500) sup++;

        no = no->prox;
        count++;
    }
}

void imprime(Lista *L){
 	int count = 0;
 	No* no;
 	no = L->inicio;
    while(no != NULL){

        cout << endl << "codigo do produto: " << no->codprod;
        cout << endl << "novo valor: " << no->preco << endl;

        no = no->prox;
        count++;
    }
}
	
void apaga(Lista* L){
 	int r = 0;
 	while (r != -1)
 	{
 		r = remove_fim(L);
 	}
}

/*-----------------------------------------------------------------------------*/

int main() {

  int id, quant, desc;
  char codprod;
  double preco;

 	Lista L;
 	inicia(&L);
 	printf("\t\t--------1. Programa que Cadastra 5 Produtos--------\n\n");
  printf("\t\t------------------- Marco  Tulio ----------------\n\n");
  printf("\t\t------------------- 201903341396 ----------------\n\n");
 	
    for (id = 0; id < 5; id++) {

        cout << endl << "----- Produto [" << id << "] -----" << endl;

        cout << endl << "codigo do produto: ";
        cin >> codprod;

        cout << endl << "preco: ";
        cin >> preco;

        cout << endl << "quantidade: ";
        cin >> quant;

        cout << endl << "------------------------------" << endl;
        
        insere_fim(&L, id, codprod, preco, quant);
    }

    cout << endl << "taxa de desconto: %";
    cin >> desc;

    aplica_desc_e_quant_sup(&L, desc);

    printf("\t\t--------- RELATORIO --------\n\n");

    imprime(&L);

    cout << endl << "Quantidade de produtos com quantidade estocada superior a 500: " << sup << endl;

 	apaga(&L);
 	return 0;
}