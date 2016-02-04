#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

int	xfree(void *ptr)
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
