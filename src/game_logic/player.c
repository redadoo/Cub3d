/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:07 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/03 18:28:05 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	check_matrix(t_game *game, int x, int y)
{
	if (game->map.matrix[y][x])
		return (1);
	return (0);
}

static void	init_player_vector(t_player *player, char ch, double x, double y)
{
	set_vector3(&player->pos, x, 0, y);
	if (ch == 'N')
		set_vector2(&player->dir, 0, 1);
	else if (ch == 'S')
		set_vector2(&player->dir, 0, -1);
	else if (ch == 'E')
		set_vector2(&player->dir, 1, 0);
	else if (ch == 'W')
		set_vector2(&player->dir, -1, 0);
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
				init_player_vector(player, map[i.y][i.x], i.x + 1, i.y + 1);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
}

void	move_player(t_game *game, int dir)
{
	double	movement_speed;
	double	rotation_speed;

	game->player.movement_speed = 0.2F;
	game->player.rotation_speed = 0.2F;
	movement_speed = game->player.movement_speed;
	rotation_speed = game->player.rotation_speed;
}
