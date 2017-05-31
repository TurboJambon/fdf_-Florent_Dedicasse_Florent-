/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:59:05 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/31 13:45:43 by dchirol          ###   ########.fr       */
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
