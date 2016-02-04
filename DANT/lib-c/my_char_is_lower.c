/*
** my_char_is_lower.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 18:00:36 2012 antoine kepeklian
** Last update Wed Jan 18 18:00:47 2012 antoine kepeklian
*/

#include "lib.h"

int	my_char_is_lower(char c)
{
  if (c >= 'a' && c <= 'z')
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
