/*
** my_printf_mem.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:52 2012 antoine kepeklian
** Last update Wed Jan 18 17:57:53 2012 antoine kepeklian
*/

#include "lib.h"

void	my_printf_mem(va_list *ap)
{
  if (va_arg(*ap, unsigned int) == 0)
    my_putstr("(nil)");
  else
    {
      my_printf("0x");
      my_putnbr_base_uns(va_arg(*ap, unsigned int), HEXA_MIN);
    }
}
