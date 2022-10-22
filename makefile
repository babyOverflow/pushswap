NAME = push_swap
SRC_DIR := src
OBJ_DIR := obj
DIR_DUP = mkdir -p $(@D)
CC := clang

SRC := main.c parse.c parse_utils.c push_swap.c ps_commands.c \
	deque_int.c deque_int_const.c deque_int_mut.c\
	deque_run.c deque_run_const.c deque_run_mut.c\
	ps_merge_action_spec.c ps_merge_action_spec_bool.c \
	ps_merge_action_spec_register_pos.c \
	ps_merge_number.c ps_merge_number_get_pos.c \
	push_swap_short.c

SRC := $(SRC:%.c=$(SRC_DIR)/%.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS := ft
LIBS_TARGET := ft_printf/libft.a
INCS := src ft_printf


CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := $(addprefix -I,$(INCS))
LDFLAGS := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS := $(addprefix -l,$(LIBS))

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

# unit_test: $(OBJ)
# 	$(CC) $(CFLAGS) test/test_deque.c $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf a.out

fclean:
	rm -rf $(OBJ)

re: fclean
	make