NAME = push_swap
SRC_DIR := src
OBJ_DIR := obj

SRC := main.c parse.c parse_utils.c push_swap.c ps_commands.c \
	deque/deque_int.c deque/deque_int_const.c \
	deque/deque_run.c deque/deque_run_const.c \
	ps_merge_action_spec.c ps_merge_number.c
SRC := $(SRC:%.c=$(SRC_DIR)/%.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DIR_DUP = mkdir -p $(@D)
CC = clang

CFLAGS = -L./ -lft -Isrc -g

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

# unit_test: $(OBJ)
# 	$(CC) $(CFLAGS) test/test_deque.c $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf a.out

fclean:
	rm -rf $(OBJ)