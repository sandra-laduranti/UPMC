/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/harat_k//rendu/projets/systemUnix/mysh/mysh1.1/lib
**
** Made by karim harat
** Login   <harat_k@epitech.net>
**
** Started on  Mon Jan 16 15:37:44 2012 karim harat
** Last update Tue Jan 31 14:15:03 2012 antoine kepeklian
*/

#include	"lib.h"

int		 cpt_word(char *str, char c)
{
  int		i;
  int		cpt;
  char		car_prec;

  i = 0;
  cpt = 0;
  car_prec = c;
  while (str[i] != '\0')
    {
      if ((car_prec == c) && (str[i] != c))
          cpt++;
      car_prec = str[i];
      i++;
    }
  return (cpt);
}

char		*copy(char *str, char *dest, int debut, char c)
{
  int		i;

  i = 0;
  while ((str[debut] != c) && (str[debut] != '\0'))
    {
      dest[i] = str[debut];
      debut++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int		cpt_letter(char *str, int debut, char c)
{
  int		i;

  i = 0;
  while ((str[debut] != c) && (str[debut] != '\0'))
    {
      debut++;
      i++;
    }
  return (i);
}

int		check_str(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] == c)
    i++;
  if (str[i])
    return (0);
  return (-1);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		i;
  int		j;
  char		car_prec;
  char		**tab;

  i = 0;
  j = 0;
  if (check_str(str, c) != 0)
    return (NULL);
  tab = malloc((cpt_word(str, c) + 1) * sizeof(*tab));
  car_prec = c;
  while (str[i] != '\0')
    {
      if ((car_prec == c) && (str[i] != c))
        {
          tab[j] = malloc((cpt_letter(str, i, c) + 1) * sizeof(**tab));
          copy(str, tab[j], i, c);
          j++;
        }
      car_prec = str[i];
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
