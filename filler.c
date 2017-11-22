/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 06:09:33 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/20 13:10:34 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	ft_free_token(t_token *token)
{
	int	i;

	i = 0;
	while (i < token->h)
		ft_memdel((void *)(&((token->fig)[i++])));
	ft_memdel((void *)token->fig);
}

void	ft_free_arrays(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->height)
		ft_memdel((void *)(&((info->m)[i++])));
	i = 0;
	while (i < info->height)
		ft_memdel((void *)(&((info->wm)[i++])));
	ft_memdel((void *)info->m);
	ft_memdel((void *)info->wm);
}

void	ft_init_arrays(t_info *info)
{
	int	i;

	i = 0;
	info->m = malloc(sizeof(char *) * (info->height + 1));
	(info->m)[info->height] = NULL;
	while (i < info->height)
		(info->m)[i++] = ft_strnew(info->width + 1);
	i = 0;
	info->wm = malloc(sizeof(int *) * (info->height + 1));
	(info->wm)[info->height] = NULL;
	while (i < info->height)
		(info->wm)[i++] = malloc(sizeof(int) * (info->width + 1));
}

void	ft_get_player_info(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	info->pnb = ft_atoi(&line[10]);
	if (info->pnb == 1)
		info->let = 'O';
	else if (info->pnb == 2)
		info->let = 'X';
	if (info->let == 'O')
		info->oplet = 'X';
	else if (info->let == 'X')
		info->oplet = 'O';
	get_next_line(0, &line);
	info->height = ft_atoi(&line[8]);
	info->width = ft_atoi(&line[11]);
	ft_init_arrays(info);
}

int		main(void)
{
	char	*line;
	t_info	info;
	t_token	token;

	info = (t_info){0, 0, 0, '\0', '\0', NULL, NULL, NULL};
	token = (t_token){0, 0, 0, 0, 666, NULL};
	ft_get_player_info(&info);
	info.wm2 = info.wm;
	while (ft_player_move(&info, &token))
	{
		get_next_line(0, &line);
		info.wm2 = info.wm;
		ft_free_token(&token);
	}
	ft_free_token(&token);
	ft_free_arrays(&info);
	return (0);
}
