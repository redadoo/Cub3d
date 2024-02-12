/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:16:06 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 15:02:00 by edoardo          ###   ########.fr       */
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

t_sprite	new_img(void *mlx_ptr)
{
	t_sprite	new_img;

	new_img.img = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bpp,
			&new_img.line_len, &new_img.endian);
	return (new_img);
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
