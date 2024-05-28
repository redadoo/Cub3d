/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:09:26 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 13:31:33 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	wall_hit(t_game *game)
{
	game->raycaster.wall_x = 0;
	if (!game->raycaster.side)
		game->raycaster.wall_x = game->player.pos.z
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir.y;
	else
		game->raycaster.wall_x = game->player.pos.x
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir.x;
	game->raycaster.wall_x -= floor((game->raycaster.wall_x));
	game->raycaster.tex.x = (int)(game->raycaster.wall_x
			* TEXTURE_WIDTH);
	if ((game->raycaster.side == 0 && game->raycaster.ray_dir.x > 0)
		|| (game->raycaster.side == 1 && game->raycaster.ray_dir.y < 0))
		game->raycaster.tex.x = TEXTURE_WIDTH - game->raycaster.tex.x - 1;
}
