/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:14:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/29 13:02:52 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_hook(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == EXIT)
		close_game(game);
	move_player(game, keycode);
	return (0);
}
