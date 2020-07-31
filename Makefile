SYSTEM := $(shell uname)
NAME=libasm.a
FLAGS_MAC=-f macho64
FLAGS_LIN=-f elf64
DIR_MAC=mac/
DIR_LIN=linux/
CC_MAC = gcc
CC_LIN = clang
SRC=ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s
SRC_BONUS=ft_atoi_base_bonus.s


ifeq ($(SYSTEM),Darwin)
	FLAGS = $(FLAGS_MAC)
	DIR = $(DIR_MAC)
	CC = $(CC_MAC)
endif
ifeq ($(SYSTEM),Linux)
	FLAGS = $(FLAGS_LIN)
	DIR = $(DIR_LIN)
	CC = $(CC_LIN)
endif

SRCS = ${addprefix ${DIR}, ${SRC}}
SRCS_BONUS = ${addprefix ${DIR}, ${SRC_BONUS}}
OBJ = $(SRCS:%.s=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.s=%.o)

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
	$(CC) main.c -I includes/ -L. -lasm -o test
	./test

test_bonus:
	$(CC) main_bonus.c -I includes/ -L. -lasm -o test
	./test

.PHONY: clean fclean re main test bonus