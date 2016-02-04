/*
** my_fprintf_nbr.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:41 2012 antoine kepeklian
** Last update Fri Jan 20 18:07:42 2012 antoine kepeklian
*/

#include "lib.h"

void	my_fprintf_nbr(const int fd, va_list *ap)
{
  my_fputnbr(fd, va_arg(*ap, int));
}

void	my_fprintf_nbr_uns(const int fd, va_list *ap)
{
  my_fputnbr_uns(fd, va_arg(*ap, unsigned int));
}

void	my_fprintf_hex_min(const int fd, va_list *ap)
{
  my_fputnbr_base(fd, va_arg(*ap, int), HEXA_MIN);
}

void	my_fprintf_hex_maj(const int fd, va_list *ap)
{
  my_fputnbr_base(fd, va_arg(*ap, int), HEXA_MAJ);
}

void	my_fprintf_bin(const int fd, va_list *ap)
{
  my_fputnbr_base(fd, va_arg(*ap, int), BIN);
}
