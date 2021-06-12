/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:22:09 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/12 12:20:24 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 명칭을 오름차순으로 정렬확인, 내림차순으로 정렬확인으로 해서 asc, desc 를 
// 쓰는 게 낫지 않나. 다시 볼 때 고쳐보자.

//스택 a가 두번째 매개변수 길이 안에서 오름차순으로 정렬되어있는지 파악하는 함수
int				sorted_check_a(t_stack **a, int len)
{
	t_stack		*index;
	int			low;
	int			i;

	index = (*a)->next;
	low = (*a)->n;
	i = 0;
	if (index == NULL)
		return (1);
	while (index != NULL && i < len)
	{
		if (low < index->n)
			low = index->n;
		else
			return (0);
		index = index->next;
		i++;
	}
	return (1);
}
// 스택 b가 비어있거나 내림차순으로 정렬되어 있으면 1을 반환하고 아니면 0을 반환하는 함수
int				sorted_check_b(t_stack **b, int len)
{
	t_stack		*index;
	int			high;
	int			i;

	index = (*b)->next;
	high = (*b)->n;
	i = 0;
	if (index == NULL)
		return (1);
	while (index != NULL && i < len)
	{
		if (high > index->n)
			high = index->n;
		else
			return (0);
		index = index->next;
		i++;
	}
	return (1);
}
