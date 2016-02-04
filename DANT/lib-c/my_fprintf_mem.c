/*
** my_fprintf_mem.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:45 2012 antoine kepeklian
** Last update Fri Jan 20 18:07:47 2012 antoine kepeklian
*/

#include "lib.h"

void	my_fprintf_mem(const int fd, va_list *ap)
{
  if (va_arg(*ap, unsigned int) == 0)
    my_fputstr(fd, "(nil)");
  else
    {
      my_fprintf(fd, "0x");
      my_fputnbr_base_uns(fd, va_arg(*ap, unsigned int), HEXA_MIN);
    }
}
