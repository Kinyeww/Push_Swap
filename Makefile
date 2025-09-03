NAME = push_swap.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
AR = ar rcs $(NAME)
SRC = \
	checker.c	create_nodes.c	ft_split.c	parsing.c	Push_Swap_algo2.c	push_swap_utils1.c	push_swap.c	rotate_algo.c
OBJS := $(SRC:.c=.o)
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o %@

clean:
	$(RM) *.o

fclean: fclean all

.PHONY: all clean fclean re