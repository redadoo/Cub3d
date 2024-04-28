/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_string_alpha.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:48:29 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/28 16:50:07 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool ft_is_string_alpha(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (!ft_isalpha(str[i]))
            return (false);
        i++;
    }
    return (true);
}