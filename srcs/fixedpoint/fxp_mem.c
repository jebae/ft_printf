/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxp_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:54:17 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:54:28 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixedpoint.h"

void		fxp_init(t_fixedpoint *fxp)
{
	bi_init(&fxp->num);
	fxp->e = 0;
}

void		fxp_del(t_fixedpoint *fxp)
{
	bi_del(&fxp->num);
	fxp->e = 0;
}
