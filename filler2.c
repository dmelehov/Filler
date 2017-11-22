/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 06:11:57 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/20 16:46:20 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	get_wm_values(t_info *info, int m, int n)
{
	int i;
	int j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if ((info->wm)[i][j] == 0 &&
				(((j + 1) < info->width && (info->wm)[i][j + 1] == m) ||
				((j - 1 >= 0) && (info->wm)[i][j - 1] == m) ||
				((i + 1) < info->height && (info->wm)[i + 1][j] == m) ||
				((i - 1) >= 0 && (info->wm)[i - 1][j] == m)))
			{
				(info->wm)[i][j] = n;
			}
			j++;
		}
		i++;
	}
	m = n;
	if (find_nb(info, m))
		get_wm_values(info, m, n + 1);
}

void	ft_get_weight_map(t_info *info, int i, int j)
{
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if ((info->m)[i][j] == info->oplet)
			{
				if (info->wm2[i][j] == 1)
					(info->wm)[i][j] = 10;
				else if (info->wm2[i][j] != 10 && info->width >= 30)
					(info->wm)[i][j] = 1;
				else
					(info->wm)[i][j] = 10;
			}
			else
				(info->wm)[i][j] = 0;
			j++;
		}
		i++;
	}
	if (find_nb(info, 1) && info->width >= 30)
		get_wm_values(info, 1, 2);
	get_wm_values(info, 10, 11);
}

void	ft_get_token(t_token *token)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	token->h = ft_atoi(&line[6]);
	token->w = ft_atoi(&line[8]);
	token->fig = malloc(sizeof(char *) * (token->h + 1));
	(token->fig)[token->h] = NULL;
	while (i < token->h)
	{
		get_next_line(0, &line);
		(token->fig)[i++] = ft_strdup(line);
	}
}

void	ft_get_map(t_info *info)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	while (i < info->height)
	{
		get_next_line(0, &line);
		ft_strcpy((info->m)[i++], &(line[4]));
	}
}

int		ft_player_move(t_info *info, t_token *token)
{
	ft_get_map(info);
	ft_get_weight_map(info, 0, 0);
	ft_get_token(token);
	token->x = 0;
	token->y = 0;
	if (ft_who_is_upper(info))
		ft_updown_search(info, token);
	else
		ft_downup_search(info, token);
	ft_dprintf(1, "%d %d\n", token->x, token->y);
	token->d = 666;
	return (1);
}
