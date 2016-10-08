/*
** mini.h for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 09:26:37 2014 ugo belfiore
** Last update Sat Nov 22 22:10:34 2014 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#define COLOR_YELLOW_1 0xFFFF00
#define COLOR_YELLOW_2 0xFFCC00
#define COLOR_YELLOW_3 0xFF9900
#define COLOR_YELLOW_4 0xFF6633
#define COLOR_YELLOW_5 0xFF0000
#define COLOR_BLUE 0x000099
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define KEY_ENTER 65293
#define KEY_ESC 65307
#define KEY_REFRESH 114
#define KEY_KILL 107
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_DOWN 65364

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*bigData;
  int		x;
  int		y;
  int		x_max;
  int		y_max;
  int		colo;
  int		bpp;
  int		sizeline;
  int		endian;
  char		**tab;
  int		x_file;
  int		y_file;
  int		para;
  int		par2;
}               t_data;

typedef struct	s_affd
{
  int		x;
  int		y;
  int		mx;
  int		my;
  int		i;
  int		cte;
  int		testxy;
  int		testx;
  int		testy;
  int		mod;
}		t_affd;

typedef struct	s_line
{
  int		dx;
  int		dy;
  int		e;
  int		x1;
  int		x2;
  int		y1;
  int		y2;
}		t_line;

typedef struct	s_file
{
  char		buff[40960];
  int		word;
  char		**tab;
  int		x_file;
  int		y_file;
}		t_file;

int     aff_line_verti(t_data d, t_line a);
int     aff_line_horiz(t_data d, t_line a);
int     aff_lineBIS(t_data d, t_line a);
int     aff_lineBIS_1(t_data d, t_line a);
int     aff_lineBIS_2(t_data d, t_line a);
int     aff_lineBIS_3(t_data d, t_line a);
int     aff_lineBIS_4(t_data d, t_line a);
int     aff_pix_img(t_data d, int x, int y);
int     aff_add_1(t_data d, t_line a);
int     aff_add_2(t_data d, t_line a);
int     aff_add_3(t_data d, t_line a);
int     aff_add_4(t_data d, t_line a);
int     aff_line(t_data data, int x1, int y1, int x2, int y2);
int     cute_word(char *av);
int     cute_char(char *av, int *i);
t_file  cute_file(t_file f);
t_file  my_str_to_wordtab_fdf(t_file f);
void    my_show_wordtab(char **tab);
int     aff_win(char *name, int x_max, int y_max, t_file f);
int     aff_line(t_data data, int x1, int y1, int x2, int y2);
int     aff_win_img(t_data d);
int     aff_win_file(t_data d);
void	aff_win_file_2(t_data d, t_affd a);
t_data	change_colo(t_data d, t_affd a);
char	*get_next_line(const int fd);

#endif
