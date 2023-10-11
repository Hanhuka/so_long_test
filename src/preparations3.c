/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:19:10 by ralves-g          #+#    #+#             */
/*   Updated: 2023/10/11 18:37:45 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_anim	**bckgnd(void)
{
	static t_anim	*useless_shit;

	return (&useless_shit);
}

void	opt_2(t_win *win, int s)
{
	(*window()).opt = 1;
	stackadd_back(bckgnd(), new_module(SPATH"Fundo_2048_1.xpm", win));
	stackadd_back(bckgnd(), new_module(SPATH"so_long_bckg.xpm", win));
	stackadd_back(bckgnd(), new_module(SPATH"Nyan1.xpm", win));
	stackadd_back(bckgnd(), new_module(NULL, win));
	(*sp()).background = (*bckgnd())->img.img;
}

void	init_opt3(t_win *win, int s)
{
	int		frame_n;
	char	*name;
	char	*tmp;
	char	*frame_c;

	frame_n = 1;
	while (frame_n <= FRAME_NBR)
	{
		frame_c = ft_itoa(frame_n);
		name = ft_strjoin(GIF_NAME, frame_c);
		free(frame_c);
		tmp = ft_strjoin(name, ".xpm");
		free(name);
		name = ft_strjoin(SPATH, tmp);
		free(tmp);
		// img_tmp = mlx_xpm_file_to_image((*win).mlx, name, &s, &s);
		stackadd_back(bckgnd(), new_module(name, win));
		free(name);
		frame_n++;
	}
}

void	opt_3(t_win *win, int s)
{
	(*window()).opt = 2;
	init_opt3(win, s);
	(*sp()).background = (*bckgnd())->img.img;
	(*window()).size = 16;
	(*window()).width = (*window()).px_size * (*window()).size;
	(*window()).height = (*window()).px_size * (*window()).size;
	mlx_destroy_window((*window()).mlx, (*window()).mlx_win);
	(*window()).mlx_win = mlx_new_window((*window()).mlx, (*window()).width
			+ (5 * 64), (*window()).height, "Honey Catcher");
}

void	change_bckgnd(int keycode)
{
	if ((keycode == LEFT || keycode == RIGHT) && (*window()).opt == 1)
	{
		(*bckgnd()) = (*bckgnd())->next;
		(*sp()).background = (*bckgnd())->img.img;
	}
}
