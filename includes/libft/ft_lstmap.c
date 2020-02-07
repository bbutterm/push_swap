/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:10:34 by bbutterm          #+#    #+#             */
/*   Updated: 2019/04/20 20:15:17 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;
	t_list *prev;
	t_list *head;

	prev = NULL;
	head = NULL;
	if (f)
		while (lst)
		{
			if (!(elem = f(lst)))
			{
				if (head)
					ft_lstdel(&head, &ft_del);
				return (NULL);
			}
			if (prev)
				prev->next = elem;
			else
				head = elem;
			lst = lst->next;
			prev = elem;
		}
	return (head);
}
