NAME = philo

SRC_PATH 	= src/
SRC_OBJ		= objs/
SRC_HEADER	= includes/

HEADER	= philosophers.h
SRC = main.c parse.c philo.c table.c time_utils.c
CFLAGS	= -Wall -Wextra -Werror -g3
OPTIONS	= -I$(SRC_HEADER)
LIBS		= -lpthread

SRCS = $(addprefix $(SRC_PATH),$SRC)
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(SRC_OBJ),$(OBJ))
HEADERS = $(addprefix $(SRC_HEADER),$(HEADER))

CC = gcc
RM = rm -rf

$(SRC_OBJ)%.o: $(SRC_PATH)%.c $(HEADERS)
	mkdir -p $(SRC_OBJ)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LIBS) $(CFLAGS) $(OPTIONS) -o $(@) $(^)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(SRC_OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
