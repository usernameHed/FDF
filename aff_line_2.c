/*
** aff_line_2.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Oct 30 14:15:05 2014 ugo belfiore
** Last update Sat Nov 22 16:54:52 2014 ugo belfiore
*/

#include <stdlib.h>
#include "./minilibx/mlx.h"
#include "./include/my.h"
#include "./include/mini.h"

int	aff_line_verti(t_data d, t_line a)
{
  if (a.dy != 0)
    {
      if (a.dy > 0)
	{
	  while (a.y1 != a.y2)
	    {
	      aff_pix_img(d, a.x1, a.y1);
	      a.y1++;
	    }
	}
      else
	{
	  while (a.y1 != a.y2)
	    {
	      aff_pix_img(d, a.x1, a.y1);
	      a.y1--;
	    }
	}
    }
  return (0);
}

int	aff_line_horiz(t_data d, t_line a)
{
  if (a.dx > 0)
    {
      while (a.x1 != a.x2)
	{
	  aff_pix_img(d, a.x1, a.y1);
	  a.x1++;
	}
    }
  else
    {
      while (a.x1 != a.x2)
	{
	  aff_pix_img(d, a.x1, a.y1);
	  a.x1--;
	}
    }
  return (0);
}

int	aff_lineBIS(t_data d, t_line a)
{
  if (a.dx > 0)
    {
      if (a.dy != 0)
	{
	  if (a.dy > 0)
	    aff_lineBIS_1(d, a);
	  else
	    aff_lineBIS_2(d, a);
	}
    }
  else
    {
      if (a.dy != 0)
	{
	  if (a.dy > 0)
	    aff_lineBIS_3(d, a);
	  else
	    aff_lineBIS_4(d, a);
	}
    }
  return (0);
}
