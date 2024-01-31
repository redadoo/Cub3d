/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:11:40 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/26 13:12:19 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLIDER_H
# define COLLIDER_H

# include "../vector/vector.h"
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_3dbox_collider
{
	t_vector3		pos;
	t_vector3		size;
}				t_3dbox_collider;

#endif