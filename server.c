/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:17:43 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/25 17:05:05 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <printf.h>
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

char	*ft_strjoin_v2(char *s1, unsigned char c)
{
	char	*ptr;
	size_t	size;
	int		i;

	if (s1 != NULL)
		size = ft_strlen(s1) + 1;
	else
		size = 1;
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	ptr[i] = c;
	ptr[i + 1] = 0;
	return (ptr);
}

char	*ft_printffree(char *ptr)
{
	ft_printf("\n%s", ptr);
	free(ptr);
	ptr = NULL;
	return (ptr);
}

void	ft_handle_sig(int sig)
{
	static unsigned char	c;
	static int				i;
	static unsigned char	mask;
	static char				*ptr;

	if (mask == 0)
		mask = 128;
	if (sig == SIGUSR2)
		c |= mask;
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == 0)
			ptr = ft_printffree(ptr);
		else
			ptr = ft_strjoin_v2(ptr, c);
		c = 0;
	}
	else
		c >>= 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &ft_handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("\nPID : %d", pid);
	while (1)
		;
}
