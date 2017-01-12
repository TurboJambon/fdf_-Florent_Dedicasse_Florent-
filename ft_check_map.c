/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:22:33 by niragne           #+#    #+#             */
/*   Updated: 2017/01/12 20:41:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_map(int fd)
{
	char	*str;
	char	**arr;

	str = fd_to_str(fd); 
			printf("bite\n");

	arr = ft_strsplit(str, '\n');
	ft_putarr(arr);
	return (1);
}