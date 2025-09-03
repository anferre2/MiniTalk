/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:28:53 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/12 15:26:37 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	append_char(char **str, char c)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(*str);
	i = 0;
	new_str = malloc(len + 2);
	if (!new_str)
		return ;
	while (i < len)
	{
		new_str[i] = (*str)[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	free(*str);
	*str = new_str;
}

void	sig_handler(int sig)
{
	static int	bitcount;
	static char	c;
	static char	*message;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1);
	bitcount++;
	if (bitcount == 8)
	{
		if (c == '\0')
		{
			write(1, message, ft_strlen(message));
			write(1, "\n", 1);
			free(message);
			message = NULL;
		}
		else
			append_char(&message, c);
		bitcount = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid_val;
	char				*pid_str;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid_val = getpid();
	pid_str = ft_itoa(pid_val);
	ft_putstr("Server PID= ");
	if (pid_str)
	{
		ft_putstr(pid_str);
		free(pid_str);
	}
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
