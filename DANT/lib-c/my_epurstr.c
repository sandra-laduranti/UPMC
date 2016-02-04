/*
** my_epurstr.c for corewar in /home/noe_f//Documents/Projets_tek1/korewar/rendu_grp/corewar/lib/src
** 
** Made by florence noe
** Login   <noe_f@epitech.net>
** 
** Started on  Wed Jan 25 13:34:12 2012 florence noe
** Last update Wed Jan 25 16:32:50 2012 antoine kepeklian
*/

#include "lib.h"

int	count_char(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' || str[i] != '\t')
	{
	  count++;
	  i++;
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      else
	{
	  count++;
	  i++;
	}
    }
  return (count);
}

char	*my_epurstr(char *str)
{
  int	i;
  int	j;
  char	*str2;

  str2 = xmalloc(sizeof(*str2) * count_char(str));
  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	str2[j++] = str[i++];
      else if (str[i] == ' ' || str[i] == '\t')
	{
	  str2[j++] = str[i++];
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
    }
  if (str2[--j] == ' ' || str2[--j] == '\t')
    str2[j] = '\0';
  return (str2);
}
