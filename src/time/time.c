/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:28:02 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/21 18:30:36 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int64_t	current_time_millis(void)
{
	struct timeval	time;
	int64_t			s1;
	int64_t			s2;

	gettimeofday(&time, NULL);
	s1 = (int64_t)(time.tv_sec) * 1000;
	s2 = (time.tv_usec / 1000);
	return (s1 + s2);
}

void	manage_time(t_game *game)
{
	game->game_time.old_time = game->game_time.time;
	game->game_time.time = current_time_millis();
	game->game_time.frame_time = (game->game_time.time
			- game->game_time.old_time) / 1000.0;
}
