/*
** my_putchar.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:31 2012 antoine kepeklian
** Last update Fri Jan 20 19:20:08 2012 antoine kepeklian
*/

#include "lib.h"

void	my_putchar(char c)
{
  int	ret;
  ret = write(1, &c, 1);
  if (ret == -1)
    {
      my_fprintf(MY_STDERR, "Cannot putchar\n");
      exit(EXIT_FAILURE);
    }
}
