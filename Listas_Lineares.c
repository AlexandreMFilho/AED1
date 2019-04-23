// Listas Lineares

//Introdução as Estruturas.
/*
struct Elemento:
{
    campo1: tipo1
    ...
    campok:tipok
};

struct Aluno{              //Criação de uma estrutura do tipo Aluno.
    int Matricula;          //Elementos que compoem o tipo Aluno.
    char[50] Nome;
    //__DATE__ DataNasc;
    char[500] Endereço;
    bool Formado;
    float CR;
};
*/
int Max_N;                  //Numero maximo de elementos

struct No <Chave,Elem>    //Cria estrutura Lista Linear composta de 2 elementos
{
    char Chave;
    int Elem;
};
struct ListaLinear{
    struct No Val[Max_N];
    int N;                //Numero corrente de elementos da lista.
}

int Tamanho(struct ListaLinear *L){
    return L-> N;
}

void Exibe (struct ListaLinear *L){
    int i;
    for (i = 0; i <= (L->N); i++){
        printf(' %c ',L->Val[i].Chave);
    } printf('\n');
    for (i = 0; i <= (L->N); i++){
        printf(' %d ',L->Val[i].Elem);
    } printf('\n');
}

//Ordenação da lista.

void Ordena_chave (struct ListaLinear *L){
    int i, temp, temp2;
    for (i = 0; i < (L->N)-1 ; i++){
        for (j = i+1; j < L->N ; j++){
            if (L->Val[i].Chave > L->Val[j].Chave){
                temp = L->Val[j].Chave;
                temp2 = L->Val[j].Elem;
                L->Val[j].Chave = L->Val[i].Chave;
                L->Val[j].Elem = L->Val[i].Elem;
                L->Val[i].Chave = temp;
                L->Val[i].Elem = temp2;
            }
        }
    }
};

void Ordena_elem (struct ListaLinear *L){
    int i, j, temp, temp2;
    for (i = 0; i < (L->N)-1 ; i++){
        for (j = i+1; j < L->N ; j++){
            if (L->Val[i].Elem < L->Val[j].Elem){
                temp = L->Val[j].Elem;
                temp2 = L->Val[j].Chave;
                L->Val[j].Elem = L->Val[i].Elem;
                L->Val[j].Chave = L->Val[i].Chave;
                L->Val[i].Elem = temp;
                L->Val[i].Chave = temp2;
            }
        }
    }
};

// Busca da chave por posição é a mesma para Ordenadas e não ordenadas.
int Busca_chave (struct ListaLinear *L,int pos){           // Retorna a chave da posição dada.
    return (L->Val[pos].Chave);
};

//Busca em lista não ordenada.

int No_Busca_pos (struct ListaLinear *L,char c){              // Retorna a posição da chave dada.
    int i = 0;
    while (i <= L->N && L->Val[i].Chave =! c){
        i++;
    } if (i <= L-N){
        return i;
    } else {
        return -1;
    }
};

int No_Busca_elem (struct ListaLinear *L,char c){             // Retorna o elemento da chave dada.      
    int elem;
    elem = No_Busca_pos(l,c);
    } if (elem == -1){
        return 'NULL';
    } else {
        return (L->Val[pos].Elem);
    }
};

//Busca em Lista Ordenada.

int O_Busca_bin (struct ListaLinear *L, char c, int *posIns){    // Retorna a posição da chave dada.
    int inf, sup, meio;
    inf = 0;
    sup = (L->N) -1;

    while(inf <= sup){
         meio =(inf + sup)/2;
        if(L->Val[meio].Chave == c){
            return meio;
        } else{
            if(L->Val[meio].Chave < c){
                inf = meio +1;
            } else {
                sup = meio -1;
            }
        }
    }
    *(posIns) = inf;
    return 0;
};

int O_Busca_elem (struct ListaLinear *L, char c ){            // Retorna o elemento da chave dada.
    int pos;
    pos = Busca_bin(L,c);
    if(pos == 0){
        return "NULL";
    } else{
        return (L->Val[pos].Chave);
    }
};

// Inserção em Lista não ordenada.
void No_Insere (struct ListaLinear *L, char c, int x){         //Insere no fim da lista.
    if (L->N < Max_N){
        L->Val[L->N+1].Chave = c;
        L->Val[L->N+1].Elem = x;
        L->N = L->N+1
    }
};

void No_Insere_em (struct ListaLinear *L,char c, int x,int pos){   //Insere na posição desejada. O elemento que estava na posição vai para o fim da lista.
    if(L->N < Max_N){
        L->Val[L->N+1].Elem = Val[pos].Elem;
        L->Val[L->N+1].Chave = Val[pos].Chave;
        L->Val[pos].Elem = x;
        L->Val[pos].Chave = c;
        L->N = L->N+1;
    }
};

//Inserção em Lista Ordenada.                               //MINHA CRIAÇÃO 
void O_Insere (struct ListaLinear *L,char c, int x){
    if(L->N < Max_N){
        int i,j;
        i=0;
        while (c > L->Val[i].Chave){
            i++;
        } for (j=L->N; j > i; j--){
            L->Val[j+1].Chave = L->Val[j].Chave;
            L->Val[j+1].Elem = L->Val[j].Elem;
        }
        L->Val[i].Chave = c;
        L->Val[i].Elem = x;
    } else {
        printf("Overflow");
    }
/*Inserção em Lista Ordenada.                               //PROFESSOR CRIAÇÃO 
void P_Insere (struct ListaLinear *L,char c, int x){
    if(L->N < Max_N){
        int i,j, pos;
        pos = O_Busca_bin (L,c,pos);
        if (pos == 0){
                .
                .
                .
    }
*/

// Remoção em Lista não Ordenada.

void No_Remove (struct ListaLinear *L,char c){
    int pos;
    pos = No_Busca_pos(L,c);
    if (pos > 0){
        L->Val[pos].Elem = L->Val[L->N].Elem;
        L->Val[pos].Chave = L->Val[L->N].Chave;
        L->N = L->N-1;
    } else {
        print( "Chave inexistente.");
    }
};

void No_Remove_em (struct ListaLinear *L , int pos){
    if(pos >= Max_N){   //verificar isso
        L->Val[pos].Elem = L->Val[L->N].Elem;
        L->Val[pos].Chave = L->Val[L->N].Chave;
        L->N = L->N-1;
    }
};
// Remoção em Lista Ordenada.

