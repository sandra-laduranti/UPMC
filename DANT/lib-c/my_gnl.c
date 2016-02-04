/*
** my_gnl.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:58:27 2012 antoine kepeklian
** Last update Sat Jan 21 15:54:39 2012 antoine kepeklian
*/

#include "lib.h"

int		read_gnl(const int fd, int *i, int *rd, char *buffer)
{
  if (*i == *rd)
    {
      *i = 0;
      if (!(*rd = xread(fd, buffer, GNL_SIZE)))
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		end_of_line(const int fd, int *i, int *rd, char *buffer)
{
  while (buffer[*i] && buffer[*i] != '\n')
    {
      (*i) = (*i) + 1;
      if (!(*rd = xread(fd, buffer, GNL_SIZE)))
        return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

char		*get_next_line(const int fd)
{
  static char	buffer[GNL_SIZE];
  static int	i = 0;
  static int	rd = 0;
  int		n;
  char	        *res;

  n = 0;
  if (!(read_gnl(fd, &i, &rd, buffer)))
    return (NULL);
  res = xmalloc(GNL_SIZE * sizeof(*res));
  while (buffer[i] && buffer[i] != '\n' && n < GNL_SIZE)
    {
      res[n++] = buffer[i++];
      if (!(read_gnl(fd, &i, &rd, buffer)))
        return (res);
    }
  if (n == GNL_SIZE)
    if (!(end_of_line(fd, &i, &rd, buffer)))
      return (res);
  i = i + 1;
  return (res);
}
