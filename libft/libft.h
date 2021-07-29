/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sochoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:56:34 by sochoi            #+#    #+#             */
/*   Updated: 2020/10/10 02:47:25 by sochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int         	ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_isdigit(int c);
char			*ft_strdup(const char *s1);
int             ft_isblank(int c);
int             ft_iscomma(int c);
void	        ft_bzero(void *s, unsigned int n);
#endif