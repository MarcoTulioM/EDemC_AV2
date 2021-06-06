#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct no {
    int id;
    char nome;
    double salario;

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

void insere_fim(Lista* L, int id, char nome, double salario){
  No* no;
  no = (No*) malloc(sizeof(No)); 

  no->id = id;
  no->nome = nome;
  no->salario = salario;

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
 	No* no;
 	no = L->inicio;
    while(no != NULL){

        cout << endl << "funcionario [" <<  no->id << "]: "<< no->nome;
        cout << endl << "salario: " << no->salario << endl;

        no = no->prox;
    }
}

void crescente (Lista* L) {
  No* no;
  no = L->inicio;
  while (no != NULL){
    No *p = no->prox;
    while (p != NULL){
        if (no->salario > p->salario){ 

            int tmp_id = no->id; 
            no->id = p->id;
            p->id = tmp_id;

            char tmp_nome = no->nome; 
            no->nome = p->nome;
            p->nome = tmp_nome;

            double tmp_salario = no->salario; 
            no->salario = p->salario;
            p->salario = tmp_salario;
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

void maior_salario(Lista *L, Lista *M){
  double maior;
 	No* no;
 	no = L->inicio;
    while(no != NULL){

        int id = no->id;
        char nome = no->nome;
        double salario = no->salario;

        if (no->id == 0) {
          maior = no->salario;
          insere_fim(M, id, nome, salario);
        };

        if (no->salario > maior && no->id != 0) {
          maior = no->salario;
          apaga(M);
          insere_fim(M, id, nome, salario);
        } else if (no->salario == maior) {
          insere_fim(M, id, nome, salario);
        }

        no = no->prox;
    }
}

void resolve_os_itens_a_b_c(Lista *L, Lista *M, double superior){
 	No* no;

  cout << endl << " " << endl;
  cout << "a. Maior Salario:" << endl;
  cout << " " << endl;
  int count = 0; 
 	no = M->inicio;
  while(no != NULL){

      if (count > 0) {cout << ",";};
      cout << no->nome;

      no = no->prox;
      count++;
  }
  cout << endl << " " << endl;
  cout << "b. Media:" << endl;
  double xcount = 0; 
  no = L->inicio;
  while(no != NULL){

    xcount += no->salario;

    if (no->prox == NULL) {cout << endl << "média salarial de todos os funcionários juntos e de: " << xcount / 8;};
    no = no->prox;
  }
  cout << endl << " " << endl;
  cout << "c. Quantidade Superior:" << endl;
  count = 0; 
  no = L->inicio;
  while(no != NULL){

      if (no->salario > superior) {
        count++;
      };
      if (no->prox == NULL) {
        cout << endl << "Quantidade de funcionários com salário superior a " << superior << " e de: " << count << endl;
      };
      no = no->prox;
  }

}

/*-----------------------------------------------------------------------------*/

int main() {

  int id;
  char nome;
  double salario, superior;

 	Lista L;
 	inicia(&L);

  Lista M;
  inicia(&M);

 	printf("\t\t--------2. Programa que Cadastra 8 Funcionários--------\n\n");
  printf("\t\t------------------- Marco  Tulio ----------------\n\n");
  printf("\t\t------------------- 201903341396 ----------------\n\n");
 	
    for (id = 0; id < 8; id++) {

        cout << endl << "----- funcionario [" << id << "] -----" << endl;

        cout << endl << "nome: ";
        cin >> nome;

        cout << endl << "salario: ";
        cin >> salario;

        cout << endl << "------------------------------" << endl;
        
        insere_fim(&L, id, nome, salario);
    }

    cout << endl << "Quantidade de funcionários com salário superior a?: ";
    cin >> superior;

    printf("\t\t--------- Ordem Crescente --------\n\n");

    maior_salario(&L, &M);
    crescente(&L);
    imprime(&L);

    printf("\t\t------------ Resultado -----------\n\n");

    resolve_os_itens_a_b_c(&L, &M, superior);

 	apaga(&L);
 	return 0;
}