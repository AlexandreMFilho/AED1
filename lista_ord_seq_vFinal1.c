#include <stdio.h>
#include <stdlib.h>

#define  MAX_N 10

struct No{
	char Chave;
	int Elemento;
};
struct ListaLinear {
	struct No Val[MAX_N];
	int n;
};

/*int Tamanho (struct ListaLinear *L){
	int i;
	for (i = 0; L->Val[i].Elemento < '\0'; i++){
		;
	}
	return i;
}*/

//Exibindo a Lista

void Exibe (struct ListaLinear *L){
  int i,j;

  for (i = 0; i < (L->n); i++){
    printf("%c ", L->Val[i].Chave);
  }
  printf("\n");

  for (j = 0; j < (L->n); j++){
    printf("%d ", L->Val[j].Elemento);
  }
  printf("\n");
}

//Orddenando os elementos
void Ordenacao (struct ListaLinear *L){
	int i, j, temp;

	for (i = 0; i < L->n; i++){
		for (j = i+1; j < L->n; j++){
			if (L->Val[j].Elemento  < L->Val[i].Elemento){ // 5 e 2
				temp = L->Val[i].Elemento;
				L->Val[i].Elemento = L->Val[j].Elemento;
				L->Val[j].Elemento = temp;
			}
		}
	}/*
	for (i = 0; i < L->n; i++){
		for (j = i+1; j < L->n; j++){
			if (L->Val[j].Chave  < L->Val[i].Chave){
				temp = L->Val[i].Chave;
				L->Val[i].Chave = L->Val[j].Chave;
				L->Val[j].Chave = temp;
			}
		}
	}*/
  Exibe(L);
}

//Insercao em Lista Ordenada POR CHAVE, mas antes precisamos da funcao BuscaPosicao e da funcao InsereEm

int BuscaPosicao (struct ListaLinear *L, char chave, int *posIns){
  int inf, sup, m;
  inf = 0;
  sup = (L->n) - 1;

  while (inf <= sup){
    m = (inf+sup)/2;
    if ((L->Val[m].Chave) == chave){
      return m;
    }else{
		if ((L->Val[m].Chave) < chave){
			inf = m + 1;
		}else{
			sup = m - 1;
		}
	}

}
*(posIns) = inf;
  return 0;
}


void InsereEm (struct ListaLinear *L, int pos, char chave, int x){
  int i;

  if (L->n < MAX_N){
    for (i = L->n; i >= pos; i--){
      L->Val[i+1] = L->Val[i];
    }

    L->n = (L->n)+1;
    L->Val[pos].Chave = chave;
    L->Val[pos].Elemento = x;

  }
}


void Insere (struct ListaLinear *L, char chave, int x){
  int pos, posIns;

  pos = BuscaPosicao (L, chave, &posIns);

  printf("\nPosIns: %d\n", posIns);
  if (pos == 0){
    InsereEm (L, posIns, chave, x);
  }

  Exibe(L);

}

//Para remover em lista ordenada, precisamos da funcao BuscaPosicao e da funcao RemoveEm

int RemoveEm (struct ListaLinear *L, int pos){
  int i;

  if (L->n > 0){
    int x;
    x = L->Val[pos].Elemento;
    for (i = pos; i <= (L->n); i++){
      L->Val[i] = L->Val[i+1];
    }
    L->n = (L->n) - 1;
    return x;
  }
}

int Remove (struct ListaLinear *L, char chave){
  int pos, posIns;
  pos = BuscaPosicao(L, chave, &posIns);

  //printf("\nPosIns: %d", posIns);
  if (pos > 0){
    return RemoveEm(L, pos);
  }
  //Exibe(L);
}

int main(void){
	struct ListaLinear L;
	//Preenchendo valores previamente determinados em L...
  L.Val[0].Chave = 'A';
  L.Val[1].Chave = 'B';
  L.Val[2].Chave = 'C';
  L.Val[3].Chave = 'D';
  L.Val[4].Chave = 'Z';
  L.Val[5].Chave = 'F';


 // strcpy(L1.Chave1, "ABCDEF");

  L.Val[0].Elemento = 2;
  L.Val[1].Elemento = 7;
  L.Val[2].Elemento = 5;
  L.Val[3].Elemento = 9;
  L.Val[4].Elemento = 6;
  L.Val[5].Elemento = 1;

  L.n = 6;

  printf("***********Exibe\n");
  Exibe(&L);
  printf("***********Ordena\n");
  Ordenacao(&L);
  printf("************Insere\n");
  Insere(&L, 'G', 3);
  printf("************Remove\n");
  int elem_removido = Remove(&L, 'C');//Remover o 'C' da lista, só entramos com a lista e a chave
  printf("\nElemento Removido: %d\n", elem_removido);
  Exibe(&L);




	system("pause");
	return 0;
}
