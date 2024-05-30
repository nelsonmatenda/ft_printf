/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:41:34 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/30 11:45:13 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> // TODO: apagar no final.

typedef struct s_format
{
    int minus[2];
    int plus;
    int dot[2];
    int zero[2];
    int space;
    int hash;
    int width;
    char    *specifier;
}   t_format;

typedef struct s_data
{
    const char *s;
    va_list ap;    
    int nbr_char_printed;
    t_format    f;
    char    *place_holder;
}   t_data;


long	ft_abs(long n);
int	ft_putaddress(void *format);
void	ft_putbase_fd(int nbr, const char *base, int fd);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long n, char format);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned long n);
int	ft_putstr(char const *s);
void    ft_init_data (t_data d, const char *s);


#endif