/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:02:28 by abonnel           #+#    #+#             */
/*   Updated: 2020/12/01 17:11:51 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list			*res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (0);
	res->content = content;
	res->next = NULL;
	return (res);
}
