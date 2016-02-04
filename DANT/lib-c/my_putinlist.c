/*
** my_putinlist.c for library in /home/kepekl_b//Documents/lib/my2/lib/src
**
** Made by antoine kepeklian
** Login   <kepekl_b@epitech.net>
**
** Started on  Wed Jan 18 17:57:26 2012 antoine kepeklian
** Last update Fri Jan 20 19:20:04 2012 antoine kepeklian
*/

#include "lib.h"

int		my_putinlist_head(t_init *list, char *str)
{
  t_list	*element;

  if (!list)
    {
      my_fprintf(MY_STDERR, "this list doesn't exist\n");
      return (EXIT_SUCCESS);
    }
  element = xmalloc(sizeof(*element));
  element->str = str;
  element->prev = list->tail;
  element->next = list->head;
  if (list->tail != list->head)
    list->tail->next = element;
  else
    list->head = element;
  list->tail = element;
  list->size++;
  return (EXIT_SUCCESS);
}

int		my_putinlist_tail(t_init *list, char *str)
{
  t_list	*element;

  if (!list)
    {
      my_fprintf(MY_STDERR, "this list doesn't exist\n");
      return (EXIT_SUCCESS);
    }
  element = xmalloc(sizeof(*element));
  element->str = str;
  element->prev = list->head;
  element->next = list->tail;
  if (list->head != list->tail)
    list->head->prev = element;
  else
    list->tail = element;
  list->head = element;
  list->size++;
  return (EXIT_SUCCESS);
}
