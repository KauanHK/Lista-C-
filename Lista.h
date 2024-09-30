#include <stdio.h>
#include <stdlib.h>

class Lista {

private:
    Lista *prox = NULL;
    Lista *anterior = NULL;

    Lista *getUltimo(){
        Lista *ultimo = this;
        while (ultimo->prox != NULL){
            ultimo = ultimo->prox;
        }
        return ultimo;
    }

    void removeAux(Lista *a){
        a->anterior->prox = a->prox;
        a->prox->anterior = a->anterior;
    }

public:
    int value;

    Lista(int value){
        this->value = value;
    }


    void append(int value){

        Lista *novo = new Lista(value);
        Lista *ultimo = getUltimo();
        ultimo->prox = novo;
        novo->anterior = ultimo;
        novo->prox = NULL;
        novo->value = value;

    }

    void insert(int index, int value){

        int i = 0;
        Lista *aux = this;
        while (aux->prox != NULL){
            if (i == index){
                Lista *novo = new Lista(value);
                aux->anterior->prox = novo;
                novo->anterior = aux->anterior;
                novo->prox = aux;
                aux->anterior = novo;
                return;
            }
            i++;
            aux = aux->prox;
        }
        printf("Erro: lista nao contem index %d\n", index);

    }

    void pop(int index){

        Lista *aux = this;
        int i = 0;
        while (aux->prox != NULL){
            if (i == index){
                removeAux(aux);
                return;
            }
            aux = aux->prox;
            i++;
        }
        printf("Erro: index %d nao corresponde a nenhum elemento\n", index);

    }

    void remove(int value){
        // Remove o elemento com o valor especificado com o menor índice

        Lista *aux = this;
        while (aux->prox != NULL){
            if (aux->value == value){
                removeAux(aux);
                return;
            }
            aux = aux->prox;
        }
        printf("Erro: a lista nao contem o valor %d\n", value);

    }

    void imprimir(){

        Lista *aux = this;
        while (aux != NULL){
            printf("%d\n", aux->value);
            aux = aux->prox;
        }
        printf("\n");

    }

};
