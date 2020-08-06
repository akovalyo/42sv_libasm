/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <akovalyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:47:30 by akovalyo          #+#    #+#             */
/*   Updated: 2020/08/05 11:10:57 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	divider()
{
		printf("************************\n\n");
}

void	test_ft_strlen()
{
	printf("TEST FT_STRLEN:\n1) \"hello\"\n");
	printf("strlen: %d\nft_strlen:%d\n", (int)strlen("hello"), (int)ft_strlen("hello"));
	printf("2) \"\"\n");
	printf("strlen: %d\nft_strlen: %d\n", (int)strlen(""), (int)ft_strlen(""));
	printf("3) \"\\n\"\n");
	printf("strlen: %d\nft_strlen: %d\n", (int)strlen("\n"), (int)ft_strlen("\n"));
	printf("4) \"1234567890\"\n");
	printf("strlen: %d\nft_strlen: %d\n", (int)strlen("1234567890"), (int)ft_strlen("1234567890"));
}

void	test_ft_strcmp()
{
	printf("TEST FT_STRCMP:\n1) \"hello\" - \"hello\"");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("hello", "hello"), ft_strcmp("hello", "hello"));
	printf("2) \"abc\" - \"bcd\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("abc", "fcd"), ft_strcmp("abc", "fcd"));
	printf("3) \"jbc\" - \"acd\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("jbc", "acd"), ft_strcmp("jbc", "acd"));
	printf("4) \"abc\" - \"abcdef\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("abc", "abcdef"), ft_strcmp("abc", "abcdef"));
	printf("5) \"abcdef\" - \"abc\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("abcdef", "abc"), ft_strcmp("abcdef", "abc"));
	printf("6) \"\" - \"\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("", ""), ft_strcmp("", ""));
	printf("7) \"a\" - \"abc\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("a", "abc"), ft_strcmp("a", "abc"));	
	printf("8) \"abc\" - \"a\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("abc", "a"), ft_strcmp("abc", "a"));
	printf("9) \"abc\" - \"\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("abc", ""), ft_strcmp("abc", ""));
	printf("10) \"A\" - \"a\"\n");
	printf("strcmp: %d\nft_strcmp: %d\n", strcmp("A", "a"), ft_strcmp("A", "a"));
	
}

void	test_ft_strcpy()
{
	char d1[50];
	char d2[50];
				
	printf("TEST FT_STRCPY\nTest1: src=\"abc\"\n");
	printf("strcpy:  dst=\"%s\", len=%d\nft_strcpy: dst=\"%s\", len=%d\n\n", strcpy(d1, "abc"), (int)strlen(d1), ft_strcpy(d2, "abc"), (int)strlen(d2));
	printf("Test 2: src=\"\"\nstrcpy:  dst=\"%s\", len=%d\nft_strcpy: dst=\"%s\", len=%d\n", strcpy(d1, ""), (int)strlen(d1), ft_strcpy(d2, ""), (int)strlen(d2));
	
}

void	test_ft_write()
{
	int a;
	int b;
	
	printf("TEST FT_WRITE.\nTest 1 - \"abc\\n\" to stdout\nft_write:\n");
	a = ft_write(1, "abc\n", 4);
	printf("N bytes: %d\n", a);

	printf("Test 2 (unopend fd):\n");
	a = ft_write(6, "abc\n", 4);
	printf("N bytes: %d\n", a);
	printf("errno: %d\n\n", errno);

	printf("write:\nTest 1:\n");
	b = write(1, "abc\n", 4);
	printf("N bytes: %d\n", b);

	printf("Test 2:\n");
	b = write(6, "abc\n", 4);
	printf("N bytes: %d\n", b);
	printf("errno: %d\n", errno);
}

void	test_ft_read()
{
	char	buff[500];
	int		a;
	int		fd;

	fd = open("linux/ft_strcpy.s", O_RDONLY);
	a = ft_read(fd, buff, 40); 
	printf("TEST FT_READ\nRead 50 bytes from ft_strcpy.s\nN bytes: %d\nREAD:\nstart[%s]end", a,  buff);
	close(fd);
	
	a = ft_read(10, buff, 500);
	printf("\n\nRead from unopen fd:\nft_read return: %d\nerrno: %d\n", a, errno);
}

void	test_ft_strdup()
{
	char *dst;
	char *dst2;

	dst = ft_strdup("hello");
	printf("Test FT_STRDUP:\n1) ft_strdup(\"hello\"):\nreturn: %s, len=%d\n\n", dst, (int)strlen(dst));
	dst2 = ft_strdup("");
	printf("2) ft_strdup:(\"\")\nreturn: %s, len=%d\n", dst2, (int)strlen(dst2));
}

int main() 
{
	test_ft_strlen();
	divider();
	test_ft_strcmp();
	divider();
	test_ft_strcpy();	
	divider();
	test_ft_write();
	divider();
	test_ft_read();
	divider();
	test_ft_strdup();
	divider();
	return 0;
}
