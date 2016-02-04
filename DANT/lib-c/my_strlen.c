/*
** my_strlen.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:55:53 2012 antoine kepeklian
** Last update Wed Jan 18 17:55:55 2012 antoine kepeklian
*/

#include "lib.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
