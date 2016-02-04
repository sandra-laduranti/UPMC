/*
** my_char_is_space.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Tue Jan 24 19:00:59 2012 antoine kepeklian
** Last update Tue Jan 24 19:01:57 2012 antoine kepeklian
*/

#include "lib.h"

int	my_char_is_space(char c)
{
  if (c == ' ' || c == '\t')
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
