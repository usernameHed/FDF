/*
** my_show_wordtab.c for  in /home/belfio_u/rendu/EXOTEST/lib/my
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Nov  2 18:00:38 2014 ugo belfiore
** Last update Mon Nov  3 22:29:27 2014 ugo belfiore
*/

#include "./include/my.h"

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar(' ');
      if (tab[i][0] == '\n')
	my_putchar(10);
      i++;
    }
}
