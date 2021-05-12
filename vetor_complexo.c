#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vetor_complexo.h"
#include "vetor_double.h"
#include "vetor_int.h"
#include "Complexo.h"

#include <time.h>

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
    srand(time(NULL));
    for (int i = 0; i < vetor->nAtual; i++) {
        D_mudaReal(vetor->vet[i],(rand() % 5 + 1));
        D_mudaImaginaria(vetor->vet[i],(rand() % 5 + 1));
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

D_complexo_t* CD_RetornaMaiorModulo(CD_vetor_t* vetor) {
    D_complexo_t* maior = D_criaComplexo(0,0);
    int pos;
    for (int i = 0; i < vetor->nAtual; i++) {
        if(D_retornaMagnitude(maior) < D_retornaMagnitude(vetor->vet[i])) {
            *maior = *vetor->vet[i];
            pos = i;
        }
    }
    
    vetor->i = pos;
    return maior;
}

D_complexo_t* CD_RetornaMenorModulo(CD_vetor_t* vetor) {
    D_complexo_t* menor = D_criaComplexo(0,0);
    *menor = *vetor->vet[0];
    int pos;
    for (int i = 0; i < vetor->nAtual; i++) {
        if (D_retornaMagnitude(vetor->vet[i]) < D_retornaMagnitude(menor)) {
            *menor = *vetor->vet[i];
            pos = i;
        }
    }

    vetor->i = pos;
    return menor;
}

int CD_RetornaQtdIguais(CD_vetor_t* vetor, D_complexo_t* valor) {
    int count = 0;
    D_complexo_t* temp;
    D_complexo_t* temp2;

    for (int i = 0; i < vetor->nAtual; i++) {
        temp = D_subtraiComplexos(vetor->vet[i],valor);
        temp2 = D_subtraiComplexos(vetor->vet[i],valor);
        if (D_retornaMagnitude(temp) > -0.0001 && D_retornaMagnitude(temp2) < 0.0001) {
            count++;
        }

        D_destroiComplexo(temp);
        D_destroiComplexo(temp2);
    }
    return count;
}

I_vetor_t* CD_DevolveVetorComElementosIguais(CD_vetor_t* vetor, D_complexo_t* valor) {
    int count = 0;
    D_complexo_t* tempSub;
    D_complexo_t* tempSub2;

    for (int i = 0; i < vetor->nAtual; i++) {
        tempSub = D_subtraiComplexos(vetor->vet[i],valor);
        tempSub2 = D_subtraiComplexos(vetor->vet[i],valor);
        
        if (D_retornaMagnitude(tempSub) > -0.0001 && D_retornaMagnitude(tempSub2) < 0.0001) {
            count++;
        }
    
        D_destroiComplexo(tempSub);
        D_destroiComplexo(tempSub2);
    }
    
    I_vetor_t* novo = I_CriaVetor(count);

    if (count == 0) {
        return novo;
    }
    
    int temp = 0;

    for (int i = 0; i < vetor->nAtual; i++) {
        tempSub = D_subtraiComplexos(vetor->vet[i],valor);
        tempSub2 = D_subtraiComplexos(vetor->vet[i],valor);
        
        if (D_retornaMagnitude(tempSub) > -0.0001 && D_retornaMagnitude(tempSub2) < 0.0001) {
            novo->vet[temp] = i;
            temp++;
        }

        D_destroiComplexo(tempSub);
        D_destroiComplexo(tempSub2);
    }

    return novo;
}

CD_vetor_t* CD_SomaVetores(CD_vetor_t* vetor1, CD_vetor_t* vetor2) {
    if (vetor1->nAtual != vetor2->nAtual) {
        return NULL;
    }
    
    CD_vetor_t* soma = CD_CriaVetor(vetor1->nAtual);
    D_complexo_t* temp;

    for (int i = 0; i < vetor1->nAtual; i++) {
        temp = D_somaComplexos(vetor1->vet[i],vetor2->vet[i]);
        *soma->vet[i] = *temp;
        D_destroiComplexo(temp);
    }

    return soma;
}

D_complexo_t* CD_ProdutoInterno(CD_vetor_t* vetor1, CD_vetor_t* vetor2) {
    if (vetor1->nAtual != vetor2->nAtual) {
        return 0;
    }

    D_complexo_t* produto = D_criaComplexo(0,0);
    D_complexo_t* temp;

    for (int i = 0; i < vetor1->nAtual; i++) {
        temp = D_produtoComplexos(vetor1->vet[i],vetor2->vet[i]);
        D_acumulaSoma(produto,temp);
        D_destroiComplexo(temp);
    }

    return produto;
}

CD_vetor_t* CD_SubtraiVetores(CD_vetor_t* vetor1, CD_vetor_t* vetor2) {
    if (vetor1->nAtual != vetor2->nAtual) {
        return NULL;
    }
    
    CD_vetor_t* diferenca = CD_CriaVetor(vetor1->nAtual);
    D_complexo_t* temp;

    for (int i = 0; i < vetor1->nAtual; i++) {
        temp = D_subtraiComplexos(vetor1->vet[i],vetor2->vet[i]);
        *diferenca->vet[i] = *temp;
        D_destroiComplexo(temp);
    }

    return diferenca;
}

void CD_MultiplicaPorEscalar(CD_vetor_t* vetor, double escalar) {
    for (int i = 0; i < vetor->nAtual; i++) {
        D_MudaMagnitude(vetor->vet[i],escalar);
    }
}

void CD_AcumulaSoma(CD_vetor_t* vetor1, CD_vetor_t* vetor2) {
    for (int i = 0; i < vetor1->nAtual; i++) {
        D_acumulaSoma(vetor1->vet[i],vetor2->vet[i]);
    }
}

D_complexo_t* CD_MediaAritmetica(CD_vetor_t* vetor) {
    D_complexo_t* media = D_criaComplexo(0,0);
    double real = 0, img = 0;

    for (int i = 0; i < vetor->nAtual; i++) {
        real += D_retornaReal(vetor->vet[i]);
        img += D_retornaImaginaria(vetor->vet[i]);
    }
    
    real /= vetor->nAtual;
    img /= vetor->nAtual;
    
    D_mudaReal(media,real);
    D_mudaImaginaria(media,img);

    return media;
}

D_complexo_t* CD_Variancia(CD_vetor_t* vetor) {
    D_complexo_t* media = CD_MediaAritmetica(vetor);
    
    D_complexo_t* variancia = D_criaComplexo(0,0);
    double real = 0, img = 0;

    for (int i = 0; i < vetor->nAtual; i++) {
        real += pow((D_retornaReal(vetor->vet[i]) - D_retornaReal(media)),2);
        img += pow((D_retornaImaginaria(vetor->vet[i]) - D_retornaImaginaria(media)),2);
    }

    real /= (vetor->nAtual - 1);
    img /= (vetor->nAtual - 1);

    D_mudaReal(variancia,real);
    D_mudaImaginaria(variancia,img);

    D_destroiComplexo(media);
    return variancia;
}

D_complexo_t* CD_DesvioPadrao(CD_vetor_t* vetor) {
    D_complexo_t* desvio = CD_Variancia(vetor);

    double real = sqrt(D_retornaReal(desvio));
    double img = sqrt(D_retornaImaginaria(desvio));

    D_mudaReal(desvio,real);
    D_mudaImaginaria(desvio,img);

    return desvio;
}