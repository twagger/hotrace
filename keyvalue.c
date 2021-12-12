/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:38:18 by twagner           #+#    #+#             */
/*   Updated: 2021/12/12 09:58:11 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	hr_is_in_list(t_key_value *lst, char *key)
{
	while (lst)
	{
		if (!ft_strcmp(lst->key, key))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_key_value	*hr_new_keyvalue(char *key, char *value)
{
	t_key_value	*new;

	new = (t_key_value *)malloc(sizeof(*new));
	if (!new)
	{
		free(key);
		free(value);
		return (NULL);
	}
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	hr_keyvalue_add_front(t_key_value **lst, t_key_value *item)
{
	item->next = *lst;
	*lst = item;
}

void	hr_free_list(t_key_value *lst)
{
	t_key_value	*next;

	while (lst)
	{
		next = lst->next;
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = next;
	}
}
