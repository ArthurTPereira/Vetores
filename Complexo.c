#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef TYPE
#ifdef TYPED

TYPED(complexo_t)* TYPED(criaComplexo)(TYPE real, TYPE img) {
    TYPED(complexo_t)* complexo = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    complexo->real = real;
    complexo->img = img;
    return complexo;
}

void TYPED(destroiComplexo)(TYPED(complexo_t)* complexo) {
    free(complexo);
}

void TYPED(atribuiComplexo)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    complexo1->real = complexo2->real;
    complexo1->img = complexo2->img;
}

TYPED(complexo_t)* TYPED(copiaComplexo)(TYPED(complexo_t)* complexo) {
    TYPED(complexo_t)* copia = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    copia->real = complexo->real;
    copia->img = complexo->img;
    return copia;
}

void TYPED(imprimeComplexo)(TYPED(complexo_t)* complexo) {
    if (complexo == NULL) {
        printf("ERRO: Complexo nulo.\n");
        return;
    }
    
    char parametros[50];
    strcpy(parametros,"");
    strcat(parametros," %");
    strcat(parametros,TIPO);
    if(complexo->img >=0) {
        strcat(parametros," +");
    }
    strcat(parametros," %");
    strcat(parametros,TIPO);
    strcat(parametros,"i");

    printf(parametros,complexo->real,complexo->img);
    printf("\n");
}

TYPE TYPED(retornaReal)(TYPED(complexo_t)* complexo) {
    return complexo->real;
}

TYPE TYPED(retornaImaginaria)(TYPED(complexo_t)* complexo) {
    return complexo->img;
}

double TYPED(retornaMagnitude)(TYPED(complexo_t)* complexo) {
    return (double)sqrt(complexo->real * complexo->real + complexo->img * complexo->img);
}

double TYPED(retornaFase)(TYPED(complexo_t)* complexo) {
    return atan(complexo->img / complexo->real);
}

void TYPED(mudaReal)(TYPED(complexo_t)* complexo,TYPE real) {
    complexo->real = real;
}

void TYPED(mudaImaginaria)(TYPED(complexo_t)* complexo,TYPE imaginaria) {
    complexo->img = imaginaria;
}

TYPED(complexo_t)* TYPED(calculaConjugado)(TYPED(complexo_t)* complexo) {
    TYPED(complexo_t)* conjugado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    conjugado->real = complexo->real;
    conjugado->img = -complexo->img;
    return conjugado;
}

TYPED(complexo_t)* TYPED(somaComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* soma = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    soma->real = complexo1->real + complexo2->real;
    soma->img = complexo1->img + complexo2->img;
    return soma;
}

void TYPED(acumulaSoma)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* temp = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    temp->real = complexo1->real + complexo2->real;
    temp->img = complexo1->img + complexo2->img;
    complexo1->real = temp->real;
    complexo1->img = temp->img;
    free(temp);
}

TYPED(complexo_t)* TYPED(subtraiComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* subtracao = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    subtracao->real = complexo1->real - complexo2->real;
    subtracao->img = complexo1->img - complexo2->img;
    return subtracao;
}

TYPED(complexo_t)* TYPED(produtoComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* produto = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    produto->real = complexo1->real * complexo2->real - complexo1->img * complexo2->img;
    produto->img = complexo1->real * complexo2->img + complexo1->img * complexo2->real;
    return produto;
}

void TYPED(acumulaProduto)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* temp = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    temp->real = complexo1->real;
    temp->img = complexo1->img;
    complexo1->real = temp->real * complexo2->real - temp->img * complexo2->img;
    complexo1->img = temp->real * complexo2->img + temp->img * complexo2->real;
    free(temp);
}

TYPED(complexo_t)* TYPED(divideComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* divisao = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    TYPE div1 = ((complexo2->real * complexo2->real) + (complexo2->img * complexo2->img));
    TYPE div2 = ((complexo2->real * complexo2->real) + (complexo2->img * complexo2->img));
    if (div1 == 0 || div2 == 0) {
        printf("Nao e possivel dividir por zero.\n");
        free(divisao);
        return NULL;
    }
    divisao->real = (((complexo1->real * complexo2->real) + (complexo1->img * complexo2->img)) / div1);
    divisao->img = (((-complexo1->real * complexo2->img) + (complexo1->img * complexo2->real)) / div2);
    return divisao;
}

TYPED(complexo_t)* TYPED(operacaoComplexo)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2, char* operador) {
    TYPED(complexo_t)* resultado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));

    if (strcmp(operador,"+") == 0) {
        resultado = TYPED(somaComplexos)(complexo1,complexo2);
    } else if(strcmp(operador, "-") == 0) {
        resultado = TYPED(subtraiComplexos)(complexo1, complexo2);
    } else if(strcmp(operador,"*")== 0) {
        resultado = TYPED(produtoComplexos)(complexo1, complexo2);
    } else if (strcmp(operador,"/") == 0) {
        resultado = TYPED(divideComplexos)(complexo1,complexo2);
    } else if (strcmp(operador,"+=") == 0) {
        TYPED(acumulaSoma)(complexo1,complexo2);
        return complexo1;
    } else if (strcmp(operador,"*=") == 0) {
        TYPED(acumulaProduto)(complexo1,complexo2);
        return complexo1;
    }

    return resultado;
}

int TYPED(verificaModulo)(TYPED(complexo_t)* complexo) {
    double modulo = (double)TYPED(retornaMagnitude)(complexo);
    if (modulo >= -0.00001 && modulo <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int TYPED(verificaReal)(TYPED(complexo_t)* complexo) {
    if (complexo->real >= -0.00001 && complexo->real <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int TYPED(verificaImaginario)(TYPED(complexo_t)* complexo) {
    if (complexo->img >= -0.00001 && complexo->img <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int TYPED(comparaModulos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    double modulo1 = TYPED(retornaMagnitude)(complexo1);
    double modulo2 = TYPED(retornaMagnitude)(complexo2);

    if (fabs(modulo1 - modulo2) <= 0.0001) {
        return 0;
    } else if (modulo1 > modulo2) {
        return 1;
    } else {
        return -1;
    }
}

int TYPED(comparaFase)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    double fase1 = TYPED(retornaFase)(complexo1);
    double fase2 = TYPED(retornaFase)(complexo2);

    if(fabs(fase1 - fase2) <= 0.0001) {
        return 0;
    }
    else if(fase1 > fase2) {
        return 1;
    }
    else {
        return -1;
    }
}

TYPED(complexo_t)* TYPED(alteraMagnitude)(TYPED(complexo_t)* complexo, int escalar) {
    TYPED(complexo_t)* escalonado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    escalonado->real = complexo->real * escalar;
    escalonado->img = complexo->img * escalar;
    return escalonado;
}

TYPED(complexo_t)* TYPED(alteraFase)(TYPED(complexo_t)* complexo) {
    TYPED(complexo_t)* transformado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    transformado->real = complexo->real;
    transformado->img = -complexo->img;
    return transformado;
}

void TYPED(MudaMagnitude)(TYPED(complexo_t)* complexo, TYPE escalar) {
    complexo->real *= escalar;
    complexo->img *= escalar;
}

void TYPED(DividePorEscalar)(TYPED(complexo_t)* complexo, TYPE escalar) {
    complexo->real /= (TYPE)escalar;
    complexo->img /= (TYPE)escalar;
}

#endif
#endif