/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:39:50 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 17:40:08 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	safe_free(void *_ptr)
{
	if (_ptr != NULL)
		free(_ptr);
}

void	safe_mlx_destroy_image(void *mlx_ptr, void *image_ptr)
{
	if (mlx_ptr != NULL && image_ptr != NULL)
	{
		mlx_destroy_image(mlx_ptr, image_ptr);
	}
}

void	safe_mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	if (mlx_ptr != NULL && win_ptr != NULL)
		mlx_destroy_window(mlx_ptr, win_ptr);
}

void	safe_mlx_destroy_display(void *mlx_ptr)
{
	if (mlx_ptr != NULL)
		mlx_destroy_display(mlx_ptr);
}

void	safe_mlx_clear_window(void *mlx_ptr, void *win_ptr)
{
	if (mlx_ptr != NULL && win_ptr != NULL)
		mlx_clear_window(mlx_ptr, win_ptr);
}
