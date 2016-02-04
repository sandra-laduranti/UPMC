/*
** my_fprintf_str.c for library in /home/kepekl_b//Documents/lib/my2
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Fri Jan 20 18:07:36 2012 antoine kepeklian
** Last update Fri Jan 20 18:07:37 2012 antoine kepeklian
*/

#include "lib.h"

void		my_fprintf_str(const int fd, va_list *ap)
{
  char		*str;

  str = va_arg(*ap, char *);
  if (str == NULL)
    my_fputstr(fd, "(null)");
  else
    my_fputstr(fd, str);
}

void		my_fprintf_chr(const int fd, va_list *ap)
{
  my_fputchar(fd, va_arg(*ap, int));
}

void		my_fprintf_pct(const int fd, va_list *ap)
{
  va_arg(*ap, int);
  my_fputchar(fd, '%');
}

void		my_fprintf_err(const int fd, va_list *ap)
{
  if (!*ap)
    my_fprintf(fd, "Failure");
  else
    my_fprintf(fd, "Success");
}
