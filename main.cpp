#include <stdio.h>
#include "Lista.h"


int main(void){

	Lista lista = NULL;

	printf("Lista criada:\n");
	for (int i = 10; i > 0; i--){
		lista.append(i);
	}
	lista.imprimir();

	printf("Lista ordenada:\n");
	lista.sort();
	lista.imprimir();

	printf("Remover 8:\n");
	lista.remove(8);
	lista.imprimir();

	printf("Trocar valor do index 2 por 11:\n");
	lista.changeValue(2, 11);
	lista.imprimir();

	printf("Adicionar 12 no index 4:\n");
	lista.insert(4, 12);
	lista.imprimir();

	printf("Remover elemento do index 5:\n");
	lista.pop(5);
	lista.imprimir();

    return 0;
}
