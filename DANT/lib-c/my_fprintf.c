/*
** my_fprintf.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:53 2012 antoine kepeklian
** Last update Fri Jan 20 18:07:55 2012 antoine kepeklian
*/

#include "lib.h"

t_fpf		my_fprintf_fct[] =
  {
    {'i', &my_fprintf_nbr},
    {'d', &my_fprintf_nbr},
    {'s', &my_fprintf_str},
    {'c', &my_fprintf_chr},
    {'p', &my_fprintf_mem},
    {'x', &my_fprintf_hex_min},
    {'X', &my_fprintf_hex_maj},
    {'b', &my_fprintf_bin},
    {'m', &my_fprintf_err},
    {'%', &my_fprintf_pct},
    {'u', &my_fprintf_nbr_uns},
    {0, NULL}
  };

int		my_fprintf(const int fd, const char *all, ...)
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
	  while (my_fprintf_fct[j].flag != all[i] && my_fprintf_fct[j].flag != 0)
	    j = j + 1;
	  my_fprintf_fct[j].funct(fd, &ap);
	}
      else
	my_fputchar(fd, all[i]);
      i = i + 1;
    }
  va_end(ap);
  return (EXIT_SUCCESS);
}

