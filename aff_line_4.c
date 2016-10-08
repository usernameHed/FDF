/*
** aff_line_3.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Oct 30 15:12:11 2014 ugo belfiore
** Last update Fri Nov 14 13:30:57 2014 ugo belfiore
*/

#include <stdlib.h>
#include "./minilibx/mlx.h"
#include "./include/my.h"
#include "./include/mini.h"

int     aff_lineBIS_3(t_data d, t_line a)
{
  if (-a.dx >= a.dy)
    {
      a.e = a.x2 - a.x1;
      a.dx = a.e * 2;
      a.dy = (a.y2 - a.y1) * 2;
      while (a.x1 != a.x2)
        {
          aff_pix_img(d, a.x1, a.y1);
          a.x1--;
          a.e += a.dy;
          if (a.e >= 0)
            {
              a.y1++;
              a.e += a.dx;
            }
        }
    }
  else
    {
      aff_add_3(d, a);
    }
  return (0);
}

int     aff_add_3(t_data d, t_line a)
{
  a.e = a.y2 - a.y1;
  a.dy = a.e * 2;
  a.dx = (a.x2 - a.x1) * 2;
  while (a.y1 != a.y2)
    {
      aff_pix_img(d, a.x1, a.y1);
      a.y1++;
      a.e += a.dx;
      if (a.e <= 0)
        {
          a.x1--;
          a.e += a.dy;
        }
    }
  return (0);
}

int     aff_lineBIS_4(t_data d, t_line a)
{
  if (a.dx <= a.dy)
    {
      a.e = a.x2 - a.x1;
      a.dx = a.e * 2;
      a.dy = (a.y2 - a.y1) * 2;
      while (a.x1 != a.x2)
        {
          aff_pix_img(d, a.x1, a.y1);
          a.x1--;
          a.e -= a.dy;
          if (a.e >= 0)
            {
              a.y1--;
              a.e += a.dx;
            }
        }
    }
  else
    {
      aff_add_4(d, a);
    }
  return (0);
}

int     aff_add_4(t_data d, t_line a)
{
  a.e = a.y2 - a.y1;
  a.dy = a.e * 2;
  a.dx = (a.x2 - a.x1) * 2;
  while (a.y1 != a.y2)
    {
      aff_pix_img(d, a.x1, a.y1);
      a.y1--;
      a.e -= a.dx;
      if (a.e >= 0)
        {
          a.x1--;
          a.e += a.dy;
        }
    }
  return (0);
}
