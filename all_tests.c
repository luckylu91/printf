/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:50:54 by lzins             #+#    #+#             */
/*   Updated: 2020/12/03 13:57:57 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int rp, rm;

	printf("[%%c] 0\n");
	rp = printf("\t>%c\n", 0);
	printf("printf return : %d\n", rp);
	rm = ft_printf("\t>%c\n", 0);
	printf("my return : %d\n", rm);
	printf("\n");

	printf("[0%%c] 0\n");
	rp = printf("\t>0%c\n", 0);
	printf("printf return : %d\n", rp);
	rm = ft_printf("\t>0%c\n", 0);
	printf("my return : %d\n", rm);
	printf("\n");
}
