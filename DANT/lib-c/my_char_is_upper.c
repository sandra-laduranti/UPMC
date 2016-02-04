/*
** my_char_is_upper.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:58:43 2012 antoine kepeklian
** Last update Fri Jan 20 18:08:04 2012 antoine kepeklian
*/

#include "lib.h"

int	my_char_is_upper(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
