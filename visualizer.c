/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:22:31 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/20 18:07:37 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	ft_start(char *str, int delay)
{
	if (ft_strstr(str, "got"))
	{
		usleep(delay);
		system("clear");
	}
	else if (ft_strstr(str, "fin"))
		ft_printf("%s\n", str);
}

void	ft_print_string(char *str, int delay)
{
	int	i;

	i = 0;
	ft_start(str, delay);
	if (ft_isdigit((*str)))
	{
		while (*str != '\0')
		{
			if (*str == 'O' || *str == 'o')
				ft_printf("\x1b[32m%c{eoc}", *str);
			else if (*str == 'X' || *str == 'x')
				ft_printf("\x1b[31m%c{eoc}", *str);
			else if (*str == '.' || *str == '*')
				ft_printf("%c", (*str));
			str++;
		}
		ft_printf("|\n");
	}
}

int		set_delay(char *str)
{
	int	i;
	int	res;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (50000);
		i++;
	}
	res = ft_atoi(str);
	if (res <= 0)
		return (50000);
	return (res);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		delay;

	if (argc == 2)
		delay = set_delay(argv[1]);
	else
		delay = 50000;
	while (get_next_line(0, &line))
		ft_print_string(line, delay);
	return (0);
}
