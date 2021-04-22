#include <stdio.h>
#include <stdlib.h>

int main() {

    #include "vetor_int.h"
    #include "vetor_double.h"
    #include "vetor_complexo.h"

    CD_vetor_t* complexos = CD_CriaVetor(6);
    CD_ColocaValores(complexos);
    CD_ImprimeVetor(complexos);

    //CD_vetor_t* copia = CD_CriaVetor(6);
    //CD_AtribuiCopia(copia,complexos); //cópia recebe complexos

    //printf("\n\n Copiado : \n");
    //CD_ImprimeVetor(copia);


    CD_DestroiVetor(complexos);
    //CD_DestroiVetor(copia);
    return 0;
}