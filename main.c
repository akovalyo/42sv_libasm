#include <stdio.h>
#include <inttypes.h>
#include <string.h>


size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);


void	divider()
{
		printf("************************\n\n");
}

void	test_ft_strlen()
{
	printf("Test ft_strlen:\n1) \"hello\"\n");
	printf("strlen: %lu\nft_strlen:%lu\n", strlen("hello"), ft_strlen("hello"));
	printf("2) \"\"\n");
	printf("strlen: %lu\nft_strlen: %lu\n", strlen(""), ft_strlen(""));
	printf("3) \"\\n\"\n");
	printf("strlen: %lu\nft_strlen: %lu\n", strlen("\n"), ft_strlen("\n"));
	printf("4) \"1234567890\"\n");
	printf("strlen: %lu\nft_strlen: %lu\n", strlen("1234567890"), ft_strlen("1234567890"));
}

void	test_ft_strcmp()
{
	printf("Test ft_strcmp:\n1) \"hello\" - \"hello\"");
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
				
	printf("Check ft_strcpy\nTest1: src=\"abc\"\n");
	printf("strcpy:  dst=\"%s\", len=%lu\nft_strcpy: dst=\"%s\", len=%lu\n\n", strcpy(d1, "abc"), strlen(d1), ft_strcpy(d2, "abc"), strlen(d2));
	printf("Test 2: src=\"\"\nstrcpy:  dst=\"%s\", len=%lu\nft_strcpy: dst=\"%s\", len=%lu\n", strcpy(d1, ""), strlen(d1), ft_strcpy(d2, ""), strlen(d2));
	
}	

int main() 
{
	test_ft_strlen();
	divider();
	test_ft_strcmp();
	divider();
	test_ft_strcpy();	
	divider();
	return 0;
}
