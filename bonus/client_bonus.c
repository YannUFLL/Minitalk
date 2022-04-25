/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:47:26 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/25 21:04:17 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handle_sig(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("\nMessage received");
	exit(0);
}

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
	int					pid;
	char				*ptr;
	struct sigaction	sa;

	sa.sa_handler = &ft_handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("2 arguments needed : PID then string");
		return (0);
	}
	ptr = argv[2];
	pid = ft_atoi(argv[1]);
	while (*ptr)
	{
		ft_send(*ptr, pid);
		ptr++;
	}
	ft_send(*ptr, pid);
	while (1)
		;
}
