/*
** my_char_is_num.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:58:48 2012 antoine kepeklian
** Last update Wed Jan 18 17:58:50 2012 antoine kepeklian
*/

#include "lib.h"

int	my_char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
