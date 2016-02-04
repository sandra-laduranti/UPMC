/*
** my_rm_list.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:56:36 2012 antoine kepeklian
** Last update Fri Jan 20 19:19:55 2012 antoine kepeklian
*/

#include "lib.h"

t_list		*rm_element(t_init *list, int pos)
{
  t_list	*del;

  if (list->size == 0)
    return (EXIT_SUCCESS);
  if (pos == 1)
    del = rm_first_element(list);
  else if (pos > 1 && pos < list->size)
    del = rm_pos_element(list, pos);
  else if (pos == list->size)
    del = rm_last_element(list);
  else
    {
      my_fprintf(MY_STDERR, "This element doesn't exist!\n");
      return (NULL);
    }
  xfree(del);
  list->size--;
  return (EXIT_SUCCESS);
}

t_list		*rm_first_element(t_init *list)
{
  t_list	*del;

  del = list->head;
  list->head = list->head->next;
  if (list->head == list->tail)
    list->tail = list->head;
  else
    list->head->prev = list->tail;
  return (del);
}

t_list		*rm_pos_element(t_init *list, int pos)
{
  int		i;
  t_list	*del;
  t_list	*current;

  i = 1;
  current = list->head;
  while (i < pos)
    {
      current = current->next;
      i = i + 1;
    }
  del = current;
  current->prev->next = current->next;
  current->next->prev = current->prev;
  return (del);
}
t_list		*rm_last_element(t_init *list)
{
  t_list	*del;

  del = list->tail;
  list->tail->prev->next = list->head;
  list->tail = list->tail->prev;
  return (del);
}
