/*
** my_putstr.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:53 2012 antoine kepeklian
** Last update Fri Jan 20 19:19:59 2012 antoine kepeklian
*/

#include "lib.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (!str)
    {
      my_fprintf(MY_STDERR, "Cannot print this str\n");
      exit(EXIT_FAILURE);
    }
  while (str[i])
    my_putchar(str[i++]);
}
