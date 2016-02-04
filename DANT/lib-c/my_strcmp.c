/*
** my_strcmp.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:14 2012 antoine kepeklian
** Last update Wed Jan 18 17:56:17 2012 antoine kepeklian
*/

#include "lib.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (str1 == 0 && str2 == 0)
    return (0);
  else
    {
      while ((str1[i] == str2[i]) && (str1[i] || str2[i]))
	i = i + 1;
      return (str1[i] - str2[i]);
    }
}
