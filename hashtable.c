/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:56:06 by twagner           #+#    #+#             */
/*   Updated: 2021/12/12 15:08:10 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_key_value	*hr_get_item_by_key(\
	char *key, t_key_value **hashtable, int (*hasher)(char *))
{
	int			hash;
	t_key_value	*looked;

	hash = hasher(key);
	looked = hashtable[hash];
	while (looked)
	{
		if (!ft_strcmp(looked->key, key))
			return (looked);
		looked = looked->next;
	}
	return (NULL);
}

int	hr_add_tbl_item(\
	char *key, char *value, t_key_value **hashtable, int (*hasher)(char *))
{
	t_key_value	*tmp;

	tmp = hr_new_keyvalue(key, value);
	if (!tmp)
		return (ERROR);
	hr_insert_keyvalue((t_key_value **)hashtable, tmp, hasher);
	return (0);
}

void	hr_insert_keyvalue(\
	t_key_value **hashtable, t_key_value *new, int (*hasher)(char *))
{
	int	index;

	index = hasher(new->key);
	if (!hr_is_in_list(hashtable[index], new->key))
		hr_keyvalue_add_front(&hashtable[index], new);
	else
	{
		free(new->key);
		free(new->value);
		free(new);
	}
}

t_key_value	**hr_create_hashtable(int size)
{
	int			i;
	t_key_value	**hashtable;

	hashtable = (t_key_value **)malloc(sizeof(*hashtable) * size);
	if (!hashtable)
		return (NULL);
	i = -1;
	while (++i < size + 1)
		hashtable[i] = NULL;
	return (hashtable);
}

void	hr_free_hashtable(t_key_value **hashtable)
{
	int	i;

	i = -1;
	while (++i < TABLE_SIZE)
		hr_free_list(hashtable[i]);
}
