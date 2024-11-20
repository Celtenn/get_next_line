/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:39:09 by idkahram          #+#    #+#             */
/*   Updated: 2024/11/20 14:56:33 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(const char *str, const char *nbr);
char	*get_next_line(int fd);

#endif