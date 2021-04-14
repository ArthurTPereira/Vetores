#include <stdio.h>


int main() {

    #include "vetor_int.h"
    #include "vetor_double.h"

    D_vetor_t* vet = D_CriaVetor(6);
    D_ColocaValores(vet);
    D_ImprimeVetor(vet);

    D_DestroiVetor(vet);


    return 0;
}