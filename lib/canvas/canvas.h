/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:53:37 by nnuno-ca          #+#    #+#             */
/*   Updated: 2024/01/31 17:09:29 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

#include "../../mlx_linux/mlx.h"

# include <stddef.h>
# include <stdint.h>

// WINDOW DIMENSIONS

# define WIN_WIDTH 1200
# define WIN_HEIGHT 600

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/* img represents a canvas to which we'll draw 
	to then put that canvas(img) to the window */

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

static inline t_img	init_img(void)
{
	return ((t_img)
		{
			.ptr = NULL,
			.addr = NULL,
			.bpp = 0,
			.line_len = 0,
			.endian = 0
		});
}

static inline t_img	new_img(void *mlx_ptr)
{
	t_img	new_img;

	new_img.ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.ptr, &new_img.bpp,
			&new_img.line_len, &new_img.endian);
	return (new_img);
}

static inline void	put_pixel_in_canvas(t_img *img, int x, int y,
	uint32_t color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(uint32_t *)dst = color;
}

static inline int	extract_pixel_from_image(t_img *img,
		int point_x, int point_y)
{
	return (*(uint32_t *)(img->addr
		+ (point_y * img->line_len) + (point_x * img->bpp / 8)));
}

#endif // IMG_H