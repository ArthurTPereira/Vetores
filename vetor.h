#ifdef TYPE
#ifdef TYPED

typedef struct TYPED(vetor) {
    int nAtual;
    int nMax;
    int i;
    TYPE* vet;
} TYPED(vetor_t);

TYPED(vetor_t)* TYPED(CriaVetor)(int qtdElementos);

void TYPED(DestroiVetor)(TYPED(vetor_t)* vetor);

void TYPED(ImprimeVetor)(TYPED(vetor_t)* vetor);

void TYPED(AtribuiCopia)(TYPED(vetor_t)* vetorCopia, TYPED(vetor_t)* vetor);

TYPED(vetor_t)* TYPED(CopiaNovo)(TYPED(vetor_t)* vetor);

int TYPED(Devolve_nAtual)(TYPED(vetor_t)* vetor);

int TYPED(Devolve_nMax)(TYPED(vetor_t)* vetor);

int TYPED(DevolveIndice)(TYPED(vetor_t)* vetor);

TYPE TYPED(DevolvePrimeiroElemento)(TYPED(vetor_t)* vetor);

TYPE TYPED(DevolveProximoElemento)(TYPED(vetor_t)* vetor);

TYPE TYPED(DevolveElementoAnterior)(TYPED(vetor_t)* vetor);

TYPE TYPED(DevolveUltimoElemento)(TYPED(vetor_t)* vetor);

TYPE TYPED(DevolveElementoI)(TYPED(vetor_t)* vetor, int i);

void TYPED(AtribuiValorEmI)(TYPED(vetor_t)* vetor, int i, TYPE valor);

void TYPED(AtribuiValorUltimaPosicao)(TYPED(vetor_t)* vetor, double valor);

TYPE TYPED(EliminaValorEmI)(TYPED(vetor_t)* vetor, int posicao);

void TYPED(EliminaTodosElementos)(TYPED(vetor_t)* vetor);

TYPE TYPED(RetornaMaiorModulo)(TYPED(vetor_t)* vetor);

TYPE TYPED(RetornaMenorModulo)(TYPED(vetor_t)* vetor);

int TYPED(RetornaQtdIguais)(TYPED(vetor_t)* vetor, double valor);

TYPED(vetor_t)* TYPED(DevolveVetorComElementosIguais)(TYPED(vetor_t)* vetor, double valor);

TYPED(vetor_t)* TYPED(SomaVetores)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2);

TYPE TYPED(ProdutoInterno)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2);

TYPED(vetor_t)* TYPED(SubtraiVetores)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2);

void TYPED(MultiplicaPorEscalar)(TYPED(vetor_t)* vetor, TYPE escalar);

void TYPED(AcumulaSoma)(TYPED(vetor_t)* vetor1, TYPED(vetor_t)* vetor2);

double TYPED(MediaAritmetica)(TYPED(vetor_t)* vetor);

double TYPED(Variancia)(TYPED(vetor_t)* vetor);

double TYPED(DesvioPadrao)(TYPED(vetor_t)* vetor);

void TYPED(QuickSort)(TYPE* vetor, int menor, int maior);

void TYPED(QuickSortInvertido)(TYPE* vetor, int menor, int maior);

TYPE TYPED(Mediana)(TYPED(vetor_t)* vetor);

int TYPED(Criterio)(TYPE a, TYPE b);

void TYPED(OrdenaElementosVetor)(TYPED(vetor_t)* vetor, int crit);


void TYPED(ColocaValores)(TYPED(vetor_t)* vetor);

#endif
#endif
