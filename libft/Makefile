NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include
OBJ_DIR = .object/

SRC = ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
	ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
	ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
	ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
	ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
	ft_printf/ft_printf.c ft_printf/ft_putnbr_base.c ft_printf/ft_utoa.c ft_printf/type_process.c ft_printf/ft_putulnbr_base.c \
	get_next_line.c get_next_line_utils.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_strlastncmp.c \
	ft_count_line_fd.c \
	ft_read_file.c \
	ft_free_strs.c \
	ft_strslen.c \
	ft_strcchr.c

HEADER = include/ft_printf.h include/get_next_line.h include/libft.h

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o: %.c $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
