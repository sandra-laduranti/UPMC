/*
** my_getnbr.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:58:32 2012 antoine kepeklian
** Last update Tue Jan 31 20:26:04 2012 sandra laduranti
*/

#include "lib.h"

int	my_getnbr(char *str)
{
  int	nbr;
  int	sign;
  int	i;

  sign = 1;
  i = 0;
  nbr = 0;
  while (str[i])
    {
      if (my_char_is_num(str[i]))
	{
	  if (str[i] == '+' && nbr == 0);
	  else if (str[i] == '-' && nbr == 0)
	    sign = -sign;
	  else
	    return (nbr * sign);
	  i = i + 1;
	}
      else
	{
	  nbr = nbr * 10 + str[i] - '0';
	  i = i + 1;
	}
    }
  return (nbr * sign);
}

