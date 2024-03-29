/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:47:26 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/25 21:37:35 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void affichebin(unsigned n)
{
    unsigned bit = 0;
    unsigned mask = 128;
    printf("\n");
    for (int i = 7 ; i > -1 ; i--)
    {
        bit = (n & mask) >> i;
        printf("%d", bit);
        mask >>= 1;
    }
}
*/
void	ft_send(char c, int pid)
{
	char	mask;
	int		i;

	i = 0;
	mask = 1;
	while (i < 8)
	{
		if (mask & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(25);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*ptr;	

	if (argc == 3)
	{
		ptr = argv[2];
		pid = ft_atoi(argv[1]);
		while (*ptr)
		{
			ft_send(*ptr, pid);
			ptr++;
		}
		ft_send(*ptr, pid);
	}
	else
		ft_printf("2 arguments needed : PID then string");
	return (0);
}
