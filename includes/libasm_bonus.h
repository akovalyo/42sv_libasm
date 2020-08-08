/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <akovalyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:51:28 by akovalyo          #+#    #+#             */
/*   Updated: 2020/08/06 12:38:13 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
typedef struct			s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
ssize_t					ft_write(int fd, const void *buf, size_t count);
ssize_t					ft_read(int fd, void *buf, size_t count);
char					*ft_strdup(const char *s);
int						ft_atoi_base(char *str, char *base);
void					ft_list_push_front(t_list **begin_list, void *data);
int						ft_list_size(t_list *begin_list);
void					ft_list_sort(t_list **begin_list, int (*cmp)());
void					ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

#endif
