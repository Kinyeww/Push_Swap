NAME = push_swap
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
AR = ar rcs $(NAME)
INC_DIR = parsing_utils
INC_ALG = algorithm_command
SRC = $(*.c parsing_utils/*.c algorithm_command/*.c)

OBJS := $(SRC:.c=.o)
CPPFLAGS = -I$(INC_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) 
			$(CC) $(CCFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o %@

clean:
	$(RM) *.o

fclean: fclean all

.PHONY: all clean fclean re