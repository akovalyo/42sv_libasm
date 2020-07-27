NAME=libasm.a
FLAGS=-f macho64
SRC=ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s
OBJ = $(SRC:%.s=%.o)

%.o: %.s
	nasm $(FLAGS) $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)
	
clean:
	@rm -f $(OBJ)

fclean: clean 
	@rm -f $(NAME)

re: fclean all

test: 
	gcc main.c -I. -L. -lasm -o test
	./test

.PHONY: clean fclean re main test