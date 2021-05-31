/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:07:11 by lzins             #+#    #+#             */
/*   Updated: 2020/12/08 10:22:48 by lzins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*new_digit(unsigned int i)
{
	unsigned int *iptr;

	if (!(iptr = malloc(sizeof(unsigned int))))
		return (NULL);
	*iptr = i;
	return (ft_lstnew(iptr));
}

t_list	*itolst(t_uint128 i)
{
	t_list *res;
	t_list *new_elem;

	res = NULL;
	while (i)
	{
		if (!(new_elem = new_digit(i % 10)))
		{
			ft_lstclear(res, &free);
			return (NULL);
		}
		ft_lstadd_front(&res, new_elem);
		i /= 10;
	}
	return (res);
}

int		mult(t_list *ilst, unsigned int b)
{
	unsigned int	val;
	unsigned int	res;
	unsigned int	rem;

	rem = 0;
	while (ilst)
	{
		val = *((unsigned int*)(ilst->content));
		res = val * b + rem;
		rem = res / 10;
		*((unsigned int*)(ilst->content)) = res % 10;
		if (!ilst->next && rem > 0)
			if (!(ilst->next = new_digit(0)))
				return (-1);
		ilst = ilst->next;
	}
	return (0);
}

int		*div2(t_list *fract_lst, size_t len, size_t *nzero_len)
{
	unsigned int	res;
	unsigned int	rem;
	unsigned int	val;
	t_list			*ilst;
	t_list			*new_elem;

	*nzero_len = 0;
	rem = 0;
	while (len != 0)
	{
		val = *((unsigned int*)(fract_lst->content));
		res = val / 2 + rem;
		*((unsigned int*)(fract_lst->content)) = res;
		if (res > 0 && *nzero_len == 0)
			*nzero_len = len;
		rem = 5 * (val % 2);
		if (!fract_lst->next && rem > 0)
			if (!(fract_lst->next = new_digit(0)))
				return (-1);
		len--;
	}
	return (0);
}

t_list	*pow2(uint32_t pow2)
{
	t_list *res;

	if (!(res = new_digit(1)))
		return (NULL);
	while (pow2 != 0)
	{
		if (mult(res, 2) == -1)
		{
			ft_lstclear(res, &free);
			return (NULL);
		}
		pow2--;
	}
	return (res);
}

t_list	*deci_part(t_uint128 mant_frac, uint32_t neg_exp, size_t len)
{
	t_list *frac_lst;
	t_list *res;
	size_t nzero_len;

	if (!(frac_lst = new_digit(1)))
		return (NULL);
	while (neg_exp != 0)
	{
		if (div2(frac_lst, len + 1, &nzero_len) == -1)
		{
			ft_lstclear(frac_lst, &free);
			return (NULL);
		}
		if (nzero_len == 0)
			break ;
		neg_exp--;
	}
	res = frac_lst->next;
	ft_lstdelone(frac_lst, &free);
	return (res);
}

void	f_conv(long double d)
{
	t_fparts	d_parts;
	t_uint128	int_part;
	t_list		*pow2_part;
	t_list		*frac_lst;

	d_parts = decompose(d);
	if (d_parts.exp >= 0)
	{
		if (d_parts.exp )
			int_part = d_parts.mantissa >> d_parts.mantissa_size - 1;
		if (d_parts.exp > 0)
		{
			if (!(pow2_part = pow2(d_parts.exp)))
				return ;
			mult(ptwo)
		}
	}
	if (d_parts.exp < d_parts.mantissa_size)
	{
		// DECIMAL
	}	
}