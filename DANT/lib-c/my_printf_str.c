/*
** my_printf_str.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:36 2012 antoine kepeklian
** Last update Fri Jan 20 18:04:03 2012 antoine kepeklian
*/

#include "lib.h"

void		my_printf_str(va_list *ap)
{
  char		*str;

  str = va_arg(*ap, char *);
  if (str == NULL)
    my_putstr("(null)");
  else
    my_putstr(str);
}

void	my_printf_chr(va_list *ap)
{
  my_putchar(va_arg(*ap, int));
}

void	my_printf_pct()
{
  my_putchar('%');
}

void	my_printf_err(va_list *ap)
{
  if (!*ap)
    my_printf("Failure");
  else
    my_printf("Success");
}
