/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 06:13:10 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/20 13:10:47 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		ft_check_fit(t_info *info, t_token *token, int x, int y)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < token->h && (info->m)[x + i][y + j] != '\0')
	{
		while (j < token->w && (info->m)[x + i][y + j] != '\0')
		{
			if (cmp_el(info, &k, (token->fig)[i][j], (info->m)[x + i][y + j]))
				j++;
			else if (!(cmp_el(info, &k, (token->fig)[i][j],
				(info->m)[x + i][y + j])))
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
	}
	if (k == 1)
		return (1);
	return (0);
}

int		ft_who_is_upper(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if ((info->m)[i][j] == info->let)
				return (1);
			else if ((info->m)[i][j] == info->oplet)
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

int		place_token(t_info *info, t_token *token, int i, int j)
{
	int	k;
	int l;

	k = 0;
	while (k < token->h)
	{
		l = 0;
		if (i - k < 0)
			return (1);
		while (l < token->w && (i + token->h - k) <= info->height)
		{
			if (j - l < 0)
				break ;
			if (((token->fig)[k][l] == '*')
				&& ft_check_fit(info, token, i - k, j - l)
				&& (j + token->w - l) <= info->width)
			{
				if ((info->wm)[i - k][j - l] <= token->d)
					ft_write_ans(info, token, i - k, j - l);
			}
			l++;
		}
		k++;
	}
	return (0);
}

int		ft_updown_search(t_info *info, t_token *token)
{
	int i;
	int j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if ((info->m)[i][j] == info->let && ft_o_is_free(info, i, j))
				place_token(info, token, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_downup_search(t_info *info, t_token *token)
{
	int i;
	int j;

	i = info->height - 1;
	while (i >= 0)
	{
		j = info->width - 1;
		while (j >= 0)
		{
			if ((info->m)[i][j] == info->let && ft_o_is_free(info, i, j))
				place_token(info, token, i, j);
			j--;
		}
		i--;
	}
	return (1);
}
