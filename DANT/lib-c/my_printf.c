/*
** my_printf.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:59 2012 antoine kepeklian
** Last update Wed Jan 18 17:58:01 2012 antoine kepeklian
*/

#include "lib.h"

t_pf			my_printf_fct[] =
  {
    {'i', &my_printf_nbr},
    {'d', &my_printf_nbr},
    {'s', &my_printf_str},
    {'c', &my_printf_chr},
    {'p', &my_printf_mem},
    {'x', &my_printf_hex_min},
    {'X', &my_printf_hex_maj},
    {'b', &my_printf_bin},
    {'m', &my_printf_err},
    {'%', &my_printf_pct},
    {'u', &my_printf_nbr_uns},
    {0, NULL}
  };

int		my_printf(const char *all, ...)
{
  va_list	ap;
  int		i;
  int		j;

  j = 0;
  i = 0;
  va_start(ap, all);
  while (all[i])
    {
      if (all[i] == '%')
	{
	  i = i + 1;
	  while (my_printf_fct[j].flag != all[i] && my_printf_fct[j].flag != 0)
	    j = j + 1;
	  my_printf_fct[j].funct(&ap);
	}
      else
	my_putchar(all[i]);
      i = i + 1;
    }
  va_end(ap);
  return (EXIT_SUCCESS);
}

