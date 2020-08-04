#include "libasm_bonus.h"

//int main(int argc, char **argv)
//{
//    printf("%d\n", ft_atoi_base(argv[1], argv[2]));
//    return (0);
//}
//

int	main()
{
	t_list node1;
	t_list node2;
	t_list *list;
	list = &node1;
	node1.data = strdup("Hello");
	node2.data = strdup("World");
	node1.next = &node2;
	node2.next = NULL;
	ft_list_push_front(&list, "test");

	while(list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
	return (0);
}
