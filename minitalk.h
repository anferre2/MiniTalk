/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:28:41 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/12 15:26:45 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putstr(const char *s);
char	*ft_itoa(int n);

#endif