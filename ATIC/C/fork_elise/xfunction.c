#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include "tpfork.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      fprintf(stderr, "Allocation failure");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

int	xwrite(int fd, char *buffer, int size)
{
  int	ret;

  ret = write(fd, buffer, size);
  if (ret == -1)
    {
      fprintf(stderr, "Cannot Write\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	xread(int fd, char *buffer, int size)
{
  int	ret;

  ret = read(fd, buffer, size);
  if (ret == -1)
    {
      fprintf(stderr, "Cannot read\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	xclose(const int fd)
{
  if (close(fd))
    {
      fprintf(stderr, "Cannot close\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
