#include <stdio.h>
#include "Lista.h"



int main(void){

    Lista lista(1);
    for (int i = 2; i < 10; i++){
        lista.append(i);
    }

    lista.pop(3);
    lista.remove(8);

    lista.imprimir();

    lista.insert(4, 11);
    lista.imprimir();


    return 0;
}