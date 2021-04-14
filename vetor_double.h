#ifndef VETOR_DOUBLE_H
#define VETOR_DOUBLE_H

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE double
#define TYPED(COISA) D_ ## COISA
#define TIPO "lf"

#include "vetor.h"

#undef TYPE
#undef TYPED
#undef TIPO

#endif