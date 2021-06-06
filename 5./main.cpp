#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct no {
    int id;
    int numero;
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

void insere_fim(Lista* L, int id, int numero){
  No* no;
  no = (No*) malloc(sizeof(No)); 

  no->id = id;
  no->numero = numero;

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

void imprime(Lista *L){
    int count = 0;
 	No* no;
 	no = L->inicio;
    while(no != NULL){
        if (count != 0) {cout << ", ";};
        cout << no->numero;

        no = no->prox;
        count++;
    }
}

void crescente (Lista* L) {
  No* no;
  no = L->inicio;
  while (no != NULL){
    No *p = no->prox;
    while (p != NULL){
        if (no->numero > p->numero){ 
            int tmp_id = no->id; 
            no->id = p->id;
            p->id = tmp_id;

            char tmp_numero = no->numero; 
            no->numero = p->numero;
            p->numero = tmp_numero;
        }
        p = p->prox;
    }
    no = no->prox;
  }
}

void decrescente (Lista* L) {
  No* no;
  no = L->inicio;
  while (no != NULL){
    No *p = no->prox;
    while (p != NULL){
        if (no->numero < p->numero){ 
            int tmp_id = no->id; 
            no->id = p->id;
            p->id = tmp_id;

            char tmp_numero = no->numero; 
            no->numero = p->numero;
            p->numero = tmp_numero;
        }
        p = p->prox;
    }
    no = no->prox;
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

  int id, numero;

    Lista L;
    inicia(&L);
 	Lista Par;
 	inicia(&Par);
    Lista Impar;
 	inicia(&Impar);


 	printf("\t\t--------2. Programa que Cadastra 8 Funcionários--------\n\n");
    printf("\t\t------------------- Marco  Tulio ----------------\n\n");
    printf("\t\t------------------- 201903341396 ----------------\n\n");
 	
    for (id = 0; id < 20; id++) {

        cout << endl << "----- NUMERO [" << id << "] -----" << endl;
        cout << endl << "entre um numero: ";
        cin >> numero;

        cout << endl << "------------------------------" << endl;
        
        insere_fim(&L, id, numero);
        if ( numero % 2 == 0) {
            insere_fim(&Par, id, numero);
        } else {
            insere_fim(&Impar, id, numero);
        }
    }
    cout << endl << "" << endl;
    printf("\t\t--------------- Pares ------------\n\n");
    cout << endl;
    imprime(&Par);

    cout << endl << "" << endl;
    printf("\t\t--------------- Impares ------------\n\n");
    cout << endl;
    imprime(&Impar);

    cout << endl << "" << endl;
    printf("\t\t--------- Ordem Crescente --------\n\n");
    cout << endl;
    crescente(&L);
    imprime(&L);

    cout << endl << "" << endl;
    printf("\t\t--------- Ordem Derescente --------\n\n");
    cout << endl;
    decrescente(&L);
    imprime(&L);
    cout << endl;

    apaga(&L);
    apaga(&Par);
    apaga(&Impar);
 	return 0;
}