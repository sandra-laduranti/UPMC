/*
** my_init_list.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:58:17 2012 antoine kepeklian
** Last update Wed Jan 18 17:58:20 2012 antoine kepeklian
*/

#include "lib.h"

void	init_list(t_init *list)
{
  list->size = 0;
  list->head = list->tail;
  list->tail = list->head;
}
