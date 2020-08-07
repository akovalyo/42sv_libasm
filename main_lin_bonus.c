/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <akovalyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:59:06 by akovalyo          #+#    #+#             */
/*   Updated: 2020/08/06 12:56:04 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

static int	convert_ch(char c, int base, int *nbr)
{
	int		c_int;
	
	if (c >= '0' && c <= '9')
		c_int = c - '0';
	else if (c >= 'A' && c <= 'F')
		c_int = c - 'A' + 10;
	else if (c >= 'a' && c <= 'f')
		c_int = c - 'a' + 10;
	else
		return (0);
	if (c_int < base)
		*nbr = *nbr * base + c_int;
	else
		return (0);
	return (1);
}

static int	ft_atoi_cut(const char *nptr)
{
	int		collector;
	int		i;

	collector = 0;
	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v' ||
			nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
        return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		collector = collector * 10 + nptr[i] - '0';
		i++;
	}
	return (collector);
}

int			ft_atoi_base_original(char *str, char *base)
{
	int	i;
	int	sign;
	int	nbr;
	int	int_base;

	int_base = ft_atoi_cut(base);
	if (!str || (int_base < 2 || int_base > 16))
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] && convert_ch(str[i], int_base, &nbr))
		i++;
	return (nbr * sign);
}

int		ft_lstsize_original(t_list *lst)
{
	int i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstprint_str(t_list *lst)
{
	int i = 1;

	while (lst != NULL && lst->data != NULL)
	{
		printf("node %d: %s\n", i, lst->data);
		lst = lst->next;
		i++;
	}
}



void	divider()
{
		printf("************************\n\n");
}

void	test_ft_atoi_base()
{
	printf("TEST FT_ATOI_BASE:\n\n1) str=\"\", base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("", "10"), ft_atoi_base("", "10"));
    printf("2) str=123, base=\"\"\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("123", ""), ft_atoi_base("123", ""));
    printf("3) str=123, base=+10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("123", "+10"), ft_atoi_base("123", "+10"));
    printf("4) str=123, base=-10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("123", "-10"), ft_atoi_base("123", "-10"));
    printf("5) str=123, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("123", "10"), ft_atoi_base("123", "10"));
    printf("6) str=-123, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("-123", "10"), ft_atoi_base("-123", "10"));
    printf("7) str=2147483647, base=10\n");
	printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("2147483647", "10"), ft_atoi_base("2147483647", "10"));
    printf("8) str=-2147483648, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("-2147483648", "10"), ft_atoi_base("-2147483648", "10"));
    printf("9) str=--123, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("--123", "10"), ft_atoi_base("--123", "10"));
    printf("10) str=+123, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("+123", "10"), ft_atoi_base("+123", "10"));
    printf("11) str=++123, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("++123", "10"), ft_atoi_base("++123", "10"));
    printf("12) str=+-123, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("+-123", "10"), ft_atoi_base("+-123", "10"));
    printf("13) str=-+123, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("-+123", "10"), ft_atoi_base("-+123", "10"));
    printf("14) str=123a, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("123a", "10"), ft_atoi_base("123a", "10"));
    printf("15) str=1a23, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("1a23", "10"), ft_atoi_base("1a23", "10"));
    printf("16) str=a, base=10\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("a", "10"), ft_atoi_base("a", "10"));
    printf("18) str=A, base=16\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("A123", "16"), ft_atoi_base("A123", "16"));
    printf("17) str=aBcDeFg, base=16\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("aBcDeFg", "16"), ft_atoi_base("aBcDeFg", "16"));
    printf("18) str=8, base=8\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("8", "8"), ft_atoi_base("8", "8"));
    printf("19) str=52, base=8\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("52", "8"), ft_atoi_base("52", "8"));
    printf("20) str=101010, base=2\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("101010", "2"), ft_atoi_base("101010", "2"));
    printf("21) str=132, base=5\n");
    printf("ft_atoi_base_original: %d\nft_atoi_base: %d\n\n", ft_atoi_base_original("132", "5"), ft_atoi_base("132", "5"));
}

void	test_ft_list_push_front()
{
	t_list *begin = NULL;
	printf("TEST FT_LIST_PUSH_FRONT & FT_LIST_SIZE:\n\n");
	printf("ft_lstsize_original: %d\n", ft_lstsize_original(begin));
	printf("ft_list_size: %d\n\n", ft_list_size(begin));
	printf("Step 1: Add 1st node to the empty list, data=\"hi\":\n...\n");
	ft_list_push_front(&begin, "hi");
	printf("list size: %d\n", ft_lstsize_original(begin));
	printf("ft_list_size: %d\nlst data:\n", ft_list_size(begin));
	ft_lstprint_str(begin);
	printf("\n\nStep 2: Add 2nd node to the list, data=\"hello\":\n...\n");
	ft_list_push_front(&begin, "hello");
	printf("list size: %d\n", ft_lstsize_original(begin));
	printf("ft_list_size: %d\nlst data:\n", ft_list_size(begin));
	ft_lstprint_str(begin);
	printf("\n\nStep 3: Add 3d node to the list, data=\"world\":\n...\n");
	ft_list_push_front(&begin, "world");
	printf("list size: %d\n", ft_lstsize_original(begin));
	printf("ft_list_size: %d\nlst data:\n", ft_list_size(begin));
	ft_lstprint_str(begin);
}

int main() 
{
	test_ft_atoi_base();
	divider();
	test_ft_list_push_front();
	divider();
}
