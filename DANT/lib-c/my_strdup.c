/*
** my_strdup.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:00 2012 antoine kepeklian
** Last update Fri Jan 20 19:19:44 2012 antoine kepeklian
*/

#include "lib.h"

char	*my_strdup(char *str)
{
  char	*dup;
  int	i;

  i = 0;
  dup = malloc((my_strlen(str) + 1) * sizeof(*str));
  if (!dup)
    {
      my_fprintf(MY_STDERR, "Cannot duplicate this string\n");
      return (NULL);
    }
  while (str[i])
    {
      dup[i] = str[i];
      i = i + 1;
    }
  dup[i] = 0;
  return (dup);
}
