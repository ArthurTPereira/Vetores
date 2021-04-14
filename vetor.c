#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#ifdef TYPE
#ifdef TYPED


TYPED(vetor_t)* TYPED(CriaVetor)(int qtdElementos) {
    TYPED(vetor_t)* vetor = (TYPED(vetor_t)*) malloc(sizeof(TYPED(vetor_t)));
    vetor->nMax = 100;

    int count = 0; // Gambiarra
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
    vetor->vet = (TYPE*) malloc(vetor->nAtual * sizeof(TYPE));

    return vetor;
}

void TYPED(DestroiVetor)(TYPED(vetor_t)* vetor) {
    free(vetor->vet);
    free(vetor);
}

void TYPED(ImprimeVetor)(TYPED(vetor_t)* vetor) {
    char parametros[50];
    strcpy(parametros,"");
    strcat(parametros," %");
    strcat(parametros,TIPO);
    strcat(parametros,"\n");
    
    for (int i = 0; i < vetor->nAtual; ++i) {
        printf(parametros,vetor->vet[i]);
    }
}

void TYPED(AtribuiCopia)(TYPED(vetor_t)* vetorCopia, TYPED(vetor_t)* vetor) {
    vetorCopia->nAtual = vetor->nAtual;
    vetorCopia->nMax = vetor->nMax;
    vetorCopia->i = vetor->i;
    vetorCopia->vet = vetor->vet;
}

TYPED(vetor_t)* TYPED(CopiaNovo)(TYPED(vetor_t)* vetor) {
    TYPED(vetor_t)* novo = (TYPED(vetor_t)*) malloc(sizeof(TYPED(vetor_t)));
    novo->vet = (TYPE*) malloc (vetor->nAtual * sizeof(TYPE));

    novo->nAtual = vetor->nAtual;
    novo->nMax = vetor->nMax;
    novo->i = vetor->i;
    novo->vet = vetor->vet;
    return novo;
}

int TYPED(Devolve_nAtual)(TYPED(vetor_t)* vetor) {
    return vetor->nAtual;
}

int TYPED(Devolve_nMax)(TYPED(vetor_t)* vetor) {
    return vetor->nMax;
}

int TYPED(DevolveIndice)(TYPED(vetor_t)* vetor) {
    return vetor->i;
}

TYPE TYPED(DevolvePrimeiroElemento)(TYPED(vetor_t)* vetor) {
    vetor->i = 0;
    return vetor->vet[vetor->i];
}

TYPE TYPED(DevolveProximoElemento)(TYPED(vetor_t)* vetor) {
    if (vetor->i == vetor->nAtual) {
        printf("deu zika");
        return 0;
    }
    
    vetor->i += 1;
    return vetor->vet[vetor->i];
}

TYPE TYPED(DevolveElementoAnterior)(TYPED(vetor_t)* vetor) {
    if (vetor->i == 0) {
        printf("deu zika");
        return 0;
    }
    
    vetor->i -= 1;
    return vetor->vet[vetor->i];
}

TYPE TYPED(DevolveUltimoElemento)(TYPED(vetor_t)* vetor) {
    vetor->i = vetor->nAtual - 1;
    return vetor->vet[vetor->i];
}

TYPE TYPED(DevolveElementoI)(TYPED(vetor_t)* vetor, int i) { // i começa em 0
    vetor->i = i;
    return vetor->vet[vetor->i];
}

void TYPED(AtribuiValorEmI)(TYPED(vetor_t)* vetor, int i, TYPE valor) { // i começa em 0
    vetor->i = i;
    vetor->vet[vetor->i] = valor;
}

void TYPED(AtribuiValorUltimaPosicao)(TYPED(vetor_t)* vetor, double valor) {
    vetor->nAtual += 1;

    int count = 0;  //Gambiarra
    while(count < 5) {
        if (vetor->nAtual == vetor->nMax) {
            vetor->nMax *= 2;
        } else if (vetor->nAtual <= vetor->nMax / 4) {
            vetor->nMax /= 2;
        }
        count ++;
    }

    vetor->vet = realloc(vetor->vet, (vetor->nAtual) * sizeof(TYPE));
    vetor->i = vetor->nAtual;
    vetor->vet[vetor->i-1] = valor;
}


TYPE TYPED(EliminaValorEmI)(TYPED(vetor_t)* vetor, int posicao) {
    TYPE temp = vetor->vet[posicao];
    for (int i = posicao - 1; i < vetor->nAtual - 1; ++i) {
        vetor->vet[i] = vetor->vet[i+1];
    }

    vetor->i = posicao - 1;
    vetor->nAtual -= 1;

    int count = 0;  //Gambiarra
    while(count < 5) {
        if (vetor->nAtual == vetor->nMax) {
            vetor->nMax *= 2;
        } else if (vetor->nAtual <= vetor->nMax / 4) {
            vetor->nMax /= 2;
        }
        count ++;
    }

    vetor->vet = realloc(vetor->vet,vetor->nAtual * sizeof(TYPE));
    return temp;
}

void TYPED(EliminaTodosElementos)(TYPED(vetor_t)* vetor) {
    vetor->nAtual = 0;
    vetor->nMax = 0;
    vetor->i = 0;
    free(vetor->vet);
}

TYPE TYPED(RetornaMaiorModulo)(TYPED(vetor_t)* vetor) {
    TYPE maior = 0;
    int pos;
    for (int i = 0; i < vetor->nAtual; i++) {
        if(maior < fabs(vetor->vet[i])) {
            maior = fabs(vetor->vet[i]);
            pos = i;
        }
    }
    
    vetor->i = pos;
    return maior;
}

TYPE TYPED(RetornaMenorModulo)(TYPED(vetor_t)* vetor) {
    TYPE menor = vetor->vet[0];
    int pos;
    for (int i = 0; i < vetor->nAtual; i++) {
        if (fabs(vetor->vet[i]) < menor) {
            menor = fabs(vetor->vet[i]);
            pos = i;
        }
    }

    vetor->i = pos;
    return menor;
}

int TYPED(RetornaQtdIguais)(TYPED(vetor_t)* vetor, double valor) {
    int count = 0;
    for (int i = 0; i < vetor->nAtual; i++) {
        if (vetor->vet[i] - valor > -0.0001 && vetor->vet[i] - valor < 0.0001) {
            count++;
        }
    }
    return count;
}

// TYPED(vetor_t)* D_DevolveVetorComElementosIguais(TYPED(vetor_t)* vetor, double valor) {
//     int count = 0;
//     for (int i = 0; i < vetor->nAtual; i++) {
//         if (vetor->vet[i] - valor > -0.0001 && vetor->vet[i] - valor < 0.0001) {
//             count++;
//         }
//     }
// }

void TYPED(ColocaValores)(TYPED(vetor_t)* vetor) { // temporario
    for (int i = 0; i < vetor->nAtual; ++i) {
        vetor->vet[i] = (TYPE)i;
    }
}

#endif
#endif