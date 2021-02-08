/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:40:19 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/07 12:40:18 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				put_pointer_prefix(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int				put_minus(t_info, char **buf)
{
	int			len_to_add;

	len_to_add = 0;
	if ((info->type == 'i' || info->type == 'd') &&
			info->zero == 0 && info->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		len_to_add = 1;
	}
	return (len_to_add);
}

int				put_minus2(int buf_len, t_info *info, char **buf)
{
	int			len_to_add;

	len_to_add = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			len_to_add;
		}
		else if (buf_len < info->width)
			*buf[0] = '-';
	}
	return (len_to_add);
}

int				put_prec_str(unsigned long long nbr, t_info *info, char **buf)
{
	int			buf_len;
	int			ret;
	int			i;

	buf_len = ft_nbrlen(nbr, info);
	ret = (info->prec > buf_len) ? info->prec : buf_len;
	if (!(*buf = (char *)malloc(sizeof(char) * ret + 1)))
		return (0);
	i = 0;
	(*buf)[ret] = '\0';
	while (buf_len + i < ret)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && info->prec != 0)
		(*buf)[ret - i] = '0';
	while (nbr)
	{
		(*buf)[ret - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (buf_len);
}

int			print_nbr(unsigned long long nbr, t_info *info)
{
	char		*buf;
	int			ret;
	int			buf_len;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = put_prec_str(nbr, info, &buf);
	buf_len += put_minus(info, &buf);
	if (info->type == 'p')
		buf_len = put_pointer_prefix(&buf);
	ret = put_width_str(&buf, info);
	ret += put_minus2(buf_len, info, &buf);
	ft_putstr(buf);
	free(buf);
	return (ret);
}