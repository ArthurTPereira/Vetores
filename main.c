#include <stdio.h>
#include <stdlib.h>

int main() {

    #include "vetor_int.h"
    #include "vetor_double.h"
    #include "vetor_complexo.h"

    CD_vetor_t* complexos = CD_CriaVetor(6);
    CD_vetor_t* complexos2 = CD_CriaVetor(6);
    CD_ColocaValores(complexos);
    CD_ColocaValores(complexos2);

    printf("Vetor 1:\n");
    CD_ImprimeVetor(complexos);

    printf("Vetor 2:\n");
    CD_ImprimeVetor(complexos2);


    CD_DestroiVetor(complexos);
    CD_DestroiVetor(complexos2);
    return 0;
}