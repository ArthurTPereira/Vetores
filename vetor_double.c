#include "vetor_double.h"

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE double
#define TYPED(COISA) D_ ## COISA
#define TIPO "lf"

#include "vetor.c"

#undef TYPE
#undef TYPED
#undef TIPO