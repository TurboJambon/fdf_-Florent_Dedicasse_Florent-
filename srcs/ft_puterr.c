/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:23:05 by niragne           #+#    #+#             */
/*   Updated: 2017/06/17 14:47:32 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_puterr(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

void	ft_puterr_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}
