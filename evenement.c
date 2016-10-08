/*
** evenement.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 15:43:22 2014 ugo belfiore
** Last update Sat Nov 22 17:03:43 2014 ugo belfiore
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

int		manage_key(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  if (keycode == KEY_KILL)
    exit(0);
  if (keycode >= 65361 && keycode <= 65364)
    {
      d->para = (keycode == KEY_RIGHT) ? d->para + 1 : d->para;
      d->para = (keycode == KEY_LEFT) ? d->para - 1 : d->para;
      d->par2 = (keycode == KEY_DOWN) ? d->par2 + 1 : d->par2;
      d->par2 = (keycode == KEY_UP) ? d->par2 - 1 : d->par2;
      d->para = (d->para > 20) ? 20 : d->para;
      d->para = (d->para < 0) ? 0 : d->para;
      d->par2 = (d->par2 > 25) ? 25 : d->par2;
      d->par2 = (d->par2 < 0) ? 0 : d->par2;
      aff_win_img(*d);
      aff_win_file(*d);
      mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
    }
  if (keycode == KEY_ESC)
    exit(0);
  return (0);
}

int		manage_expose(void *param)
{
  t_data	*data;

  data = (t_data *)param;
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
  return (0);
}

int             aff_win(char *name, int x_max, int y_max, t_file f)
{
  t_data        d;

  d.para = 0;
  d.par2 = 0;
  d.tab = f.tab;
  d.x_file = f.x_file;
  d.y_file = f.y_file;
  d.x_max = x_max;
  d.y_max = y_max;
  d.mlx_ptr = mlx_init();
  if (d.mlx_ptr == NULL)
    exit(0);
  d.win_ptr = mlx_new_window(d.mlx_ptr, x_max, y_max, name);
  mlx_do_key_autorepeaton(d.mlx_ptr);
  d.img_ptr = mlx_new_image(d.mlx_ptr, x_max, y_max);
  d.bigData = mlx_get_data_addr(d.img_ptr, &d.bpp, &d.sizeline, &d.endian);
  aff_win_img(d);
  aff_win_file(d);
  mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img_ptr, 0, 0);
  mlx_key_hook(d.win_ptr, &manage_key, (void *)(&d));
  mlx_expose_hook(d.win_ptr, &manage_expose, (void *)(&d));
  mlx_loop(d.mlx_ptr);
  return (0);
}
