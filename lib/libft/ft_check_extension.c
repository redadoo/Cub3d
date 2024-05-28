/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:52:24 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 14:00:09 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	check_extension(char *file, char *extension)
{
	int		count;
	char	*tmp;

	count = ft_strlen(extension);
	tmp = (char *)ft_strstr(file, extension);
	if (tmp == NULL)
		return (false);
	while (count)
	{
		tmp++;
		count--;
	}
	if ((int)*tmp != 0)
		return (false);
	return (true);
}
