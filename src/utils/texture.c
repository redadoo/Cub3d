/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:56:57 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/10 08:14:25 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	init_texture(t_sprite *texture, t_game *game)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, texture->path,
			&texture->img_width, &texture->img_height);
	if (texture->img == NULL)
		error("error on init_texture, mlx_xpm_file_to_image() failed", game);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	texture->text_value = (int *)mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->addr)
		error("error on init_texture, mlx_get_data_addr() failed", game);
}

void	load_texture(t_game *game)
{
	init_texture(&game->assets.n_wall, game);
	init_texture(&game->assets.e_wall, game);
	init_texture(&game->assets.s_wall, game);
	init_texture(&game->assets.w_wall, game);
}
