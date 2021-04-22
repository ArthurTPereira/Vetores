#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#ifdef TYPE
#ifdef TYPED

TYPED(vetor_t)* TYPED(CriaVetor)(int qtdElementos) {
    TYPED(vetor_t)* vetor = (TYPED(vetor_t)*) malloc(sizeof(TYPED(vetor_t)));
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
    vetor->vet = (TYPE*) malloc(vetor->nAtual * sizeof(TYPE));

    return vetor;
}

void TYPED(DestroiVetor)(TYPED(vetor_t)* vetor) {
    if (vetor->vet != NULL) {
    free(vetor->vet);
    }
    if (vetor != NULL) {
    free(vetor);
    }
}

void TYPED(ImprimeVetor)(TYPED(vetor_t)* vetor) {
    if(vetor == NULL) {
        return;
    }
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

    int count = 0;  
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


TYPE TYPED(EliminaValorEmI)(TYPED(vetor_t)* vetor, int posicao) { // Posicao começando em 1
    TYPE temp = vetor->vet[posicao - 1];
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

TYPED(vetor_t)* TYPED(DevolveVetorComElementosIguais)(TYPED(vetor_t)* vetor, double valor) {
    int count = 0;
    for (int i = 0; i < vetor->nAtual; i++) {
        if (vetor->vet[i] - valor > -0.0001 && vetor->vet[i] - valor < 0.0001) {
            count++;
        }
    }
    
    TYPED(vetor_t)* novo = (TYPED(vetor_t)*) malloc(sizeof(TYPED(vetor_t)));
    novo->i = 0;
    novo->nMax = 100;
    novo->nAtual = count;
    novo->vet = (TYPE*) malloc(count * sizeof(TYPE));

    if (count == 0) {
        return novo;
    }

    int temp = 0;

    for (int i = 0; i < vetor->nAtual; i++) {
        if (vetor->vet[i] - valor > -0.0001 && vetor->vet[i] - valor < 0.0001) {
            novo->vet[temp] = i;
            temp++;
            printf("%d",i);
        }
    }

    int temp2 = 0;
    while (temp2 < 5) {
        if (count == novo->nMax) {
            novo->nMax *= 2;
        } else if (count <= novo->nMax / 4) {
            novo->nMax /= 2;
        }
        temp2 ++;
    }

    return novo;
}

TYPED(vetor_t)* TYPED(SomaVetores)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2) {
    if (vetor1->nAtual != vetor2->nAtual) {
        return NULL;
    }
    
    TYPED(vetor_t)* soma = TYPED(CriaVetor)(vetor1->nAtual);

    for (int i = 0; i < vetor1->nAtual; i++) {
        soma->vet[i] = vetor1->vet[i] + vetor2->vet[i]; 
    }
    
    return soma;
}

TYPE TYPED(ProdutoInterno)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2) {
    if (vetor1->nAtual != vetor2->nAtual) {
        return 0;
    }
    TYPE produto = 0;
    for (int i = 0; i < vetor1->nAtual; i++) {
        produto += vetor1->vet[i] * vetor2->vet[i];
    }

    return produto;
}

TYPED(vetor_t)* TYPED(SubtraiVetores)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2) {
    if (vetor1->nAtual != vetor2->nAtual) {
        return NULL;
    }

    TYPED(vetor_t)* diferenca = TYPED(CriaVetor)(vetor1->nAtual);

    for (int i = 0; i < vetor1->nAtual; i++) {
        diferenca->vet[i] = vetor1->vet[i] - vetor2->vet[i]; 
    }

    return diferenca;
}

void TYPED(MultiplicaPorEscalar)(TYPED(vetor_t)* vetor, TYPE escalar) {
    for (int i = 0; i < vetor->nAtual; i++) {
        vetor->vet[i] *= escalar;
    }
}

void TYPED(AcumulaSoma)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2) {
    if (vetor1->nAtual != vetor2->nAtual) {
        exit(1);
    }
    
    for (int i = 0; i < vetor1->nAtual; i++) {
        vetor1->vet[i] += vetor2->vet[i];
    }
}

double TYPED(MediaAritmetica)(TYPED(vetor_t)* vetor) {
    double media = 0;
    for (int i = 0; i < vetor->nAtual; i++) {
        media += vetor->vet[i];
    }
    media /= vetor->nAtual;
    return media;
}

double TYPED(Variancia)(TYPED(vetor_t)* vetor) {
    double media = TYPED(MediaAritmetica)(vetor);
    double somatorio = 0;
    double variancia;


    for (int i = 0; i < vetor->nAtual; i++) {
        somatorio += pow((vetor->vet[i] - media),2);
    }
    variancia = somatorio /(vetor->nAtual - 1);

    return variancia;
}

double TYPED(DesvioPadrao)(TYPED(vetor_t)* vetor) { // Desvio padrao amostral***
    double variancia = TYPED(Variancia)(vetor);
    double desvioPadrao = sqrt(variancia);
    return desvioPadrao;
}

void TYPED(QuickSort)(TYPE* vetor, int menor, int maior) {
   
   int aux, i, j, meio;
   TYPE pivo;

   i = menor;
   j = maior;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j) {
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(menor < j) TYPED(QuickSort)(vetor, menor, j);
   if(i < maior) TYPED(QuickSort)(vetor, i, maior);

}

void TYPED(QuickSortInvertido)(TYPE* vetor, int menor, int maior) {
   
   int aux, i, j, meio;
   TYPE pivo;

   i = menor;
   j = maior;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] > pivo) i = i + 1;
      while (vetor[j] < pivo) j = j - 1;
      
      if(i <= j) {
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(menor < j) TYPED(QuickSortInvertido)(vetor, menor, j);
   if(i < maior) TYPED(QuickSortInvertido)(vetor, i, maior);

}

TYPE TYPED(Mediana)(TYPED(vetor_t)* vetor) {
    TYPE mediana;
    TYPE* temp = (TYPE*) malloc(vetor->nAtual * sizeof(TYPE));
    
    for (int i = 0; i < vetor->nAtual; i++) {
        temp[i] = vetor->vet[i];
    }

    TYPED(QuickSort)(temp,0,vetor->nAtual);
    
    if (vetor->nAtual % 2 == 0) {
        mediana = (temp[(vetor->nAtual - 1)/2] + temp[(vetor->nAtual)/2])/2.0;
    } else {
        mediana = temp[(vetor->nAtual + 1) / 2];
    }

    free(temp);

    return mediana;
}

int TYPED(Criterio)(TYPE a, TYPE b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

void TYPED(OrdenaElementosVetor)(TYPED(vetor_t)* vetor, int crit) {
    if(crit == 0) {
        return;
    }
    if(crit == -1) {
        TYPED(QuickSort)(vetor->vet, 0, vetor->nAtual);
    }
    if(crit == 1) {
        TYPED(QuickSortInvertido)(vetor->vet,0,vetor->nAtual);
    }
}

void TYPED(ColocaValores)(TYPED(vetor_t)* vetor) {
    srand(time(NULL));
    for (int i = 0; i < vetor->nAtual; ++i) {
        vetor->vet[i] = (TYPE)(rand() % 20 + 1);
        //vetor->vet[i] = (TYPE)4;
    }
}

#endif
#endif