#include <stdio.h>
#include <stdlib.h>
#include "dico.h"

void    *xmalloc(unsigned int size)
{
  void  *ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      fprintf(stderr, "Allocation failure");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
