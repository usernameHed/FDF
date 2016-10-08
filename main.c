/*
** main.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Oct 27 15:02:42 2014 ugo belfiore
** Last update Sat Nov 22 22:10:45 2014 ugo belfiore
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./minilibx/mlx.h"
#include "./include/mini.h"

int		main(int ac, char **av)
{
  int		fd;
  t_file	f;
  int		rett;

  if (ac != 2)
    return (0);
  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    {
      my_putstr("ERROR: can't open ");
      my_putstr(av[1]);
      my_putchar(10);
    }
  else
    {
      rett = read(fd, f.buff, 40960);
      if (rett == 0 || rett > 40959)
      	exit(0);
      f = my_str_to_wordtab_fdf(f);
      aff_win("FDF - CUTENESS - FDF", 1400, 900, f);
    }
  close(fd);
  return (0);
}
