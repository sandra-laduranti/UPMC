/*
** my_char_is_in_base.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:59:29 2012 antoine kepeklian
** Last update Thu Feb 23 16:33:02 2012 antoine kepeklian
*/

#include "lib.h"

int	my_char_is_in_base(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i])
    {
      if (c == base[i])
	return (i);
      i = i + 1;
    }
  return (-1);
}
