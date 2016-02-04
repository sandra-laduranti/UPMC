/*
** my_strcat.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:24 2012 antoine kepeklian
** Last update Wed Jan 18 17:56:26 2012 antoine kepeklian
*/

#include "lib.h"

char	*my_strcat(char *src, char *dest)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(src);
  while (dest[i])
    src[j++] = dest[i++];
  src[j] = '\0';
  return (src);
}
