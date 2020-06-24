#include <stdio.h>
#include <inttypes.h>
#include <string.h>


size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

void	divider()
{
		printf("************************\n\n");
}

void	test_ft_strlen()
{
	printf("Test ft_strlen:\n1) \"hello\"\n");
	printf("strlen: %lu\n", strlen("hello"));
	printf("ft_strlen: %lu\n", ft_strlen("hello"));
	printf("2) \"\"\n");
	printf("strlen: %lu\n", strlen(""));
	printf("ft_strlen: %lu\n", ft_strlen(""));
	printf("3) \"\\n\"\n");
	printf("strlen: %lu\n", strlen("\n"));
	printf("ft_strlen: %lu\n", ft_strlen("\n"));
	printf("4) \"1234567890\"\n");
	printf("strlen: %lu\n", strlen("1234567890"));
	printf("ft_strlen: %lu\n", ft_strlen("1234567890"));
}

void	test_ft_strcmp()
{
	printf("Test ft_strcmp:\nstrcmp: %d\n", strcmp("hello", "hello"));
	printf("ft_strcmp: %d\n", ft_strcmp("hello", "hello"));
	printf("2) \"abc\" - \"bcd\"\n");
	printf("strcmp: %d\n", strcmp("abc", "fcd"));
	printf("ft_strcmp: %d\n", ft_strcmp("abc", "fcd"));
	printf("3) \"jbc\" - \"acd\"\n");
	printf("strcmp: %d\n", strcmp("jbc", "acd"));
	printf("ft_strcmp: %d\n", ft_strcmp("jbc", "acd"));

}

int main() 
{
	test_ft_strlen();
	divider();
	//test_ft_strcmp();
	divider();
	
	return 0;
}
