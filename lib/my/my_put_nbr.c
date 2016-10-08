/*
** my_put_nbr.c for my_put_nbr in /home/msa_m/rendu/Piscine_C_J07/lib
** 
** Made by matheo msa
** Login   <msa_m@epitech.net>
** 
** Started on  Tue Oct  7 10:21:41 2014 matheo msa
** Last update Thu Nov  6 14:46:56 2014 ugo belfiore
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return (0);
}
