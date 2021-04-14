#ifndef VETOR_INT_H
#define VETOR_INT_H

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE int
#define TYPED(COISA) I_ ## COISA
#define TIPO "d"

#include "vetor.h"

#undef TYPE
#undef TYPED
#undef TIPO

#endif