/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:14:22 by evocatur          #+#    #+#             */
/*   Updated: 2024/02/08 23:43:18 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == EXIT)
		close_game(game);
	move_player(game, keycode);
	return (0);
}
