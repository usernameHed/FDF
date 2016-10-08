/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Fri Nov 14 13:34:41 2014 ugo belfiore
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/mini.h"

int	cute_word(char *av)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  while (av[i])
    {
      if ((av[i] >= '0' && av[i] <= '9') 
	  || (av[i] >= 'A' && av[i] <= 'Z')
          || (av[i] >= 'a' && av[i] <= 'z'))
        {
          cpt++;
          while (av[i] && ((av[i] >= '0' && av[i] <= '9')
                          || (av[i] >= 'A' && av[i] <= 'Z')
                          || (av[i] >= 'a' && av[i] <= 'z')))
            i++;
        }
      i++;
    }
  return (cpt);
}

t_file	cute_file(t_file f)
{
  int   i;

  i = 0;
  f.x_file = 0;
  f.y_file = 0;
  while (f.buff[i])
    {
      if ((f.buff[i] >= '0' && f.buff[i] <= '9')
          || (f.buff[i] >= 'A' && f.buff[i] <= 'Z')
          || (f.buff[i] >= 'a' && f.buff[i] <= 'z'))
        {
	  if (f.y_file == 0)
	    f.x_file++;
          while (f.buff[i] && ((f.buff[i] >= '0' && f.buff[i] <= '9')
			       || (f.buff[i] >= 'A' && f.buff[i] <= 'Z')
			       || (f.buff[i] >= 'a' && f.buff[i] <= 'z')))
		 i++;
        }
      if (f.buff[i] == '\n')
	f.y_file++;
      i++;
    }
  return (f);
}

int	cute_char(char *av, int *i)
{
  int	cpt;

  cpt = 0;
  while (av[*i] && ((av[*i] >= '0' && av[*i] <= '9')
		   || (av[*i] >= 'A' && av[*i] <= 'Z')
		   || (av[*i] >= 'a' && av[*i] <= 'z')))
    {
      cpt++;
      *i = *i + 1;
    }
  return (cpt);
}

t_file	my_str_to_wordtab_fdf(t_file f)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  f = cute_file(f);
  f.word = cute_word(f.buff);
  f.tab = (char **)malloc(sizeof(char *) * f.word);
  while (f.buff[i] && f.word > 0)
    {
      if ((f.buff[i] >= '0' && f.buff[i] <= '9') 
	  || (f.buff[i] >= 'A' && f.buff[i] <= 'Z')
          || (f.buff[i] >= 'a' && f.buff[i] <= 'z'))
        {
          f.tab[a] = my_strdup(f.buff + i);
          f.tab[a][cute_char(f.buff, &i)] = '\0';
          a++;
          f.word--;
        }
      i++;
    }
  f.tab[cute_word(my_strdup(f.buff))] = NULL;
  return (f);
}
