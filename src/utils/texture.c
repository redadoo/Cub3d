/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:56:57 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/21 18:49:55 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	load_texture(t_game *game)
{
	init_texture(&game->assets.n_wall, game);
	init_texture(&game->assets.e_wall, game);
	init_texture(&game->assets.s_wall, game);
	init_texture(&game->assets.w_wall, game);
}