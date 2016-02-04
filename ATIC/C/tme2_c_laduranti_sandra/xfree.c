#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

int     xfree(void *ptr)
{
  if (!ptr)
    {
      fprintf(stderr, "Cannot free\n");
      return (EXIT_FAILURE);
    }
  else
    free(ptr);
  return (EXIT_SUCCESS);
}
