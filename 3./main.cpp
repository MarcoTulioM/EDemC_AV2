#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct no {
    int id;
    char nome;
    double nota;
    struct no* ant;  
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

void insere_fim(Lista* L, Lista *A, int id, char nome, double nota, bool aprovados){
  No* no;
  no = (No*) malloc(sizeof(No));
  
  no->id = id;
  no->nome = nome;
  no->nota = nota;

  no->prox = NULL;
	  
  if(L->inicio == NULL){
    no->ant = NULL;
    L->inicio = L->fim = no;  
  }else{ 
    no->ant = L->fim; 
    (L->fim)->prox = no;
    L->fim = no;
  }

  if (no->nota >= 7 && aprovados) {
      insere_fim(A, L, id, nome, nota, false);
  }

}
	
int remove_fim(Lista *L) {
  	No *no;
  	int id;
  	if (L->inicio == NULL)
    	return -1;
  	no = L->fim;
 	if(L->inicio == L->fim) 
 		L->inicio = L->fim = NULL;
 	else{
  		L->fim = no->ant;  
  		(L->fim)->prox = NULL;
 	}
  	id = no->id;
  	free(no);
  	return id;
}
	
void imprime(Lista *L){
 	No* no;
 	no = L->inicio;
 	if (L->inicio != NULL){
 		while(no != NULL){
 			
        cout << endl << "Aluno [" <<  no->id << "]: "<< no->nome;
        cout << endl << "nota: " << no->nota << endl;

 			no = no->prox;
 		}
 	} else printf("\n\t\tmensagem: nenhum alunos com nota igual ou superior a 7!");
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

    char nome;
    double nota;

 	Lista L;
    inicia(&L);

    Lista Aprovados;
    inicia(&Aprovados);	

 	printf("\t\t--------3. Programa que Cadastra 5 Alunos--------\n\n");
    printf("\t\t------------------- Marco  Tulio ----------------\n\n");
    printf("\t\t------------------- 201903341396 ----------------\n\n");
 	
    for (int id = 0; id < 5; id++) {
        cout << endl << "------ Aluno [" << id << "] ------" << endl;
        cout << endl << "nome: ";
        cin >> nome;

        cout << endl << "nota [ 0 - 10 ]: ";
        cin >> nota;

        if ( nota < 0 || nota > 10 ) {
            id--;
            cout << endl << "nota deve ser de 0 a 10, por favor informe os dados desse aluno novamente!";
        } else {
            cout << endl << "------------------------------" << endl;

            insere_fim(&L, &Aprovados, id, nome, nota, true);
        }
    }

    printf("\t\t--------- RESULTADO --------\n\n");

    imprime(&Aprovados);

 	apaga(&L);
 	return 0;
}