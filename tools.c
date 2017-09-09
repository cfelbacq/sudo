/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:44:37 by cfelbacq          #+#    #+#             */
/*   Updated: 2017/09/09 14:06:35 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudo.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_numeric(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int		is_dot(char c)
{
	if (c == '.')
		return (1);
	return (0);
}
