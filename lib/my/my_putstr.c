/*
** my_putstr.c for my_putstr in /home/msa_m/rendu/Piscine_C_J04
** 
** Made by matheo msa
** Login   <msa_m@epitech.net>
** 
** Started on  Thu Oct  2 17:47:57 2014 matheo msa
** Last update Thu Nov  6 19:35:55 2014 ugo belfiore
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
