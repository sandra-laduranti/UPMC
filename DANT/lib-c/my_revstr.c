/*
** my_revstr.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:46 2012 antoine kepeklian
** Last update Wed Jan 18 17:56:48 2012 antoine kepeklian
*/

#include "lib.h"

char	*my_revstr(char *str)
{
  int	len;
  int	half;
  int	i;
  char	tmp;

  len = my_strlen(str);
  half = len / 2;
  i = 0;
  len = len - 1;
  while (i < half)
    {
      tmp = str[i];
      str[i] = str[len - i];
      str[len - i] = tmp;
      i = i + 1;
      tmp = 0;
    }
  return (str);
}
