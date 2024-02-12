/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:19:30 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/05 22:26:15 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

/**
 * @brief Creates and initializes a new window using the provided parameters.
 *
 * @param mlx Pointer to the mlx instance.
 * @param width Width of the window.
 * @param height Height of the window.
 * @param name String representing the window title.
 * @return Returns a new t_window structure representing the created window.
 */
t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}
