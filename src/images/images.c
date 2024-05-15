/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:16:06 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/30 16:57:02 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

t_sprite	init_sprite(void)
{
	t_sprite	new_sprite;

	new_sprite.img = NULL;
	new_sprite.addr = NULL;
	new_sprite.bpp = 0;
	new_sprite.line_len = 0;
	new_sprite.side = 0;
	new_sprite.path = NULL;
	return (new_sprite);
}

t_sprite	init_img(void *mlx_ptr, int width, int height)
{
	t_sprite	img;

	img.img = mlx_new_image(mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_len, &img.endian);
	return (img);
}


