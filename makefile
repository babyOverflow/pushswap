
SRC_DIR := src
OBJ_DIR := obj

SRC := deque.c

SRC := $(SRC:%.c=$(SRC_DIR)/%.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DIR_DUP = mkdir -p $(@D)
CC = clang

CFLAGS = -g

unit_test: $(OBJ)
	$(CC) $(CFLAGS) test/test_deque.c $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf a.out

fclean:
	rm -rf $(OBJ)