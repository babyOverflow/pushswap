NAME = libft.a

FTDIR = ./libft
SRC_DIR = src
BSRC_DIR = bsrc
OBJ_DIR = obj

SOURCES = ft_printf.c ft_vdprintf.c ft_uitoa_base.c ft_ultoa_base.c \
		  ft_print_format.c ft_print_format_decimal.c ft_print_format_hex.c\
		  ft_print_format_string.c ft_print_format_char.c \
		  t_format_create.c t_format_set_arg.c arg_to_string.c

BONUS_SOURCES = ft_printf_bonus.c ft_vdprintf_bonus.c ft_uitoa_base_bonus.c ft_ultoa_base_bonus.c \
		  ft_print_format_bonus.c ft_print_format_decimal_bonus.c ft_print_format_hex_bonus.c\
		  ft_print_format_string_bonus.c ft_print_format_char_bonus.c \
		  t_format_create_bonus.c t_format_set_arg_bonus.c arg_to_string_bonus.c

SRCS = $(patsubst %,$(SRC_DIR)/%,$(SOURCES))
BONUS_SRCS = $(patsubst %,$(BSRC_DIR)/%,$(BONUS_SOURCES))

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
BONUS_OBJS = $(patsubst $(BSRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRCS))

STRICT = -Wall -Wextra -Werror
CC = clang

# all: $(NAME)
all: bonus

bonus: $(BONUS_OBJS)
	cd $(FTDIR) && make
	cp $(FTDIR)/libft.a ./$(NAME)
	ar rsc $(NAME) $(BONUS_OBJS)

$(NAME): $(OBJS) 
	cd $(FTDIR) && make
	cp $(FTDIR)/libft.a ./$(NAME)
	ar rsc $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(STRICT) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(STRICT) $(CFLAGS) -c $< -o $@

re: fclean
	make all

clean:
	cd libft && make fclean
	rm -f $(OBJS) $(BONUS_OBJS) libft.a

fclean: clean
	rm -f  $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

test: test.c $(OBJS) $(NAME)
	$(CC) test.c  -L./ -lftprintf $(CFLAGS) -g3
	./a.out

testb: test.c $(BONUS_OBJS) bonus
	$(CC) test.c  -L./ -lftprintf  $(CFLAGS) -g3
	./a.out