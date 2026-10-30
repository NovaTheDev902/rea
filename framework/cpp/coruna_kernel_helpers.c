/* coruna_kernel_helpers.c - Reversed Coruna kernel helper primitives (native C). */
#include "coruna_kernel_helpers.h"

/* Implementations are static inline in the header; this TU ensures the
 * reversed helpers are part of the native build. */
static int coruna_kernel_helpers_linked = 1;