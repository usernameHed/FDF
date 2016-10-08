/*
** my_getnbr.c for  in /home/msa_m/rendu/Piscine_C_J04
** 
** Made by matheo msa
** Login   <msa_m@epitech.net>
** 
** Started on  Sun Oct  5 15:24:22 2014 matheo msa
** Last update Tue Oct 28 12:42:33 2014 matheo msa
*/

int     my_getnbr(char *str)
{
  int   nb;
  int   sign;
  int   i;

  nb = 0;
  sign = 0;
  i = 0;
  if (!str)
    return (0);
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    if (str[i++] == '-')
      ++sign;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    nb = (nb * 10) + (str[i++] - '0');
  return (((sign % 2) == 1) ? ((nb) * (-1)) : (nb));
}
