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
    	
    	if (this->length == 1){
    		value = NULL;
    		this->length = 0;
    		return;
		}
    	
    	this->length--;
    	
    	if (a->anterior != NULL){
        	a->anterior->prox = a->prox;
		}
		if (a->prox != NULL){
        	a->prox->anterior = a->anterior;
		}
    }
    
    int partition(int low, int high){
	
		int pivo = this->get(low);
		int j = low;
		for (int i = low+1; i < high+1; i++){
			
			if (this->get(i) <= pivo){
				j++;
				int n1 = this->get(i);
				int n2 = this->get(j);
				this->changeValue(i, n2);
				this->changeValue(j,n1);
			}
			
		}
		this->changeValue(low, this->get(j));
		this->changeValue(j, pivo);
		return j;
	}
    
    void quickSort(int low, int high){
    	
    	if (low < high){
			int p = partition(low, high);
			quickSort(low, p-1);
			quickSort(p+1, high);
		}
    	
	}

public:
	
    int value = NULL;
    // bool valueVazio = true;
    int length = 0;

    Lista(int value){
        this->value = value;
        // this->valueVazio = false;
    }


	int get(int index){
		
		Lista *aux = this;
		int i = 0;
		while (aux != NULL){
			if (i == index) return aux->value;
			aux = aux->prox;
			i++;
		}
		printf("Erro: index %d fora de alcance\n", index);
		
	}
	
	void changeValue(int index, int value){
		
		Lista *aux = this;
		int i = 0;
		while (aux != NULL){
			if (i == index){
				aux->value = value;
				break;
			}
			aux = aux->prox;
			i++;
		}
		
	}

    void append(int value){

		this->length += 1;

		if (this->value == NULL){
        	this->value = value;
        	return;
		}

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

		if (index > this->length-1){
			printf("Erro: index fora de alcance\n");
			return;
		}

        Lista *aux = this;
        int i = 0;
        while (aux != NULL){
            if (i == index){
                removeAux(aux);
                return;
            }
            aux = aux->prox;
            i++;
        }
        printf("Erro: index %d nao corresponde a nenhum elemento\n", index);

    }

    // Remove o elemento com o valor especificado com o menor �ndice
    void remove(int value){

		if (this->length == 0){
			printf("Erro: Nao pode remover um elemento de uma lista vazia\n");
			return;
		}

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

    void sort(){
        quickSort(0, this->length-1);
    }

    void imprimir(){

		if (this->length == 0){
			printf("Lista vazia\n");
			return;
		}

        Lista *aux = this;
        while (aux != NULL){
            printf("%d ", aux->value);
            aux = aux->prox;
        }
        printf("\n");

    }

};
