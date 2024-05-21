/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:56:57 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/21 19:31:28 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	load_sprites(t_game *game)
{
	init_sprite(&game->assets.n_wall, game);
	init_sprite(&game->assets.e_wall, game);
	init_sprite(&game->assets.s_wall, game);
	init_sprite(&game->assets.w_wall, game);
}
