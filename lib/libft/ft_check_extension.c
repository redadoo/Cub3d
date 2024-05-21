/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:52:24 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/21 18:33:22 by edoardo          ###   ########.fr       */
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
	count = open(file, O_RDONLY);
	if (count == -1)
		return (false);
	close(count);
	return (true);
}
