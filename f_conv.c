/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:40:22 by lzins             #+#    #+#             */
/*   Updated: 2020/12/08 09:53:00 by lzins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		get_sign(long double d, t_fparts *res)
{
	if (d > 0.)
	{
		res->sign = 0;
		return (d);
	}
	else
	{
		res->sign = 1;
		return (-d);
	}
}

long double		get_exp(long double d, t_fparts *res)
{
	uint32_t exp;

	res->exp = 0;
	if (d >= 2.)
		while (d >= 2.)
		{
			d /= 2.;
			res->exp++;
		}
	else if (d < 1.)
		while (d < 2.)
		{
			d *= 2.;
			res->exp--;
		}
	return (d);
}

void			get_mantissa(long double d, t_fparts *res)
{
	t_uint128		mantissa;
	unsigned int	pos_part;

	res->mantissa = 0;
	res->mantissa_size = 0;
	while (d)
	{
		pos_part = (unsigned int)d;
		res->mantissa = res->mantissa << 1 + pos_part;
		res->mantissa_size++;
		d = (d - pos_part) * 2.;
	}
}

t_fparts	decompose(long double d)
{
	t_fparts res;

	d = get_sign(d, &res);
	d = get_exp(d, &res);
	get_mantissa(d, &res);
	return (res);
}