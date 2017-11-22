/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:37:26 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/20 16:49:06 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct	s_info
{
	int			pnb;
	int			height;
	int			width;
	char		let;
	char		oplet;
	char		**m;
	int			**wm;
	int			**wm2;
}				t_info;

typedef struct	s_token
{
	int			h;
	int			w;
	int			x;
	int			y;
	int			d;
	char		**fig;
}				t_token;

void			ft_write_ans(t_info *info, t_token *token, int i, int j);
int				find_nb(t_info *info, int m);
int				ft_o_is_free(t_info *info, int i, int j);
int				cmp_el(t_info *info, int *k, char s1, char s2);
int				ft_check_fit(t_info *info, t_token *token, int x, int y);
int				ft_who_is_upper(t_info *info);
int				place_token(t_info *info, t_token *token, int i, int j);
int				ft_updown_search(t_info *info, t_token *token);
int				ft_downup_search(t_info *info, t_token *token);
void			get_wm_values(t_info *info, int m, int n);
void			ft_get_weight_map(t_info *info, int i, int j);
void			ft_get_token(t_token *token);
void			ft_get_map(t_info *info);
int				ft_player_move(t_info *info, t_token *token);
void			ft_free_token(t_token *token);
void			ft_free_arrays(t_info *info);
void			ft_init_arrays(t_info *info);
void			ft_get_player_info(t_info *info);

#endif
