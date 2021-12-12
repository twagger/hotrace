/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:38:15 by twagner           #+#    #+#             */
/*   Updated: 2021/12/12 15:20:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	hr_hash(char *key)
{
	unsigned long	h;
	unsigned long	high;

	h = 0;
	while (*key)
	{
		h = (h << 4) + *key++;
		high = h & 0xF0000000;
		if (high)
			h ^= high >> 24;
		h &= ~high;
	}
	return ((int)(h % TABLE_SIZE));
}

int	hr_populate(t_key_value **hashtable, int (*hasher)(char *))
{
	int			ret;
	int			num_line;
	char		*line;
	char		*first_line;

	line = NULL;
	num_line = 1;
	ret = ft_get_next_line(0, &line, 0);
	while (ret > 0)
	{
		if (num_line % 2 && line[0] == 0)
			break ;
		if (num_line % 2)
			first_line = line;
		else if (hr_add_tbl_item(first_line, line, hashtable, hasher) == ERROR)
			return (ERROR);
		line = NULL;
		ret = ft_get_next_line(0, &line, 0);
		++num_line;
	}
	free(line);
	if (ret == ERROR)
		ft_get_next_line(0, NULL, 1);
	return (ret);
}

int	hr_lookup(t_key_value **hashtable, int (*hasher)(char *))
{
	int			ret;
	char		*line;
	t_key_value	*result;

	line = NULL;
	ret = ft_get_next_line(0, &line, 0);
	while (ret > 0)
	{
		result = hr_get_item_by_key(line, hashtable, hasher);
		if (!result)
		{
			ft_putstr_fd(line, 1);
			ft_putstr_fd(": Not found.\n", 1);
		}
		else
			ft_putstr_nl_fd(result->value, 1);
		free(line);
		line = NULL;
		ret = ft_get_next_line(0, &line, 0);
	}
	free(line);
	if (ret == ERROR)
		ft_get_next_line(0, NULL, 1);
	return (ret);
}

int	main(int ac, char **av)
{
	int			i;
	int			error;
	t_key_value	*hashtable[TABLE_SIZE];

	(void)av;
	error = 0;
	i = -1;
	while (++i < TABLE_SIZE)
		hashtable[i] = NULL;
	if (ac != 1)
		error = 1;
	if (!error && hr_populate((t_key_value **)hashtable, &hr_hash) == ERROR)
		error = 1;
	if (!error && hr_lookup((t_key_value **)hashtable, &hr_hash) == ERROR)
		error = 1;
	hr_free_hashtable((t_key_value **)hashtable);
	if (error)
		ft_putstr_fd("Error\n", 2);
	return (error);
}
