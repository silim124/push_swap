/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:45:04 by silim             #+#    #+#             */
/*   Updated: 2021/07/11 19:45:06 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (str_len < start)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (0);
	ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}
