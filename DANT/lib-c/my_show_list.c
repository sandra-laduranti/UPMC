/*
** my_show_list.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:29 2012 antoine kepeklian
** Last update Fri Jan 20 19:19:48 2012 antoine kepeklian
*/

#include "lib.h"

int		my_show_list(t_init *list)
{
  t_list	*tmp;

  if (!list)
    {
      my_fprintf(MY_STDERR, "Cannot show the list\n");
      return (EXIT_FAILURE);
    }
  tmp = list->head;
  while (tmp->next)
    {
      my_printf(">%s\n",tmp->str);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
