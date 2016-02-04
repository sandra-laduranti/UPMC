/*
** my_strncmp.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:55:38 2012 antoine kepeklian
** Last update Wed Jan 18 17:55:39 2012 antoine kepeklian
*/

#include "lib.h"

int	my_strncmp(char *str1, char *str2, int n)
{
  if (n < 1)
    return (1);
  while (*str1 && *str2 && n)
    {
      if (*str1++ != *str2++)
	return (1);
      n = n - 1;
    }
  return (0);
}
