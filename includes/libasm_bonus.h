/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <akovalyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:51:28 by akovalyo          #+#    #+#             */
/*   Updated: 2020/08/03 09:31:31 by akovalyo         ###   ########.fr       */
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

size_t	                ft_strlen(const char *s);
int		                ft_strcmp(const char *s1, const char *s2);
char	                *ft_strcpy(char *dest, const char *src);
ssize_t	                ft_write(int fd, const void *buf, size_t count);
ssize_t                 ft_read(int fd, void *buf, size_t count);
char	                *ft_strdup(const char *s);
int                     ft_atoi_base(char *str, char *base);
void                    ft_list_push_front(t_list **begin_list, void *data);

typedef struct          s_list
{
    void                *data;
    struct s_list       *next;
}                       t_list;

#endif