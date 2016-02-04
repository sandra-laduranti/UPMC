#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      printf("Allocation failure");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
