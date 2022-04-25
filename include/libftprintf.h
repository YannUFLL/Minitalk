/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:23:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/19 20:38:11 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr_base2(int nbr, char *base, int count);
int	ft_putadd_base2(unsigned long long int nbr, int count);
int	ft_select_f(long long int arg, char c, int count);
int	ft_putnbr2(int n, int count);
int	ft_putnbr_unsigned2(unsigned int n, int count);
int	ft_putstr2(char *str, int count);
int	ft_putchar2(char c, int count);
int	ft_printf(const char *str, ...);
int	ft_putnbr_r2(int n, int count);

#endif
