/*
** my_getnbr_base.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:58:38 2012 antoine kepeklian
** Last update Thu Feb 23 16:33:10 2012 antoine kepeklian
*/

#include "lib.h"

int	my_getnbr_base(char *str, char *base)
{
  int	nbr;
  int	sign;
  int	i;

  sign = 1;
  i = 0;
  nbr = 0;
  while (str[i])
    {
      if (my_char_is_in_base(str[i], base) == -1)
	{
	  if (str[i] == '+' && nbr == 0);
	  else if (str[i] == '-' && nbr == 0)
	    sign = -sign;
	  else
	    return (nbr * sign);
	}
      else
	nbr = nbr * my_strlen(base) + my_char_is_in_base(str[i], base);
      i = i + 1;
    }
  return (nbr * sign);
}
