/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:34:30 by twagner           #+#    #+#             */
/*   Updated: 2021/12/12 18:00:09 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

/*
** LIBRARIES
*/

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
** GLOBAL PARAMS
*/

# define TABLE_SIZE 202393
# define BUFFER_SIZE 200

enum e_errors
{
	ERROR = -1
};

enum e_gnl
{
	LAST_LINE,
	STD_LINE
};

/*
** DATA STRUCTURES
*/

typedef struct s_key_value
{
	char				*key;
	char				*value;
	struct s_key_value	*next;
}						t_key_value;

/*
** UTILS
*/

void		ft_putstr_fd(char *s, int fd);
void		ft_putstr_nl_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_get_next_line(int fd, char **line, int to_free);
void		*ft_realloc(void *ptr, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
void		hr_display_table(t_key_value **hashtable);

/*
** KEY VALUE LINKED LIST UTILS
*/

void		hr_free_list(t_key_value *lst);
void		hr_keyvalue_add_front(t_key_value **lst, t_key_value *item);
t_key_value	*hr_new_keyvalue(char *key, char *value);
int			hr_is_in_list(t_key_value *lst, char *key);

/*
** HASHTABLE UTILS
*/

int			hr_hash(char *key);
t_key_value	**hr_create_hashtable(int size);
void		hr_free_hashtable(t_key_value **hashtable);
void		hr_insert_keyvalue(\
			t_key_value **hashtable, t_key_value *new, int (*hasher)(char *));
t_key_value	*hr_get_item_by_key(\
			char *key, t_key_value **hashtable, int (*hasher)(char *));
int			hr_add_tbl_item(char *key, char *value, \
			t_key_value **hashtable, int (*hasher)(char *));

#endif