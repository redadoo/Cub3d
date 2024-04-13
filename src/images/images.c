/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:16:06 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/13 14:03:30 by edoardo          ###   ########.fr       */
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

void	put_pixel(t_sprite *img, int x, int y, uint32_t color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	if (img->side == 1)
		color = (color >> 1) & 8355711;
	*(uint32_t *)dst = color;
}

int	extract_pixel_from_image(t_sprite *img, int x, int y)
{
	return (*(uint32_t *)(img->addr + (y * img->line_len) + (x * img->bpp
			/ 8)));
}
