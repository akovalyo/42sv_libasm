NAME=libasm.a
FLAGS=-f macho64
SRC=ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s
SRC_BONUS=ft_atoi_base_bonus.s
OBJ = $(SRC:%.s=%.o)
OBJ_BONUS = $(SRC_BONUS:%.s=%.o)

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

bonus: $(OBJ) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
	ranlib $(NAME)

test: 
	gcc main.c -I. -L. -lasm -o test
	./test

test_bonus:
	gcc main_bonus.c -I. -L. -lasm -o test
	./test

.PHONY: clean fclean re main test bonus