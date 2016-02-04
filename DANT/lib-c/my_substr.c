/*
** my_substr.c for library in /home/kepekl_b//Documents/Projets/16_Korewar/rendu_grp
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 25 11:44:15 2012 antoine kepeklian
** Last update Wed Jan 25 11:45:36 2012 antoine kepeklian
*/

#include "lib.h"

char		*my_substr(int begin, int end, char *str)
{
  char		*substr;
  int		i;

  i = 0;
  substr = xmalloc((end - begin + 1) * sizeof(*substr));
  while (begin + i != end)
    {
      substr[i] = str[begin + i];
      i = i + 1;
    }
  substr[i] = 0;
  return (substr);
}
