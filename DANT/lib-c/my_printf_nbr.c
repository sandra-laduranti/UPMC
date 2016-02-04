/*
** my_printf_nbr.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:45 2012 antoine kepeklian
** Last update Wed Jan 18 17:57:47 2012 antoine kepeklian
*/

#include "lib.h"

void	my_printf_nbr(va_list *ap)
{
  my_putnbr(va_arg(*ap, int));
}

void	my_printf_nbr_uns(va_list *ap)
{
  my_putnbr_uns(va_arg(*ap, unsigned int));
}

void	my_printf_hex_min(va_list *ap)
{
  my_putnbr_base(va_arg(*ap, int), HEXA_MIN);
}

void	my_printf_hex_maj(va_list *ap)
{
  my_putnbr_base(va_arg(*ap, int), HEXA_MAJ);
}

void	my_printf_bin(va_list *ap)
{
  my_putnbr_base(va_arg(*ap, int), BIN);
}
