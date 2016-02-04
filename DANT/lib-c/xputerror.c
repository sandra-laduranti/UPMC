/*
** xputerror.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:54:54 2012 antoine kepeklian
** Last update Wed Jan 18 17:54:56 2012 antoine kepeklian
*/

#include "lib.h"

int	puterror(char *str)
{
  xwrite(2, str, my_strlen(str));
  return (EXIT_SUCCESS);
}
