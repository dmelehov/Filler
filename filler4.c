/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:37:06 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/20 13:10:54 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	ft_write_ans(t_info *info, t_token *token, int i, int j)
{
	token->d = ((info->wm)[i][j]);
	token->x = i;
	token->y = j;
}

int		find_nb(t_info *info, int m)
{
	int i;
	int j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if ((info->wm)[i][j] == m)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_o_is_free(t_info *info, int i, int j)
{
	if (((j + 1) < info->width && (j - 1 >= 0) &&
		(i + 1) < info->height && (i - 1 >= 0)) &&
		((info->m)[i][j + 1] == 'O' || (info->m)[i][j + 1] == 'X') &&
		((info->m)[i][j - 1] == 'O' || (info->m)[i][j - 1] == 'X') &&
		((info->m)[i + 1][j] == 'O' || (info->m)[i + 1][j] == 'X') &&
		((info->m)[i - 1][j] == 'O' || (info->m)[i - 1][j] == 'X') &&
		((info->m)[i - 1][j - 1] == 'O' || (info->m)[i - 1][j - 1] == 'X') &&
		((info->m)[i + 1][j - 1] == 'O' || (info->m)[i + 1][j - 1] == 'X') &&
		((info->m)[i - 1][j + 1] == 'O' || (info->m)[i - 1][j + 1] == 'X') &&
		((info->m)[i + 1][j + 1] == 'O' || (info->m)[i + 1][j + 1] == 'X'))
		return (0);
	return (1);
}

int		cmp_el(t_info *info, int *k, char s1, char s2)
{
	if (s1 == '.' && (s2 == '.' || s2 == info->let || s2 == info->oplet))
		return (1);
	else if (s1 == '*' && s2 == '.')
		return (1);
	else if (s1 == '*' && s2 == info->let)
	{
		(*k)++;
		return (1);
	}
	else if ((s1 == '*' && s2 == info->oplet) || (*k) > 1)
		return (0);
	return (0);
}
