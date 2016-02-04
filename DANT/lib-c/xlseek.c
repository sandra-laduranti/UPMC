/*
** xlseek.c for Library in /home/harat_k//rendu/projets/progElem/corewar_SVN/lib/src
** 
** Made by karim harat
** Login   <harat_k@epitech.net>
** 
** Started on  Fri Jan 27 13:52:39 2012 karim harat
** Last update Fri Jan 27 13:56:55 2012 karim harat
*/

#include	"lib.h"

int		xlseek(int fd, off_t offset, int whence)
{
  int		ret;

  ret = lseek(fd, offset, whence);
  if (ret == -1)
    {
      my_fprintf(MY_STDERR, "lseek error\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
