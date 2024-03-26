/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:14:22 by evocatur          #+#    #+#             */
/*   Updated: 2024/03/26 17:13:35 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	jump(t_game *game)
{
	printf("jump");
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == EXIT)
		close_game(game);
	if (keycode == SPACE)
		jump(game);
	move_player(game, keycode);
	return (0);
}
