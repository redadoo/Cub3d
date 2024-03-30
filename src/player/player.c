/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:07 by edoardo           #+#    #+#             */
/*   Updated: 2024/03/30 15:12:18 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	check_next_pos(t_game *game, int x, int y)
{
	if (game->map[y][x] && game->map[y][x] != '1')
	{
		return (1);
	}	
	return (0);
}

static void	init_player_vector(t_player *player, char ch, double x, double y)
{
	set_vector3(&player->pos, x + 0.5, 0, y + 0.5);
	if (ch == 'N')
		set_vector2(&player->dir, 0, 1);
	else if (ch == 'S')
		set_vector2(&player->dir, 0, -1);
	else if (ch == 'E')
		set_vector2(&player->dir, -1, 0);
	else if (ch == 'W')
		set_vector2(&player->dir, 1, 0);
}

void	init_player(t_player *player, char **map)
{
	char			ch;
	t_vector2_int	i;

	i.x = 0;
	i.y = 0;
	while (map[i.y])
	{
		while (map[i.y][i.x])
		{
			ch = map[i.y][i.x];
			if (ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E')
				init_player_vector(player, map[i.y][i.x], i.x, i.y);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
}
