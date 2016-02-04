/*
** xcreate.c for library in /home/kepekl_b//Documents/Projets/16_Korewar/rendu_grp
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Mon Jan 23 14:28:56 2012 antoine kepeklian
** Last update Tue Jan 24 10:51:48 2012 antoine kepeklian
*/

#include "lib.h"

int	xcreate(const char *pathname, int flag)
{
  int	fd;

  fd = open(pathname, O_CREAT, flag);
  xclose(fd);
  fd = open(pathname, O_TRUNC, flag);
  if (fd == -1)
    {
      my_fprintf(MY_STDERR, "Cannot Create file : %s", pathname);
      return (EXIT_FAILURE);
    }
  xclose(fd);
  fd = xopen(pathname, O_RDWR);
  return (fd);
}
