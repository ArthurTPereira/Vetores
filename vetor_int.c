#include "vetor_int.h"

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE int
#define TYPED(COISA) I_ ## COISA
#define TIPO "d"

#include "vetor.c"
#include "Complexo.c"

#undef TYPE
#undef TYPED
#undef TIPO