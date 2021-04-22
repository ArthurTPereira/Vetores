#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor_complexo.h"
#include "vetor_double.h"
#include "vetor_int.h"
#include "Complexo.h"

struct CD_vetor {
    int nAtual;
    int nMax;
    int i;
    D_complexo_t** vet;
};

typedef struct D_complexo D_complexo_t;

CD_vetor_t* CD_CriaVetor(int qtdElementos) {
    CD_vetor_t* vetor = (CD_vetor_t*) malloc(sizeof(CD_vetor_t));
    vetor->nMax = 100;
    
    int count = 0;
    while (count < 5) {
        if (qtdElementos == vetor->nMax) {
            vetor->nMax *= 2;
        } else if (qtdElementos <= vetor->nMax / 4) {
            vetor->nMax /= 2;
        }
        count ++;
    }

    vetor->nAtual = qtdElementos;
    vetor->i = 0;

    vetor->vet = (D_complexo_t**) malloc(qtdElementos * sizeof(D_complexo_t*));

    for (int i = 0; i < qtdElementos; i++) {
        vetor->vet[i] = (D_complexo_t*) malloc(sizeof(D_complexo_t));
    }

    return vetor;
}

void CD_ImprimeVetor(CD_vetor_t* vetor) {
    for (int i = 0; i < vetor->nAtual; i++) {
        D_imprimeComplexo(vetor->vet[i]);
    }
}

void CD_ColocaValores(CD_vetor_t* vetor) {
    for (int i = 0; i < vetor->nAtual; i++) {
        D_mudaReal(vetor->vet[i],2.0);
        D_mudaImaginaria(vetor->vet[i],1.0);
    }
}

void CD_DestroiVetor(CD_vetor_t* vetor) {
    if (vetor == NULL) {
        return;
    }

    for (int i = 0; i < vetor->nAtual; i++) {
        if (vetor->vet[i] != NULL) {
            D_destroiComplexo(vetor->vet[i]);
            vetor->vet[i] = NULL;
        }
    }

    if (vetor->vet != NULL) {
        free(vetor->vet);
        vetor->vet = NULL;
    }

    free(vetor);
    vetor = NULL;
}

void CD_AtribuiCopia(CD_vetor_t* vetorCopia, CD_vetor_t* vetor) {
    vetorCopia->nAtual = vetor->nAtual;
    vetorCopia->nMax = vetor->nMax;
    vetorCopia->i = vetor->i;
    vetorCopia->vet = vetor->vet;
}

CD_vetor_t* CD_CopiaNovo(CD_vetor_t* vetor) {
    CD_vetor_t* novo = (CD_vetor_t*) malloc(sizeof(CD_vetor_t));
    novo->vet = (D_complexo_t**) malloc(vetor->nAtual * sizeof(D_complexo_t*));

    novo->nAtual = vetor->nAtual;
    novo->nMax = vetor->nMax;
    novo->i = vetor->i;
    novo->vet = vetor->vet;
    return novo;
}

int CD_Devolve_nAtual(CD_vetor_t* vetor) {
    return vetor->nAtual;
}

int CD_Devolve_nMax(CD_vetor_t* vetor) {
    return vetor->nMax;
}

int CD_DevolveIndice(CD_vetor_t* vetor) {
    return vetor->i;
}

D_complexo_t* CD_DevolvePrimeiroElemento(CD_vetor_t* vetor) {
    vetor->i = 0;
    return vetor->vet[vetor->i];
}

D_complexo_t* CD_DevolveProximoElemento(CD_vetor_t* vetor) {
    if (vetor->i == vetor->nAtual) {
        return 0;
    }
    
    vetor->i += 1;
    return vetor->vet[vetor->i];
}

D_complexo_t* CD_DevolveElementoAnterior(CD_vetor_t* vetor) {
    if (vetor->i == 0) {
        return NULL;
    }
    
    vetor->i -= 1;
    return vetor->vet[vetor->i];
}

D_complexo_t* CD_DevolveUltimoElemento(CD_vetor_t* vetor) {
    vetor->i = vetor->nAtual - 1;
    return vetor->vet[vetor->i];
}

D_complexo_t* CD_DevolveElementoI(CD_vetor_t* vetor, int i) { // i começa em 0
    vetor->i = i;
    return vetor->vet[vetor->i];
}

void CD_AtribuiValorEmI(CD_vetor_t* vetor, int i, D_complexo_t* valor) { // i começa em 0
    vetor->i = i;
    vetor->vet[vetor->i] = valor;
}

void CD_AtribuiValorUltimaPosicao(CD_vetor_t* vetor, D_complexo_t* valor) {
    vetor->nAtual += 1;

    int count = 0;  
    while(count < 5) {
        if (vetor->nAtual == vetor->nMax) {
            vetor->nMax *= 2;
        } else if (vetor->nAtual <= vetor->nMax / 4) {
            vetor->nMax /= 2;
        }
        count ++;
    }

    vetor->vet = realloc(vetor->vet, (vetor->nAtual) * sizeof(D_complexo_t));
    vetor->i = vetor->nAtual;
    vetor->vet[vetor->i-1] = valor;
}

D_complexo_t* CD_EliminaValorEmI(CD_vetor_t* vetor, int posicao) {
    D_complexo_t* temp = (D_complexo_t*) malloc(sizeof(D_complexo_t));
    temp = vetor->vet[posicao - 1];
    for (int i = posicao - 1; i < vetor->nAtual - 1; ++i) {
        vetor->vet[i] = vetor->vet[i+1];
    }

    vetor->i = posicao - 1;
    vetor->nAtual -= 1;

    int count = 0;
    while(count < 5) {
        if (vetor->nAtual == vetor->nMax) {
            vetor->nMax *= 2;
        } else if (vetor->nAtual <= vetor->nMax / 4) {
            vetor->nMax /= 2;
        }
        count ++;
    }

    vetor->vet = realloc(vetor->vet,vetor->nAtual * sizeof(D_complexo_t));
    return temp;
}

// void CD_EliminaTodosElementos(CD_vetor_t* vetor) {
//     vetor->nAtual = 0;
//     vetor->nMax = 0;
//     vetor->i = 0;
//     for (int i = 0; i < vetor->nAtual; i++) {
//         free(vetor->vet[i]);
//     }
//     free(vetor->vet);
// }

D_complexo_t* CD_RetornaMaiorModulo(CD_vetor_t* vetor) {
    D_complexo_t* maior = D_criaComplexo(0,0);
    int pos;
    for (int i = 0; i < vetor->nAtual; i++) {
        if(D_retornaMagnitude(maior) < D_retornaMagnitude(vetor->vet[i])) {
            maior = vetor->vet[i];
            pos = i;
        }
    }
    
    vetor->i = pos;
    return maior;
}

D_complexo_t* CD_RetornaMenorModulo(CD_vetor_t* vetor) {
    D_complexo_t* menor = D_criaComplexo(0,0);
    menor = vetor->vet[0];
    int pos;
    for (int i = 0; i < vetor->nAtual; i++) {
        if (D_retornaMagnitude(vetor->vet[i]) < D_retornaMagnitude(menor)) {
            menor = vetor->vet[i];
            pos = i;
        }
    }

    vetor->i = pos;
    return menor;
}

int CD_RetornaQtdIguais(CD_vetor_t* vetor, D_complexo_t* valor) {
    int count = 0;
    for (int i = 0; i < vetor->nAtual; i++) {
        if (D_retornaMagnitude(D_subtraiComplexos(vetor->vet[i],valor)) > -0.0001 && D_retornaMagnitude(D_subtraiComplexos(vetor->vet[i],valor)) < 0.0001) {
            count++;
        }
    }
    return count;
}

// CD_vetor_t* CD_DevolveVetorComElementosIguais(CD_vetor_t* vetor, D_complexo_t* valor) { //Vazamento de memoria
//     int count = 0;
//     for (int i = 0; i < vetor->nAtual; i++) {
//         if (D_retornaMagnitude(D_subtraiComplexos(vetor->vet[i],valor)) > -0.0001 && D_retornaMagnitude(D_subtraiComplexos(vetor->vet[i],valor)) < 0.0001) {
//             count++;
//         }
//     }
    
//     CD_vetor_t* novo = (CD_vetor_t*) malloc(sizeof(CD_vetor_t));
//     novo->i = 0;
//     novo->nMax = 100;
//     novo->nAtual = count;
//     novo->vet = (D_complexo_t**) malloc(count * sizeof(D_complexo_t*));

//     for (int i = 0; i < count; i++) {
//         novo->vet[i] = (D_complexo_t*) malloc(sizeof(D_complexo_t));
//     }

//     if (count == 0) {
//         return novo;
//     }

//     int temp = 0;

//     for (int i = 0; i < vetor->nAtual; i++) {
//         if (D_retornaMagnitude(D_subtraiComplexos(vetor->vet[i],valor)) > -0.0001 && D_retornaMagnitude(D_subtraiComplexos(vetor->vet[i],valor)) < 0.0001) {
//             D_mudaReal(novo->vet[temp],i);
//             D_mudaImaginaria(novo->vet[temp],0);
//             temp++;
//             printf("%d",i);
//         }
//     }

//     int temp2 = 0;
//     while (temp2 < 5) {
//         if (count == novo->nMax) {
//             novo->nMax *= 2;
//         } else if (count <= novo->nMax / 4) {
//             novo->nMax /= 2;
//         }
//         temp2 ++;
//     }

//     return novo;
// }
