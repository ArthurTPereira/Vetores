#ifndef VETOR_COMPLEXO_H
#define VETOR_COMPLEXO_H

typedef struct CD_vetor CD_vetor_t;

typedef struct D_complexo D_complexo_t;

typedef struct I_vetor I_vetor_t;

CD_vetor_t* CD_CriaVetor(int qtdElementos);

void CD_ImprimeVetor(CD_vetor_t* vetor);

void CD_ColocaValores(CD_vetor_t* vetor);

void CD_DestroiVetor(CD_vetor_t* vetor);

void CD_AtribuiCopia(CD_vetor_t* vetorCopia, CD_vetor_t* vetor);

CD_vetor_t* CD_CopiaNovo(CD_vetor_t* vetor);

int CD_Devolve_nAtual(CD_vetor_t* vetor);

int CD_Devolve_nMax(CD_vetor_t* vetor);

int CD_DevolveIndice(CD_vetor_t* vetor);

D_complexo_t* CD_DevolvePrimeiroElemento(CD_vetor_t* vetor);

D_complexo_t* CD_DevolveProximoElemento(CD_vetor_t* vetor);

D_complexo_t* CD_DevolveElementoAnterior(CD_vetor_t* vetor);

D_complexo_t* CD_DevolveUltimoElemento(CD_vetor_t* vetor);

D_complexo_t* CD_DevolveElementoI(CD_vetor_t* vetor, int i);

void CD_AtribuiValorEmI(CD_vetor_t* vetor, int i, D_complexo_t* valor);

void CD_AtribuiValorUltimaPosicao(CD_vetor_t* vetor, D_complexo_t* valor);

D_complexo_t* CD_EliminaValorEmI(CD_vetor_t* vetor, int posicao);

D_complexo_t* CD_RetornaMaiorModulo(CD_vetor_t* vetor);

D_complexo_t* CD_RetornaMenorModulo(CD_vetor_t* vetor);

int CD_RetornaQtdIguais(CD_vetor_t* vetor, D_complexo_t* valor);

I_vetor_t* CD_DevolveVetorComElementosIguais(CD_vetor_t* vetor, D_complexo_t* valor);

CD_vetor_t* CD_SomaVetores(CD_vetor_t* vetor1, CD_vetor_t* vetor2);

D_complexo_t* CD_ProdutoInterno(CD_vetor_t* vetor1, CD_vetor_t* vetor2);

CD_vetor_t* CD_SubtraiVetores(CD_vetor_t* vetor1, CD_vetor_t* vetor2);

void CD_MultiplicaPorEscalar(CD_vetor_t* vetor, double escalar);

void CD_AcumulaSoma(CD_vetor_t* vetor1, CD_vetor_t* vetor2);

D_complexo_t* CD_MediaAritmetica(CD_vetor_t* vetor);

D_complexo_t* CD_Variancia(CD_vetor_t* vetor);

D_complexo_t* CD_DesvioPadrao(CD_vetor_t* vetor);

#endif