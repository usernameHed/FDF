/*
** aff_pix_img.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 31 16:36:46 2014 ugo belfiore
** Last update Sat Nov 22 18:03:48 2014 ugo belfiore
*/

#include "./minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

int	aff_pix_img(t_data d, int x, int y)
{
  int	i;

  if (x < 0 || x > d.x_max)
    return (0);
  if (y < 0 || y > d.y_max)
    return (0);
  if (d.endian == 0)
    {
      i = (d.sizeline * y) + (x * (d.bpp / 8));
      d.bigData[i] = mlx_get_color_value(d.mlx_ptr, d.colo);
      d.bigData[i + 1] = mlx_get_color_value(d.mlx_ptr, d.colo >> 8);
      d.bigData[i + 2] = mlx_get_color_value(d.mlx_ptr, d.colo >> 16);
    }
  else
    {
      i = (d.sizeline * y) + (x * (d.bpp / 8));
      d.bigData[i] = mlx_get_color_value(d.mlx_ptr, d.colo >> 16);
      d.bigData[i + 1] = mlx_get_color_value(d.mlx_ptr, d.colo >> 8);
      d.bigData[i + 2] = mlx_get_color_value(d.mlx_ptr, d.colo);
    }
  return (0);
}

int	aff_win_img(t_data d)
{
  int	i;

  i = 0;
  while (i != d.sizeline * d.y_max)
    {
      d.bigData[i++] = 0;
      d.bigData[i++] = 0;
      d.bigData[i++] = 0;
      d.bigData[i++] = 0;
    }
  return (0);
}

t_data	change_colo(t_data d, t_affd a)
{
  if (a.mod == 1)
    {
      d.colo = (a.testxy > 0 || a.testx > 0) ? COLOR_YELLOW_1 : d.colo;
      d.colo = (a.testxy > 20 || a.testx > 20) ? COLOR_YELLOW_2 : d.colo;
      d.colo = (a.testxy > 40 || a.testx > 40) ? COLOR_YELLOW_3 : d.colo;
      d.colo = (a.testxy > 60 || a.testx > 60) ? COLOR_YELLOW_4 : d.colo;
      d.colo = (a.testxy > 80 || a.testx > 80) ? COLOR_YELLOW_5 : d.colo;
    }
  else
    {
      d.colo = (a.testxy > 0 || a.testy > 0) ? COLOR_YELLOW_1 : d.colo;
      d.colo = (a.testxy > 20 || a.testy > 20) ? COLOR_YELLOW_2 : d.colo;
      d.colo = (a.testxy > 40 || a.testy > 40) ? COLOR_YELLOW_3 : d.colo;
      d.colo = (a.testxy > 60 || a.testy > 60) ? COLOR_YELLOW_4 : d.colo;
      d.colo = (a.testxy > 80 || a.testy > 80) ? COLOR_YELLOW_5 : d.colo;
    }
  return (d);
}

void	aff_win_file_2(t_data d, t_affd a)
{
  a.mod = 1;
  d = change_colo(d, a);
  if (a.x + 1 < d.x_file)
    {
      aff_line(d, (a.x * a.mx + a.y * d.para) + (d.x_max / 20),
	       ((a.y * a.my - (a.y + 1) * d.par2) + (d.y_max / 20))
	       + (my_getnbr(d.tab[a.i]) * (a.cte)),
	       ((a.x * a.mx + a.y * d.para) + (d.x_max / 20)) + a.mx,
	       ((a.y * a.my - (a.y + 1) * d.par2) + (d.y_max / 20))
	       + (my_getnbr(d.tab[a.i + 1]) * (a.cte)));
    }
  a.mod = 2;
  d.colo = COLOR_BLUE;
  d = change_colo(d, a);
  if (a.y + 1 < d.y_file)
    {
      aff_line(d, (a.x * a.mx + a.y * d.para) + (d.x_max / 20),
	       (a.y * a.my - (a.y + 1) * d.par2) + (d.y_max / 20)
	       + (my_getnbr(d.tab[a.i]) * (a.cte)),
	       (a.x * a.mx + a.y * d.para) + (d.x_max / 20) + d.para,
	       (((a.y * a.my - (a.y + 2) * d.par2) + (d.y_max / 20))
		+ a.my)
	       + (my_getnbr(d.tab[a.i + d.x_file]) * (a.cte)));
    }
}

int		aff_win_file(t_data d)
{
  t_affd	a;

  a.mx = (d.x_max - ((d.x_max / 20) * 2)) / (d.x_file + d.para);
  a.my = (d.y_max - ((d.y_max / 20) * 2)) / (d.y_file);
  a.i = 0;
  a.x = 0;
  a.y = 0;
  a.cte = 1;
  while (a.y < d.y_file)
    {
      while (a.x < d.x_file)
	{
	  d.colo = COLOR_BLUE;
	  a.testxy = my_getnbr(d.tab[a.i]);
	  a.testx = my_getnbr(d.tab[a.i + 1]);
	  if (a.y + 1 != d.y_file)
	    a.testy = my_getnbr(d.tab[a.i + d.x_file]);
	  aff_win_file_2(d, a);
	  a.x++;
	  a.i++;
	}
      a.x = 0;
      a.y++;
    }
  return (0);
}
